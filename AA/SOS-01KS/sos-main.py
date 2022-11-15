from Knapsack import Knapsack as ks,Subarr as sr
if __name__ == "__main__":
    items = 4
    p = w = [2,3,4,5]
    c = 10
    answer = ks(p,w,c,items)
    if c == answer[items][c]:
        sarr = sr(answer,w)
        print(f'solution is: {sarr}')
    else:
        print("No solution")
