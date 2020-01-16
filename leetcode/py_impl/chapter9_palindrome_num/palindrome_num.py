def palindrome_num(n):
    div = 1
    while n/div > 10:
        div*=10

    while n > 10:
        left = n//div
        right = n%10
        if left != right:
            return False
        n=(n%div//10)
        div//=100

    return True

if __name__ == "__main__":
    print(palindrome_num(1))
    print(palindrome_num(8))
    print(palindrome_num(12))
    print(palindrome_num(121))
    print(palindrome_num(31213))
