from RandomizedQS import RQS as qs
if __name__ == "__main__":
    Randomized_QuickSort = qs(input("Enter number array to sort: "))
    Randomized_QuickSort.Sort(0,len(Randomized_QuickSort.members) - 1)
    print(Randomized_QuickSort.members)