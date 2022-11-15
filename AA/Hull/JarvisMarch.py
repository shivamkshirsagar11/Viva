from Points import Point as Points

def JarvisMarch(pset):
    temp = Points(float('inf'),0)
    l=0
    for index,i in enumerate(pset):
        if temp.x > i.x:
            l = index
    p = float('inf')
    first = True
    hull = []
    while(p != l):
        if first:
            first = False
            p = l
        hull.append(pset[p])
        q = (p+1) % len(pset)
        for index,i in enumerate(pset):
            if(pset[p].Direction(pset[q],pset[index]) < 0):
                q = index
        p = q
    return hull

if __name__ == '__main__':
    point_set = [
        # Points(0,3),
        # Points(2,2),
        # Points(1,1),
        # Points(2,1),
        # Points(3,0),
        # Points(0,0),
        # Points(3,3)
        # next point set
        # Points(0,0),
        # Points(3,1),
        # Points(4,4),
        # Points(1,2),
        # Points(5,0),
        # Points(2,2),
        # Points(-1,3)
        # next point set
        Points(0,30),
        Points(20,0),
        Points(15,25),
        Points(50,10),
        Points(55,20),
        Points(30,60),
        Points(50,40),
        Points(70,30)
        # next points this is co-linear but returns hull
        # Points(0,0),
        # Points(2,2),
        # Points(3,3)
    ]
    ans = JarvisMarch(point_set)
    print(f'Hull is: {[str(i) for i in ans]}')