import os
import sys
from shutil import copyfile
import subprocess

try:
    target_folder = sys.argv[1]
except:
    print("\nError : Please Specify Destination Folder\n")
    
source = "/Users/sciencethebird/Desktop/CPE_workbench/CPE_workbench/main.cpp"
target_root = "/Users/sciencethebird/Desktop/2019_CPE"

target_folder = os.path.join(target_root, target_folder)

try:
    file = open(source, "r")
    lines = file.readlines()
    
except:
    print("Source file NOT found !!")
    
head_idx = 0
for char in lines[0]:
    
    if (char == "/" or char == " "):
        head_idx += 1
    else:
        break

file_name = lines[0][head_idx:].replace(" ", "_")
file_name = file_name.replace(":", "_")
file_name = file_name.replace("\n", "")
file_name = file_name + ".cpp"

q = "\nsave file as " + file_name +"\ncontinue?(y/n)"
a = input(q)

if(a != "n"):
    try:
        copyfile(source, os.path.join(target_folder, file_name))
        print("\nFile Successfully Transfered!!\n")
    except:
        print("\nFile Transfer Failed!!\n")

else:
    print("\nFile Transfer Cancelled\n")
    
q = "\npush to github?(y/n)"
a = input(q)

if(a != "n"):
    p1 = subprocess.Popen(["cd", "/Users/sciencethebird/Desktop/2019_CPE"], stdout=subprocess.PIPE)
    p1 = subprocess.check_output(["git", "status"])
    p1 = subprocess.check_output(["git", "status"])
    print(p1.decode())
