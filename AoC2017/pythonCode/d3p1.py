
data = 26



NORTH, S, W, E = (0, 1), (0, -1), (-1, 0), (1, 0) # directions
turn_right = {NORTH: E, E: S, S: W, W: NORTH} # old -> new direction

def counter(x,y,lim,matrix):
    count = 0
    if x == lim // 2 and y == lim // 2:
        return 1
    # print('xy',x,y)
    for i in range(y-1,y+2):
        # print('i',i)
        if i >= 0 and i < lim:
            for j in range(x-1,x+2):
                # print('j',j)
                if j >= 0 and j < lim:
                    if matrix[i][j] != None:
                        count += matrix[i][j]
    # print('count',count)
    # print('--')
    return count

def spiral(width, height,val):
    if width < 1 or height < 1:
        raise ValueError
    x, y = width // 2, height // 2 # start near the center
    dx, dy = NORTH # initial direction
    matrix = [[None] * width for _ in range(height)]
    count = 0
    while True:
        count += 1
        matrix[y][x] = counter(x,y,height,matrix) # visit
        if matrix[y][x] > val:
            return matrix[y][x]
        # try to turn right
        new_dx, new_dy = turn_right[dx,dy]
        new_x, new_y = x + new_dx, y + new_dy
        if (0 <= new_x < width and 0 <= new_y < height and
            matrix[new_y][new_x] is None): # can turn right
            x, y = new_x, new_y
            dx, dy = new_dx, new_dy
        else: # try to move straight
            x, y = x + dx, y + dy
            if not (0 <= x < width and 0 <= y < height):
                return matrix # nowhere to go

def find(val,mat):
    h = 0
    w = 0
    for i in range(len(mat)):
        if val in mat[i]:
            h = i
            for j in range(len(mat[i])):
                if mat[i][j] == val:
                    w = j
                    return (h,w)

if __name__ == "__main__":
    #vals = list(range(data))
    dim = data**0.5
    if dim != int(dim):
        dim = int(dim)+1
    else:
        dim=int(dim)
    # mat = spiral(dim,dim,data)
    # print(mat)
    i = 1
    while (i+1)**2 < data:
        i += 2
    print(i)
    print('done')
