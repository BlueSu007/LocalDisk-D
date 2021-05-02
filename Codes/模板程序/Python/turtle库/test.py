newdic={}

time=0

for i in range(7):

    s = input().split()
    time = int(s[0]) + int(s[1])
    i+=1
    updatedic={i:time}
    newdic.update(updatedic)

sortedlist=sorted(newdic.items(),key=lambda x:x[1],reverse=True)
if(sortedlist[0][1]>8):
    print(sortedlist[0][0])
else:print(0)