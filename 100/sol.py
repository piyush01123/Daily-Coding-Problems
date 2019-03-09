
def minStepMove(positions: 'list(tuple)') -> int:
    steps = 0
    for i in range(len(positions)-1):
        start = positions[i]
        end = positions[i+1]
        x_diff = abs(end[0]-start[0])
        y_diff = abs(end[1]-start[1])
        steps += max(x_diff, y_diff)
    return steps


if __name__=='__main__':
    print(minStepMove([(0, 0), (1, 1), (1, 2)]))
