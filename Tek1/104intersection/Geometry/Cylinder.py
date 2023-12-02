from dataclasses import dataclass

@dataclass
class Cylinder:
    radius: float

    def __str__(self) -> None:
        return f"Cylinder of radius {self.radius}"
