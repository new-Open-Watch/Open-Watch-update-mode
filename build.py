import subprocess
subprocess.run(["idf.py", "set-target", "esp32s3"])
subprocess.run(["cmake", "build"])
subprocess.run(["idf.py", "flash"])