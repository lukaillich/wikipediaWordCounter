# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

input_file = 'hrwiki-20211220-all-titles'
output_file = 'list_of_all_articles.txt'

def makeList(ulaz, izlaz):
    counter = 0
    
    f_read = open(ulaz,'r', encoding='utf-8')
    f_write = open(izlaz,'w', encoding='utf-8')
    
    line = f_read.readline()
    while True:
        line = f_read.readline()
        if line.startswith("0"):
            counter += 1
            f_write.write(line.replace('0	', ''))
        else: break
        
    print(counter, "članaka pronađeno i zapisano u popis")
    
    f_read.close()
    f_write.close()
    return 0

makeList(input_file, output_file)