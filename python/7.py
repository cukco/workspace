a=[]
while 1>0:
    b=input()
    ds=b.split()
    b=ds[0]
    if b=="PUSH":
        c=int(ds[1])
        a.append(c)
    elif b=="POP":
        if len(a)==0:
            print("NULL")
            continue
        print(a[-1])
        a.pop()
    elif b=="#":
        print("\n")
        break