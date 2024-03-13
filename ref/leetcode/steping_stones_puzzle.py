def find_size(stones):
    
    max_X, max_Y = -float('inf'), -float('inf')
    min_X, min_Y = float('inf'), float('inf')

    for x, y in stones:
        if x > max_X: max_X = x
        if x < min_X: min_X = x
        
        if y > max_Y: max_Y = y
        if y < min_Y: min_Y = y

    return [ min_X, max_X, min_Y, max_Y ]

def is_neighboring_sum(current, top, right, bottom, left, aj_Matrix):
    return (aj_Matrix[top[0]][top[1]] + aj_Matrix[right[0]][right[1]] + aj_Matrix[bottom[0]][bottom[1]] + aj_Matrix[left[0]][left[1]]) == current 

def first_impossible(stones):

    min_X, max_X, min_Y, max_Y = find_size(stones)

    X_size = abs(max_X - min_X)
    Y_size = abs(max_Y - min_Y)

    X_carry = abs(0 - min_X)
    Y_carry = abs(0 - min_Y)

    aj_Matrix = [[0 for _ in range(Y_size)] for _ in range(X_size)]

    for x, y in stones:
        aj_Matrix[x - X_carry][y - Y_carry] = 1

    X_val = 2
    placed = False

    def iterate_on_next(X_val):
        for x in aj_Matrix:
            for y in aj_Matrix[x]:
                res = is_neighboring_sum(X_val)

                if res:
                    aj_Matrix[x][y] = X_val
                    X_val += 1
                    return True
        
        return False

    pit = True        
    while pit:
        pit = iterate_on_next(X_val)

    return X_val


first_impossible([(0, -1), (1, 0), (-2, 5), (7, 3)])