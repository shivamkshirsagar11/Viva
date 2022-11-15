class Point:
    from math import sqrt
    def __init__(self,x=-1,y=-1):
        self.x = x
        self.y = y
    def __sub__(self,other):
        return Point(self.x-other.x,self.y-other.y)
    def __eq__(self,other):
        return (self.x==other.x) and (self.y==other.y)
    def Direction(self,to1,to2):
        p1p2 = to1-self
        p1p3 = to2-self
        return ((p1p3.x*p1p2.y)-(p1p3.y*p1p2.x))
    def OnSegment(self,to1,to2):
        minX = min(self.x,to1.x)
        maxX = max(self.x,to1.x)
        maxY = max(self.y,to1.y)
        minY = min(self.y,to1.y)
        if((maxX>=to2.x>=minX) and (maxY>=to2.y>=minY)): return True
        return False
    def GeometricDist(self):
        return self.sqrt((self.x**2 + self.y**2))
    def __str__(self):
        return f'Point({self.x}, {self.y})'
