# -*- coding: utf-8 -*-
"""
Created on Tue Dec 28 23:47:18 2021

@author: ilkri
"""

import wikipediaapi
from datetime import datetime

wiki_wiki = wikipediaapi.Wikipedia(language='hr', extract_format=wikipediaapi.ExtractFormat.WIKI)

input_file = input('Koristi listu: ')
output_file = input('Zapisi u: ')
log_file = input('Log-file: ')

errArticles = []


def statistics(cnt):
    print('\nStatistika:\n')
    print(cnt, 'clanaka parsano')
    print(errArticles, 'imaju gresku')
    return 0

def downloadText():
    counter = 0
    f_read = open(input_file,'r', encoding='utf-8')
    f_write = open(output_file, 'w', encoding='utf-8')
    f_log = open(log_file, 'w', encoding='utf-8')
    
    f_log.write('[ START ] [ ' + datetime.now().strftime("%H:%M:%S") + ' ] Parsing started\n') 
    while 1:
        name = f_read.readline()
        if name == "\n":
            break
        else:
            name = name.replace('\n', '')
        
        
        try:
            page = wiki_wiki.page(name)
            f_write.write(page.text + '\n')
            counter += 1
            f_log.write('[ DONE  ] [ ' + datetime.now().strftime("%H:%M:%S") + ' ] ' + name + '\n')
            if(counter % 100 == 0): print(counter, '. članak preuzet')
            continue
        except:
            errArticles.append(name)
            f_log.write('[ ERROR ] [ ' + datetime.now().strftime("%H:%M:%S") + ' ] ' + name + '\n')
      
        
    f_log.write('[  END  ] [ ' + datetime.now().strftime("%H:%M:%S") + ' ] Parsing ended\n')
    f_write.close()
    f_read.close()
    f_log.close()
    
    statistics(counter)
    return 0

downloadText()