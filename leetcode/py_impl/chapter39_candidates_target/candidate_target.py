def candidate_target(a, target, sum = 0, cur_nums = None, results=None):
    if results is None:
        results = []

    if cur_nums is None:
        cur_nums = []

    for c in a:
        if sum + c > target:
            break
        elif sum + c == target:
            cur_nums.append(c)
            results.append(cur_nums[:])
            cur_nums.pop()
            break
        else:
            cur_nums.append(c)
            candidate_target(a, target, sum+c, cur_nums, results)
            cur_nums.pop()
    return results

if __name__ == "__main__":
    print(candidate_target([1,1,2,2,4], 2))

