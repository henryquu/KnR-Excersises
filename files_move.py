import os
from pathlib import Path

chapter = "4"

path = os.path.abspath(os.getcwd())
moving_to = path + f"/chapter_{chapter}/"

files = os.listdir(path)

for file in files:
    if file.startswith(chapter) and file.endswith(".c") and file.startswith(chapter):
        Path(path + "/" + file).rename(moving_to + file)