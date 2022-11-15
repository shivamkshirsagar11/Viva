from random import randint as ri
def Randomized():
    m = [0 for i in range(ri(1,50)%20)]
    load = [ri(500,1000)%50 for i in range(ri(900,1000))]
    for i in range(len(load)):
        index_m = ri(10000,111111) % len(m)
        m[index_m] = m[index_m] + load[i]
    print(f'final distributed load on machine is: {m}')

if __name__ == "__main__":
    Randomized()