# -*- coding: utf-8 -*-
"""
Created on Thu Dec 30 20:59:25 2021

@author: ilkri
"""


# Creating a list of filenames
filenames = ['text1.txt', 'text2.txt', 'text3.txt', 'text4.txt', 'text5.txt', 'text6.txt', 'text7.txt', 'text8.txt', ]
  
# Open file3 in write mode
with open('TEXT_final.txt', 'w', encoding='utf-8') as outfile:
  
    # Iterate through list
    for names in filenames:
  
        # Open each file in read mode
        with open(names, encoding='utf-8') as infile:
  
            # read the data from file1 and
            # file2 and write it in file3
            outfile.write(infile.read())
  
        # Add '\n' to enter data of file2
        # from next line
        outfile.write("\n")