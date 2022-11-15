if __name__ == "__main__":
    text = input("Please enter Text: ")
    pattern = input("Enter pattern to match: ")
    m = len(text)
    n = len(pattern)
    for i in range(0,m-n+1):
        if(text[i:i+n] == pattern):
            print(f'Pattern Matched at index: {i}')