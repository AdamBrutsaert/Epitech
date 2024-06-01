mod help;

use std::env;
use std::str::FromStr;

fn parse_numeric_internal<T: FromStr>(str: &String, name: &'static str) -> T {
    match str.parse::<T>() {
        Ok(x) => x,
        Err(_e) => {
            eprintln!("{}: Not a number", name);
            std::process::exit(84);
        }
    }
}

fn parse_numeric<T: FromStr>(str_opt: Option<&String>, name: &'static str, default: Option<T>) -> T {
    match str_opt {
        Some(str) => parse_numeric_internal(str, name),
        None => match default {
            Some(x) => x,
            None => {
                eprintln!("{}: Argument not found", name);
                std::process::exit(84);
            }
        }
    }
}

fn parse_numeric_opt<T: FromStr>(str_opt: Option<&String>, name: &'static str) -> Option<T> {
    match str_opt {
        Some(str) => Some(parse_numeric_internal(str, name)),
        None => None
    }
}

fn log_vec<T: std::fmt::Display>(vec: &Vec<T>) {
    for (index, x) in vec.iter().enumerate() {
        println!("{index} {x:.5}");
    }
}

fn verify_arg(i: &Option<i32>) -> bool {
    i.is_none() || !(i.unwrap() < 0 || i.unwrap() > 200)
}

fn do_calculation(mu: f64, sigma: f64, x: f64) -> f64 {
    1.0f64 / (sigma * f64::sqrt(2.0f64 * std::f64::consts::PI)) * std::f64::consts::E.powf(-(((x - mu).powi(2)) / (2.0f64 * (sigma.powi(2)))))
}

fn calculate_iq(mu: f64, sigma: f64, min: &Option<i32>, max: &Option<i32>) -> Vec<f64> {
    let min = min.unwrap_or(0);
    let max = max.unwrap_or(200);

    let mut table: Vec<f64> = Vec::with_capacity(200);
    {
        let mut x = min;
        loop {
            if x > max {
                break;
            }
            table.push(do_calculation(mu, sigma, x as f64));
            x += 1;
        }
    }
    table
}

fn log_interval(mu: f64, sigma: f64, min: i32, max_opt: Option<i32>) {
    let max = max_opt.unwrap_or(min);
    let mut value: f64 = 0.0f64;
    let mut i = match max_opt {
        Some(_) => min,
        None => 0
    } as f64;

    while i < max as f64 {
        value += do_calculation(mu, sigma, i);
        i += 0.01;
    }
    if max_opt.is_some() {
        println!("{value:.1}% of people have an IQ between {min} and {max}");
    } else {
        println!("{value:.1}% of people have an IQ inferior to {min}");
    }
}

fn run_iq(args: &Vec<String>) {
    let mu: f64 = parse_numeric::<i32>(args.get(1), "u", None) as f64;
    let sigma: f64 = parse_numeric::<i32>(args.get(2), "s", None) as f64;
    let iq1: Option<i32> = parse_numeric_opt(args.get(3), "IQ1");
    let iq2: Option<i32> = parse_numeric_opt(args.get(4), "IQ2");

    if mu < 0f64 || mu > 200f64 {
       eprintln!("Invalid mu");
        std::process::exit(84);
    }
    
    if !verify_arg(&iq1) || !verify_arg(&iq2) {
        eprintln!("Bad value for IQ1 or IQ2");
        std::process::exit(84);
    }
    
    if iq1.is_some() && iq2.is_some() && iq2.unwrap() < iq1.unwrap() {
        eprintln!("Bad value for IQ2");
        std::process::exit(84);
    }

    match (iq1, iq2) {
        (None, None) => log_vec(&calculate_iq(mu, sigma, &iq1, &iq2)),
        (Some(iq1), None) => log_interval(mu, sigma, iq1, None),
        (Some(iq1), Some(_)) => log_interval(mu, sigma, iq1, iq2),
        (None, Some(_)) => unreachable!()
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let need_help: bool = args.iter().any(|arg| arg == "-h");
    if need_help {
        help::show_help(args.get(0).unwrap());
        std::process::exit(0);
    }

    match args.len() {
        ..=2 => {
           eprintln!("Not enough items!");
           std::process::exit(84);
        },
        6.. => {
            eprintln!("Too much arguments!");
            std::process::exit(84);
        },
        _ => run_iq(&args)
    }
}
