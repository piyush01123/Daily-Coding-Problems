
def trapedVolume(elevations: list) -> int:
    left_max = [max(elevations[:i+1]) for i in range(len(elevations))]
    right_max = [max(elevations[-i-1:]) for i in range(len(elevations))]
    trapped = [min(l, r) - e for l, r, e in zip(left_max, right_max, \
              elevations)]
    return sum(trapped)


if __name__=='__main__':
    print(trapedVolume([2, 1, 2]))
    print(trapedVolume([3, 0, 1, 3, 0, 5]))
    print(trapedVolume([0, 0, 1, 3, 0, 5]))
