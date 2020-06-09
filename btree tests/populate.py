import random
fp = open("populate.h",'w')
fnames = open("names.input",'r')
fans = open("ans.txt",'w')
courses = ['AA','BB','CC']

names = fnames.readlines()
size = len(names)
keys = [i for i in range(size)]
random.shuffle(keys)

fp.write(f'int populate_size = {size};')
fp.write(f'STUDENT sts[]={{\n')
for key,name in zip(keys,names):
    name = name.strip('\n')
    if(len(name)>15):
        continue
    grade = random.random()*10
    fp.write(f'{{{20+key}, "{name}","_{name}","{courses[key%3]}",{grade:.2f}}},\n')
    fans.write(f'{20+key}\n')
fp.write(f'\n}};')
fsearch  = open('search.txt','w')

random.shuffle(keys)
for key in keys:
    fsearch.write(f'2\n{key}\n')
fp.close()



