from sys import argv, exit
from enum import Enum

class Method(Enum):
    BISECTION = 1
    NEWTON = 2
    SECANT = 3

def _printHelp() -> None:
    print("USAGE")
    print(f"    {argv[0]} opt a0 a1 a2 a3 a4 n\n")
    print("DESCRIPTION")
    print("    opt       method option:")
    print("                  1 for the bisection method")
    print("                  2 for Newton's method")
    print("                  3 for the secant method")
    print("    a[0-4]    coefficients of the equation")
    print("    n         precision (the application of the polynomial to the solution should")
    print("              be smaller than 10^-n")

def _parseMethod(arg: str) -> Method | None:
    if (arg == "1"):
        return Method.BISECTION
    if (arg == "2"):
        return Method.NEWTON
    if (arg == "3"):
        return Method.SECANT
    return None

def _parseInt(arg: str) -> int | None:
    try:
        return int(arg)
    except:
        return None

def parseArguments() -> tuple[Method, int, int, int, int, int, int]:
    if (len(argv) == 2 and argv[1] == "-h"):
        _printHelp()
        exit(0)

    if (len(argv) != 8):
        exit(84)

    if ((method := _parseMethod(argv[1])) == None):
        exit(84)
    if ((a0 := _parseInt(argv[2])) == None):
        exit(84)
    if ((a1 := _parseInt(argv[3])) == None):
        exit(84)
    if ((a2 := _parseInt(argv[4])) == None):
        exit(84)
    if ((a3 := _parseInt(argv[5])) == None):
        exit(84)
    if ((a4 := _parseInt(argv[6])) == None):
        exit(84)
    if ((precision := _parseInt(argv[7])) == None):
        exit(84)

    if (precision <= 0):
        exit(84)

    return method, a0, a1, a2, a3, a4, precision
