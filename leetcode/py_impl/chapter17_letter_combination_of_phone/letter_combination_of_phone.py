letter_phone_maps = {}

alphas = '   abcdefghijklmnopqrstuvwxyz'
for i in range(9):
    letter_phone_maps[i] = alphas[i*3:i*3+3]

def atoi(c):
    return ord(c) - ord('0')

def letter_combination_of_phone(letters, res=[], cur=''):
    if len(letters) == 0:
        res.append(cur)
        return

    for c in letter_phone_maps[atoi(letters[0])-1]:
        letter_combination_of_phone(letters[1:], res, cur+c)

if __name__ == "__main__":
    res = []
    letter_combination_of_phone('23', res, '')
    print(res)
