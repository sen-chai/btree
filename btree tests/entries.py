import random
fp = open("entries.txt",'w')
fnames = open("names.input",'r')
fsearch = open("search.txt",'w')
fans = open("ans.txt",'w')
courses = ['AA','BB','CC']
keys = [i for i in range(154)]
random.shuffle(keys)
for i in keys:
    name = fnames.readline().strip('\n')
    if(len(name)==0):
        break
    if(len(name)>15):
        continue
    grade = random.random()*10
    fp.write(f'1\n{20+i}\n{name}\n_{name}\n{courses[i%3]}\n{grade:.2f}\n')
    fans.write(f'{20+i}\n')

fp.write('0\n')

random.shuffle(keys)
for i in keys:
    fsearch.write('2\n{i+20}\n')
fsearch.write('0\n')
fp.close()
fans.close()


