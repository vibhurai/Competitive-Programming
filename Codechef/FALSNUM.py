t = int(input())
for _ in range(t) :
    a = input()
    if a[0] == '1' :
        a = '10' + a[1:]
    else :
        a = '1' + a

    print(a)