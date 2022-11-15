def partition(arr,low,high):
    pivot = high
    i = low-1
    for j in range(low,high):
        if(arr[pivot] >= arr[j]):
            i = i + 1
            arr[i], arr[j] = arr[i], arr[j]
    arr[i+1],arr[pivot] = arr[i+1], arr[pivot]
    return i + 1

def KthSmallest(arr,low,high,k):
    while(high >= low):
        part = partition(arr,low,high)
        if( k == part ):
            return arr[k]
        elif(high == low):
            return arr[low]
        elif(k < part ):
            high = part - 1
        else:
            low = part + 1
def main():
    x = [int(i) for i in input("Array: ").split(" ")]
    k = int(input("Kth element: "))
    if(k <= len(x)-1):
        print(f'{KthSmallest(x,0,len(x)-1,k-1)}')

if __name__ == "__main__":
    main()