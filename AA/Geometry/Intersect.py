from Points import Point as Points
if __name__ == "__main__":
    # p1 = Points(1,1)
    # p2 = Points(4,8)
    # p3 = Points(2,6)
    # p4 = Points(6,3)

    p1 = Points(1,1)
    p2 = Points(4,4)
    p3 = Points(2,2)
    p4 = Points(6,6)

    d1 = p1.Direction(p2,p3)
    d2 = p1.Direction(p2,p4)
    d3 = p3.Direction(p4,p1)
    d4 = p3.Direction(p4,p2)

    if((d1*d2<0) and (d3*d4<0)):
        print("points intersect")
    elif( d1==0 and p1.OnSegment(p2,p3)):print("points intersect")
    elif( d2==0 and p1.OnSegment(p2,p4)):print("points intersect")
    elif( d3==0 and p3.OnSegment(p4,p1)):print("points intersect")
    elif( d4==0 and p3.OnSegment(p4,p1)):print("points intersect")
    else:print("points does not intersect")
