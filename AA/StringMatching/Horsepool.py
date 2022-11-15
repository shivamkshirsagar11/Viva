def PreProcess(m,p):
    shift = {chr(x):m for x in range(97,97+26)}
    for i in range(0,m-1):
        shift[p[i]] = m - 1 - i
    return shift

def Horsepool(shift,t,p):
    j = 0
    m = len(p)
    n = len(t)
    while (j+m)<=n:
        if(p[m-1] == t[j+m-1]):
            i = m-2
            while(i>=0 and p[i] == t[j+i]):
                i = i-1
            if( i == -1):
                return j
        j = j + shift[t[j+m-1]]
    return -1

if __name__ == "__main__":
    text = input("Enter text: ")
    pattern = input("Enter pattern to match: ")
    shift = PreProcess(len(pattern),pattern)
    index = Horsepool(shift,text,pattern)
    print(f'Pattern Matched At index {index}')