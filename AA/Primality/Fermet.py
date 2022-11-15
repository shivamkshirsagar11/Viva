class Fermet:
    from random import randint as ri
    def __init__(self,num,iter):
        self.num = num
        self.iter = iter
        self.b = bin(num-1)
    def Rand_x(self):
        return self.ri(1,(self.num)-1)
    def Mod(self):
        result = 1
        x = self.Rand_x()
        if(self.GCD(x) != 1) :return 2
        for i in self.b.split("0b")[1]:
            result = result**2 % self.num
            if(int(i) == 1):
                result = (result*x) % self.num
        return result
    def Fermet_Prime(self):
        for i in range(self.iter):
            if(self.Mod() != 1):
                return False # not prime
        return True # prime
    def GCD(self,x):
        r1 = x
        r2 = self.num
        while r2 > 0:
            q = int(r1/r2)
            r = r1 - q*r2
            r1, r2 = r2, r
        return r1

    