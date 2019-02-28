
def mergeIntervals(intervals: 'list(tuples)') -> 'list(tuples)':
    intervals = sorted(intervals, key=lambda x: x[0])
    merged = [intervals[0]]
    for i in range(1, len(intervals)):
        if intervals[i][0]<merged[-1][1]:
            last_interval = merged.pop()
            merged.append((last_interval[0], max(last_interval[1], intervals[i][1])))
        else:
            merged.append(intervals[i])
    return merged


print(mergeIntervals([(1, 3), (5, 8), (4, 10), (20, 25)]))
print(mergeIntervals([(6,8), (1,9), (2,4), (4,7)]))
