from Geometry.Solid import Solid
from Geometry.Point import Point
from Geometry.Vector import Vector

from sys import argv, exit

def _parseSolidType(arg: str) -> Solid | None:
    if (arg == "1"):
        return Solid.SPHERE
    if (arg == "2"):
        return Solid.CYLINDER
    if (arg == "3"):
        return Solid.CONE
    return None

def _parsePoint(arg1: str, arg2: str, arg3: str) -> Point | None:
    try:
        return Point(int(arg1), int(arg2), int(arg3))
    except:
        return None

def _parseVector(arg1: str, arg2: str, arg3: str) -> Vector | None:
    try:
        return Vector(int(arg1), int(arg2), int(arg3))
    except:
        return None

def _parseParameter(arg: str) -> int | None:
    try:
        return int(arg)
    except:
        return None

def _printUsage() -> None:
    print("USAGE")
    print(f"    {argv[0]} opt xp yp zp xv yv zv p\n")
    print("DESCRIPTION")
    print("    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone")
    print("    (xp, yp, zp)    coordinates of a point by which the light ray passes through")
    print("    (xv, yv, zv)    coordinates of a vector parallel to the light ray")
    print("    p               parameter: radius of the sphere, radius of the cylinder, or")
    print("                    angle formed by the cone and the Z-axis")

def parseArguments() -> tuple[Solid, Point, Vector, float]:
    if (len(argv) == 2 and argv[1] == "-h"):
        _printUsage()
        exit(0)

    if (len(argv) != 9):
        exit(84)
    if ((solidType := _parseSolidType(argv[1])) == None):
        exit(84)
    if ((point := _parsePoint(argv[2], argv[3], argv[4])) == None):
        exit(84)
    if ((vector := _parseVector(argv[5], argv[6], argv[7])) == None):
        exit(84)
    if ((param := _parseParameter(argv[8])) == None):
        exit(84)

    if (vector.x == 0 and vector.y == 0 and vector.z == 0):
        exit(84)

    if ((solidType == Solid.SPHERE or solidType == Solid.CYLINDER) and param < 0):
        exit(84)
    if (solidType == Solid.CONE and (param < 0 or param >= 90)):
        exit(84)

    return solidType, point, vector, param
