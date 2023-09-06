#Author: Matthew Barrington
#Date of creation: 4/21
#Date of last revision: 4/21
#Language: Python
#Compiler: Python3
#Program Description: This Python program reads a file called "readnum.txt" and calculates the
#                     maximum and minimum numbers in the file, then prints them to the screen.
#opens the file
file = open("readnum.txt")
#creates list of data from file
data = [int(n) for n in file.readlines()]
#print the minimum
print("min:", min(data))
#print the maximum
print("max:", max(data))
#close the file
file.close()