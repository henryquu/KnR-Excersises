import os

dir_name = "C:/Users/ganja/OneDrive/Pulpit/The_C_Programming_Language"
test = os.listdir(dir_name)

for item in test:
    if item.endswith(".exe"):
        os.remove(os.path.join(dir_name, item))