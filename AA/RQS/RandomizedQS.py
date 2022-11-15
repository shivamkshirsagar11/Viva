from random import randint as ri
class RQS:
    def __init__(self,members):
        self.members = [int(x) for x in members.split(" ")]

    def Sort(self,low,high):
        if(high > low):
            pivot = self.getPivot(low,high)
            self.Sort(low,pivot-1)
            self.Sort(pivot+1,high)
    
    def getPivot(self,low,high):
        rand = ri(low,high)
        self.members[rand], self.members[high] = self.members[high], self.members[rand]
        pivot = high
        i = low - 1
        for j in range(low,high):
            if(self.members[pivot] >= self.members[j]):
                i = i + 1
                self.members[i], self.members[j] = self.members[j], self.members[i]
        i = i + 1
        self.members[i], self.members[pivot] = self.members[pivot], self.members[i]
        return i