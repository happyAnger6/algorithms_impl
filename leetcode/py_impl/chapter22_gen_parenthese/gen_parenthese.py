def gen_parenthese(i, j, res='', out=[]):
    if i > j:
        return out

    if i == 0 and j == 0:
        out.append(res)

    if i > 0:
        gen_parenthese(i-1, j, res+'(', out)
    if j > 0:
        gen_parenthese(i, j-1, res+')', out)
    return out

if __name__ == "__main__":
    a = []
    print(gen_parenthese(3, 3, '', a))
