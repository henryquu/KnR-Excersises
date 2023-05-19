from pathlib import Path

chapter = "5"

moving_to = Path(f"chapter_{chapter}/")
moving_to.mkdir()

for file in Path(".").iterdir():
    if file.name[0] == chapter and file.suffix == ".c":
        file.rename(Path(".") / moving_to / file.name)
        