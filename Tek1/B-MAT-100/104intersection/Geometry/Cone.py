from dataclasses import dataclass

@dataclass
class Cone:
    angle: float

    def __str__(self) -> None:
        return f"Cone with a {self.angle} degree angle"
