def Greedy():
    m = [0 for i in range(int(input("No of Machines: ")))]
    load = []
    for i in range(int(input("No of loads: "))):
        load.append(int(input(f'load no {i+1}: ')))
    for i in range(len(load)):
        index_m = m.index(min(m))
        m[index_m] = m[index_m] + load[i]
    print(f'Given load to machines: {m}')

if __name__ == "__main__":
    Greedy()