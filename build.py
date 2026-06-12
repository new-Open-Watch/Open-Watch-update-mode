import subprocess
import os
import argparse

argumentParser = argparse.ArgumentParser()
argumentParser.add_argument("-p","--pal",action="store_true", help="sets OpenWatch port")
arguments = argumentParser.parse_args()
def updateOWGL():
    print("updating owgl")
    if not os.path.isdir("components/owgl"):
        subprocess.run(["git", "submodule", "add" ,"https://github.com/new-Open-Watch/OpenWatch-general-library.git" ,"components/owgl"])
        subprocess.run(["git","submodule", "update", " --init", "--recursive"])
    else:
        subprocess.run(["git", "submodule", "update", "--remote"])
    
updateOWGL();
subprocess.run(["idf.py", "set-target", "esp32s3"])
subprocess.run(["cmake", "build"])
if not arguments.pal:
    subprocess.run(["idf.py", "flash"])
else:
    subprocess.run(["idf.py", "build"])
