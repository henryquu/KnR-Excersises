from pathlib import Path
import os

# 
def move_files(prefix: str, suffix: str, subfolder: str):
    """
    Move files with inpute prefix and sufix into subfolder

        Parameters:
            prefix (string): prefix of the file name
            suffix (string): extension of the file
            subfolder (string): name of the new folder 

        Returns: void
    """
    moving_to = Path(subfolder)
    moving_to.mkdir()

    for file in Path(".").iterdir():
        if file.name[0] == prefix and file.suffix == suffix:
            file.rename(Path(".") / moving_to / file.name)


def delete_files(suffix: str):
    """
    Removes all files suffix with given input
    
    Parameters:
        suffix (str): extension of the file

    Returns: void
    """
    path = os.path.abspath(os.getcwd())
    files = os.listdir(path)

    for file in files:
        if file.endswith(suffix):
            os.remove(os.path.join(path, file))


def create_files(prefix: str, suffix: str, number: int):
    """
    Create files suffix with given input
    
    Parameters:
        prefix (string): prefix of the file name
        suffix (str): extension of the file
        number (int): number of files to be created

    Returns: void
    """
    print(f"Creating {number} files with format {prefix}NUMBER{suffix}!\n")

    for number in range(1, number + 1):
        with open(prefix + number + suffix, "w"):
            pass


def main():
    message  = "Move files - move\n"\
            "Create files - create\n"\
            "Delete files - delete\n"

    chapter = 5
    exercises_count = 20
    match input(message):
        case "move":
            move_files(str(chapter), ".c", "chapter_" + str(chapter))
        case "create":
            create_files(str(chapter) + "-", ".c", exercises_count)
        case "delete":
            delete_files("exe")

    


if __name__ == "__main__":
  main()
