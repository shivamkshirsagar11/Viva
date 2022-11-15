from Points import Point as Points
import math
def lowestpt(arr):
    p = Points(float('inf'),float('inf'))
    ind = None
    for index, ele in enumerate(arr):
        if((p.x >= ele.x) and (p.y >= ele.y)):
            p = ele
            ind = index
    return ind

def tangent(pi,p0):
    if(pi.x-p0.x) == 0 : return float('inf')
    ans = math.atan(((pi.y-p0.y)/(pi.x-p0.x)))*180/math.pi
    if (ans < 0):
        ans = 180+ans
    return ans

def sortP(arr,low):
    x = {x:0 for x,y in enumerate(arr)}
    rx = {i:e for i,e in enumerate(arr)}
    for i,e in enumerate(arr):
        if(i == low):
            x[i] = -math.inf
        else: x[i] = tangent(arr[i],arr[low])
    x = sorted(x.items(),key = lambda y:(y[1],y[0]))
    sortedP = []
    for i in x:
        sortedP.append(rx[i[0]])
    return sortedP

def direc(p,q,r):#s2->s1->r (r-s1) X (s1-s2)
    pq = q-p
    qr = r-p
    return((qr.x*pq.y) - (qr.y*pq.x))

def Grehams(arr):
    stack = []
    stack.append(arr[0])
    stack.append(arr[1])
    stack.append(arr[2])

    for i in range(3,len(arr)):#direc(stack[-2],stack[-1],arr[i])
        while((direc(stack[-2],stack[-1],arr[i]))>=0 and len(stack)>1):
            stack.pop()
        stack.append(arr[i])
    return stack

if __name__ == '__main__':
    point_set = [
        # next point set
        Points(0,0),
        Points(3,1),
        Points(4,4),
        Points(1,2),
        Points(5,0),
        Points(2,2),
        Points(-1,3)
        # next point set
        # Points(0,30),
        # Points(20,0),
        # Points(15,25),
        # Points(50,10),
        # Points(55,20),
        # Points(30,60),
        # Points(50,40),
        # Points(70,30)
        # next points this is co-linear but returns hull
        # Points(0,0),
        # Points(2,2),
        # Points(3,3)
    ]

    low = lowestpt(point_set)
    newarr = sortP(point_set,low)
    ch = Grehams(newarr)
    print(f'Found ch is: {[str(x) for x in ch]}')