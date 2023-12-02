from dataclasses import dataclass

@dataclass
class Sphere:
    radius: float

    def __str__(self) -> None:
        return f"Sphere of radius {self.radius}"
