from Geometry.Point import Point
from Geometry.Line import Line

from Geometry.Sphere import Sphere
from Geometry.Cylinder import Cylinder
from Geometry.Cone import Cone

from .Infinity import Infinity
from .Equation import solveQuadraticEquation
from math import tan, radians

def _getIntersectionsQuadratic(line: Line, a: float, b: float, c: float) -> list[Point] | Infinity:
    solutions = solveQuadraticEquation(a, b, c)

    if (isinstance(solutions, Infinity)):
        return Infinity()

    return [line.getPointAt(solution) for solution in solutions]

def getLineSphereIntersections(line: Line, sphere: Sphere) -> list[Point] | Infinity:
    a = line.vector.x ** 2 + line.vector.y ** 2 + line.vector.z ** 2
    b = 2 * (line.point.x * line.vector.x + line.point.y * line.vector.y + line.point.z * line.vector.z)
    c = line.point.x ** 2 + line.point.y ** 2 + line.point.z ** 2 - sphere.radius ** 2

    return _getIntersectionsQuadratic(line, a, b, c)

def getLineCylinderIntersections(line: Line, cylinder: Cylinder) -> list[Point] | Infinity:
    a = line.vector.x ** 2 + line.vector.y ** 2
    b = 2 * (line.point.x * line.vector.x + line.point.y * line.vector.y)
    c = line.point.x ** 2 + line.point.y ** 2 - cylinder.radius ** 2

    return _getIntersectionsQuadratic(line, a, b, c)

def getLineConeIntersections(line: Line, cone: Cone) -> list[Point] | Infinity:
    v2 = tan(radians(cone.angle)) ** 2
    a = line.vector.x ** 2 + line.vector.y ** 2 - v2 * (line.vector.z ** 2)
    b = 2 * (line.point.x * line.vector.x + line.point.y * line.vector.y - v2 * line.point.z * line.vector.z)
    c = line.point.x ** 2 + line.point.y ** 2 - v2 * (line.point.z ** 2)

    return _getIntersectionsQuadratic(line, a, b, c)
