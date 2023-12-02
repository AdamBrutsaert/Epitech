from dataclasses import dataclass

@dataclass
class Point:
    x: float
    y: float
    z: float

    def __str__(self) -> None:
        x = self.x
        y = self.y
        z = self.z

        if (x >= -0.0005 and x <= 0.0005):
            x = 0.0
        if (y >= -0.0005 and y <= 0.0005):
            y = 0.0
        if (z >= -0.0005 and z <= 0.0005):
            z = 0.0

        return f"({x:.3f}, {y:.3f}, {z:.3f})"
