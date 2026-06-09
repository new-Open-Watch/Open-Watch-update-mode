import subprocess
import os
def updateOWGL():
    if not os.path.isdir("components/owgl"):
        subprocess.run(["git", "submodule", "add" ,"https://github.com/new-Open-Watch/OpenWatch-general-library.git" ,"components/owgl"])
        subprocess.run(["git ","submodule", "update", " --init", "--recursive"])
    else:
        subprocess.run(["git", "submodule", "update", "--remote"])
    
updateOWGL();
subprocess.run(["idf.py", "set-target", "esp32s3"])
subprocess.run(["cmake", "build"])
subprocess.run(["idf.py", "flash"])
