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
    print()
    for idx, line in enumerate(lines):
        print(str(idx) + "\t"+line[:-1])
    head_idx = 0
except:
    print("Source file NOT found !!")


for char in lines[0]:
    
    if (char == "/" or char == " "):
        head_idx += 1
    else:
        break

file_name = lines[0][head_idx:].replace(" ", "_")
file_name = file_name.replace(":", "_")
file_name = file_name.replace("\n", "")
file_name = file_name + ".cpp"

print("\nCPE_workbech --> "+target_folder+"\n")
q = "\nSave file as <" + file_name +">?(y/n)"
a = input(q)

if(a != "n"):
    try:
        copyfile(source, os.path.join(target_folder, file_name))
        print("\nSuccessfully copied to local repository.\n")
    except:
        print("\nFile copying failed!!\n")

else:
    print("\nFile copying cancelled\n")


'''
q = "\npush to github?(y/n)"
a = input(q)

if(a != "n"):
    p1 = subprocess.Popen(["cd", "/Users/sciencethebird/Desktop/2019_CPE"], stdout=subprocess.PIPE)
    p1 = subprocess.check_output(["git", "status"])
    p1 = subprocess.check_output(["git", "status"])
    print(p1.decode()s)
'''
