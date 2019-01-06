#Cheat solution
def rgbArrangeCheat(rgb_list):
    rgb_hash = {_: 0 for _ in 'RGB'}
    for col in rgb_list:
        rgb_hash[col]+=1
    i=1
    while i<=rgb_hash['R']:
        rgb_list[i-1]='R'
        i+=1
    while i<=rgb_hash['R']+rgb_hash['G']:
        rgb_list[i-1]='G'
        i+=1
    while i<=rgb_hash['R']+rgb_hash['G']+rgb_hash['B']:
        rgb_list[i-1]='B'
        i+=1
    return rgb_list


def rgbArrange(rgb_list):
    """
    Motivation: https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
    We first construct an idx_array which stores the desired indexes
    """
    N = len(rgb_list)
    idx_array = [None for _ in range(N)]
    i = 0
    j = 0
    while i<N:
        if rgb_list[i] == 'R':
            idx_array[i] = j
            j+=1
        i+=1
    i = 0
    while i<N:
        if rgb_list[i] == 'G':
            idx_array[i] = j
            j+=1
        i+=1
    i = 0
    while i<N:
        if rgb_list[i] == 'B':
            idx_array[i] = j
            j+=1
        i+=1
    # # another cheat solution
    # B = [None for _ in range(N)]
    # for idx in idx_array:
    #     B[idx_array[idx]] = rgb_list[idx]
    # return B
    def reOrder(arr, index_array, n):
        for i in range(n):
            #  While index_array[i] and arr[i] are not fixed
            while index_array[i] != i:
                # Store values of the target (or correct)
                # position before placing arr[i] there
                oldTargetI = index_array[index_array[i]]
                oldTargetE = arr[index_array[i]]
                # Place arr[i] at its target (or correct)
                # position. Also copy corrected index_array for
                # new position
                arr[index_array[i]] = arr[i]
                index_array[index_array[i]] = index_array[i]
                # Copy old target values to arr[i] and
                # index_array[i]
                index_array[i] = oldTargetI
                arr[i] = oldTargetE
        return arr
    reordered_rgb_list = reOrder(rgb_list, idx_array, N)
    return reordered_rgb_list


if __name__=='__main__':
    rgb_list = ['G', 'B', 'R', 'R', 'B', 'R', 'G']
    cheat_soln = rgbArrangeCheat(rgb_list)

    rgb_list = ['G', 'B', 'R', 'R', 'B', 'R', 'G']
    real_soln = rgbArrange(rgb_list)

    print(cheat_soln, real_soln)
