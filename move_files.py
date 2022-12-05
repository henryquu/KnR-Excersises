import os
from pathlib import Path

chapter = "4"


moving_to = f"C:/Users/ganja/OneDrive/Pulpit/The_C_Programming_Language/chapter_{chapter}/"
dir_name = "C:/Users/ganja/OneDrive/Pulpit/The_C_Programming_Language"
test = os.listdir(dir_name)

for item in test:
    if item.startswith(chapter) and item.endswith(".c") and not item.startswith('t'):
        Path(dir_name + "/" + item).rename(moving_to + item)