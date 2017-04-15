def check_death(queen_positions : "2D array", position: tuple) -> bool:
    r, c = position[0], position[1]
    while r >=0 and c >= 0:
        if queen_positions[r][c] == 1:
            return True
        r -= 1
        c -= 1
    r, c = position[0], position[1]
    while r <= 8 and c >= 0:
        if queen_positions[r][c] == 1:
            return True
        r += 1
        c -= 1
    r, c = position[0], position[1]
    while r >= 0 and c <= 8:
        if queen_positions[r][c] == 1:
            return True
        r -= 1
        c += 1
    r, c = position[0], position[1]
    while r <= 8 and c <= 8:
        if queen_positions[r][c] == 1:
            return True
        r += 1
        c += 1
    r = position[0]
    for i in range(9):
        if queen_positions[r][i] == 1:
            return True
    return False

def find_all_queens(queen_positions, cur_queens, cur_column):
    global count, column
    if cur_queens == 9:
        count += 1
        return
    else:
        if cur_column == column:
            # if column == 9, then it will be case that cur_queens == 9
            # which won't happen
            cur_column += 1
        for i in range(9):
            if check_death(queen_positions, (i, cur_column)):
                continue
            else:
                queen_positions[i][cur_column] = 1
                find_all_queens(queen_positions, cur_queens + 1, cur_column + 1)
                queen_positions[i][cur_column] = 0



case = int(input())
queen_positions = [[0 for i in range(9)] for j in range(9) ]

while case:
    line = input().split()
    row, column = int(line[0]) - 1, int(line[1]) -1
    # 1-base to 0-base

    queen_positions[row][column] = 1
    count = 0
    
    cur_queens = 1
    #store current queens on the chess board

    find_all_queens(queen_positions, cur_queens, 0 if column != 0 else 1)
    
    queen_positions[row][column] = 0
    #initialize queen_positions to all zeros

    print(count)
    
    case -= 1