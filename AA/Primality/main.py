from Fermet import Fermet as fr

if __name__ == '__main__':
    x = input("Enter Number to check if prime & iteration: ")
    x = x.split()
    num = int(x[0])
    iter = int(x[1])
    Fermet_primality_testing = fr(num,iter)
    if(Fermet_primality_testing.Fermet_Prime()):
        print("Number is prime")
    else:
        print("number is not prime")