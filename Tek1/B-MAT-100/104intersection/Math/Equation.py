from math import sqrt
from .Infinity import Infinity

# at + b = 0
def solveLinearEquation(a: float, b: float) -> list[float] | Infinity:
    if (a == 0 and b == 0):
        return Infinity()
    if (a == 0):
        return []
    return [-b / a]

# at² + bt + c = 0
def solveQuadraticEquation(a: float, b: float, c: float) -> list[float] | Infinity:
    if (a == 0):
        return solveLinearEquation(b, c)

    determinant = b ** 2 - 4 * a * c

    if (determinant > 0):
        return [(-b + sqrt(determinant)) / (2 * a), (-b - sqrt(determinant)) / (2 * a)]
    elif (determinant == 0):
        return [-b / (2 * a)]
    return []
