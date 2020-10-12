for _ in range(int(input())):
    n = int(input())
    price=list(map(int,input().split()))
    res=0
    currmax=0
    for i in range(n-1,-1,-1):
        if price[i] >= currmax:
            currmax=price[i]
        res+=abs(currmax-price[i])
    print(res)
