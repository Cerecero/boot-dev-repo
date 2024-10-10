def tsp(cities, paths, dist):
    possible_pats = permutations(cities)
    for path in possible_pats:
        sum_dist = 0
        for i in range(len(path) -1):
            sum_dist += paths[path[i]][path[+1]]
        if sum_dist < dist:
            return True
    return False

# don't touch below this line


def permutations(arr):
    res = []
    res = helper(res, arr, len(arr))
    return res


def helper(res, arr, n):
    if n == 1:
        tmp = arr.copy()
        res.append(tmp)
    else:
        for i in range(n):
            res = helper(res, arr, n - 1)
            if n % 2 == 1:
                arr[n - 1], arr[i] = arr[i], arr[n - 1]
            else:
                arr[0], arr[n - 1] = arr[n - 1], arr[0]
    return res
