import os

path = os.path.abspath(os.getcwd())
files = os.listdir(path)

for file in files:
    if file.endswith(".exe"):
        os.remove(os.path.join(path, file))