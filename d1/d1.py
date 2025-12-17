zeroes = 0
dial_pos = 50
with open("puzzle_input.txt") as file:
    for line in file:
        dir = 1 if line[0] == "R" else -1
        value = int(line[1:])
        dial_pos += dir * value
        dial_pos %= 100
        if dial_pos == 0:
            zeroes+=1
            
print("Zero count: ", zeroes)