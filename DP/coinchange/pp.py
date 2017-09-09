import math as m
check=0
def recursion(sum_a,lower,X,N):
    global check
    for i in range(lower,int(m.sqrt(float(X)))):
        sum_b=sum_a+i**N
        print(sum_b)
        if(sum_a<X):
            check=check+recursion(sum_b,i,X,N)
        elif(sum_a==X):
            check=check+1
        else:
            return

X = input()
N = input()
print(int(X),int(N))
print ( recursion(0,1,int(X),int(N)))
