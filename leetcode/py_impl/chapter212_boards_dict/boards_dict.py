import random

strs='abcdefghijklmnopqrstuvwxzy'
def random_char():
    return strs[random.randrange(0,len(strs))]

def go_str(boards, i, j, st, results=set()):
    rows = len(boards)
    cols = len(boards[0])
    if i >= rows or j >= cols:
        return results
    results.add(st+boards[i][j])
    go_str(boards, i+1, j, st+boards[i][j], results)
    go_str(boards, i, j+1, st+boards[i][j])
    return results


if __name__ == "__main__":
    for _ in range(10):
        print(random_char())

    boards = ['oaan','etae','ihkr','iflv']
    print(go_str(boards, 0, 0, ''))