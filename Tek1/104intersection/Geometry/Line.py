from dataclasses import dataclass
from .Point import Point
from .Vector import Vector

@dataclass
class Line:
    point: Point
    vector: Vector

    def getPointAt(self, parameter: float) -> Point:
        return Point(
            self.point.x + self.vector.x * parameter,
            self.point.y + self.vector.y * parameter,
            self.point.z + self.vector.z * parameter
        )

    def __str__(self) -> None:
        return f"Line passing through the point ({self.point.x}, {self.point.y}, {self.point.z})" + \
            f" and parallel to the vector ({self.vector.x}, {self.vector.y}, {self.vector.z})"
