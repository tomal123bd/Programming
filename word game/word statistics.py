#this is statistics programme to show how many words ended by a particular alphabet
dic=open('/home/tomal/Desktop/c c++ problems/word game/dic.txt').read().splitlines()
ltr={}
for i in range (1,27):
    ltr[(chr(96+i))]=0
count=1
last_char=''
for i in dic:
    last_char=i[len(i)-1].lower()
    ltr[last_char]=ltr[last_char]+1
for i in ltr:
    print (i,ltr[i])
s=sorted(ltr.items(), key=lambda x: x[1])
for i in s[::-1]:
    print (i)
