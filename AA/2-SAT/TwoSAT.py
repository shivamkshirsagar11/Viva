from random import randint as ri
tf = {0:True,1:False}
class TwoSAT:
    x1 = {1:"x1",2:"x1'"}
    x2 = {1:"x2",2:"x2'"}
    rvalue = {"x1":tf[ri(0,1)],"x1'":tf[ri(0,1)],"x2":tf[ri(0,1)],"x2'":tf[ri(0,1)]}
    def __init__(self,m,n=2):
        self.m = m
        self.n = n
        self.fi = [0 for i in range(m)]
    def setFi(self):
        for i in range(self.m):
            l1 = self.x1[int(input("1 for x1 2 for x1': "))]
            l2 = self.x2[int(input("1 for x2 2 for x2': "))]
            self.fi[i] = [l1,l2]
    def FindSol(self):
        res = True
        for i in range(2*self.m*self.n):
            res = True
            for j in range(self.m):
                res = res and (self.rvalue[self.fi[j][0]] or self.rvalue[self.fi[j][1]])
                if( not res):
                    curr = self.rvalue[self.fi[j][0]]
                    if(curr):
                        self.fi[j][0] = "x1'"
                    else:
                        self.fi[j][0] = "x1"
        return res

