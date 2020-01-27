centrals=[None, ['0', '1', '8'], ['11', '69', '88', '96']]

def central_symmetry(n, results = None):
    if results is None:
        results = []
    if n < 3:
        return centrals[n]

    for c in centrals[2]:
        for s in central_symmetry(n-2, None):
            results.append(c[0] + s + c[-1])
    return results

if __name__ == "__main__":
    print(central_symmetry(4))
    print(central_symmetry(5))
