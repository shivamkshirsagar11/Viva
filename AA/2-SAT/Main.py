from TwoSAT import TwoSAT as ts 
if __name__ == "__main__":
    twosat = ts(int(input("Enter no of clause: ")))
    twosat.setFi()
    if(twosat.FindSol()):
        print(f'is Satisfiable (x1,x2):({twosat.rvalue[twosat.fi[0][0]]},{twosat.rvalue[twosat.fi[0][1]]})')
    else:
        print("is not Satisfiable")