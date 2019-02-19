#player has to choose a word and other player has to give a word by its last character
#this programme uses a dictionary text file to search words, dictionary named as dic.txt
import os
import time
dic=open("/home/tomal/Desktop/c c++ problems/word game/dic.txt").read().splitlines() #put dictionary file path here
player_a=""
player_b=""
print ("Input 0 to exit the game with statistics")
print ("Initial word starting from player b:")
player_b=input()
count=0
flag=0
used_words_a=[]
used_words_b=[]
last_char=player_b[len(player_b)-1]
while (True):
    os.system("clear")
    count=5
    flag=0
    start_time=time.time()
    while(True):
        print ("Input word within",60-int(time.time()-start_time),"second/s.")
        for i in used_words_a:
            if (last_char==i[0]):
                print (i)
        print ("Last char: "+last_char)
        print ("Player A: ",end='')
        if (time.time()-start_time>60):
            print ("Time over.\n","Winner B\n","\nTotal word used for A:",len(used_words_a),"\n",used_words_a,"\nTotal word used for B:",len(used_words_a),"\n",used_words_b)
            exit()
        player_a=input()
        if len(player_a)<2:
            print ("Single letter should not be used. Please try again.")
            continue
        if player_a[0]!=last_char:
            print ("Wrong starting letter. Please try again.")
            continue
        if (player_a in used_words_a):
            print ("The word have already used. Please try again.")
            continue
        if player_a not in dic:
            if count==0:
                print ("Chance over.\n","Winner B\n","\nTotal word used for A:",len(used_words_a),"\n",used_words_a,"\nTotal word used for B:",len(used_words_a),"\n",used_words_b)
                exit()
            count-=1
            print ("Not a word. Please try again. Chance left",count)
            continue
        print ("Passed")
        time.sleep(1)
        last_char=player_a[len(player_a)-1]
        used_words_a.append(player_a)
        break
    os.system("clear")
    count=5
    start_time=time.time()
    while(True):
        print ("Input word within",60-int(time.time()-start_time),"second/s.")
        for i in used_words_b:
            if (last_char==i[0]):
                print (i)
        print ("Last char: "+last_char)
        print ("Player B: ",end='')
        player_b=input()
        if (time.time()-start_time>60):
            print ("Time over.\n","Winner A\n","\nTotal word used for A:",len(used_words_a),"\n",used_words_a,"\nTotal word used for B:",len(used_words_a),"\n",used_words_b)
            exit()
        if len(player_b)<2:
            print ("Single letter should not be used. Please try again.")
            continue
        if player_b[0]!=last_char:
            print ("Wrong starting letter. Please try again.")
            continue
        if (player_b in used_words_b):
            print ("The word have already used. Please try again.")
            continue
        if player_b not in dic:
            if count==0:
                print ("Chance over.\n","Winner A\n","\nTotal word used for A:",len(used_words_a),"\n",used_words_a,"\nTotal word used for B:",len(used_words_a),"\n",used_words_b)
                exit()
            count-=1
            print ("Not a word. Please try again. Chance left",count)
            continue
        print ("Passed")
        time.sleep(1)
        last_char=player_b[len(player_b)-1]
        used_words_b.append(player_b)
        break