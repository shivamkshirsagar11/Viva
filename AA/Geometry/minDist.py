from Points import Point as Points
if __name__ == '__main__':
    p1 = Points(1,1)
    p2 = Points(4,8)
    p3 = Points(2,6)
    p4 = Points(6,3)
    pset = [p1,p2,p3,p4,Points(),Points()]
    ansD = float('inf')
    for i in range(0, len(pset)-3):
        for j in range(i+1, len(pset) - 2):
            ptemp = pset[i] - pset[j]
            t = ptemp.GeometricDist()
            if(ansD > t):
                ansD = t
                pset[-1] = pset[i]
                pset[-2] = pset[j]
    print(f'Min.Distance: {ansD}, Points:({pset[-1]}, {pset[-2]})')
                