from dataclasses import dataclass
from sys import stderr

@dataclass
class Country:
    name: str
    code: str
    populations: list[int]

def parse_int(value: str) -> int | None:
    try:
        return int(value)
    except:
        return None

def parse_country(line: int, columns: list[str]) -> Country | None:
    if (len(columns) != 60):
        print(f"[error] expected 60 columns at line {line}, got {len(columns)}", file=stderr)
        return None
    
    name = columns[0]
    code = columns[1]
    populations: list[int] = []

    for i in range(2, 60):
        population = parse_int(columns[i])

        if (population == None):
            print(f"[error] failed to parse integer at line {line} `{columns[i]}` of column {i + 1}!", file=stderr)
            continue
        
        populations.append(population)

    if (len(populations) == 0):
        return None

    return Country(name, code, populations)

def parse_csv(file: str) -> dict[str, Country] | None:
    country_by_code: dict[str, Country] = {}
    
    try:
        with open(file, "r") as f:
            for idx, line in enumerate(f.readlines()[1:]):
                country = parse_country(idx + 2, line.rstrip("\n").split(";"))
            
                if (country == None):
                    print(f"[error] failed to parse country of line {idx + 2}!", file=stderr)
                    continue

                if (country_by_code.get(country.code) != None):
                    print(f"[error] duplicate country with code `{country.code}`")
                    continue

                country_by_code[country.code] = country
    except:
        print(f"[error] failed to open file `{file}`")
        return None

    if (len(country_by_code) == 0):
        return None

    return country_by_code

