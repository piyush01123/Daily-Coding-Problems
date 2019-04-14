
import itertools

def waffleChop(R, C, H, V, waffles):
    chips = sum(sum(waffle) for waffle in waffles)
    if chips==0:
        return True
    if chips%((H+1)*(V+1))!=0:
        return False
    row_wise_chips = [sum(waffle) for waffle in waffles]
    cumm_sums_rows = [row_wise_chips[0]]
    for row in row_wise_chips[1:]:
        cumm_sums_rows.append(cumm_sums_rows[-1]+row)
    chips_per_row = chips//(H+1)
    imp_cumsums = [chips_per_row*i for i in range(1, H+1)]
    print('***************', cumm_sums_rows, imp_cumsums)
    for num in imp_cumsums:
        if num not in cumm_sums_rows:
            return False
    cut_rows = [] #cut below this
    i = 0
    for r in range(R):
        if i>=H:
            break
        if cumm_sums_rows[r]==imp_cumsums[i]:
            cut_rows.append(r)
            i+=1
    print('cut_rows', cut_rows)
    col_wise_chips = [sum(waffle[i] for waffle in waffles) for i in range(len(waffles[0]))]
    cumm_sums_cols = [col_wise_chips[0]]
    for col in col_wise_chips[1:]:
        cumm_sums_cols.append(cumm_sums_cols[-1]+col)
    chips_per_col = chips//(V+1)
    imp_cumsums = [chips_per_col*i for i in range(1, V+1)]
    for num in imp_cumsums:
        if num not in cumm_sums_cols:
            return False
    cut_cols = [] #cut below this
    i = 0
    for c in range(C):
        if i>=V:
            break
        if cumm_sums_cols[c]==imp_cumsums[i]:
            cut_cols.append(c)
            i+=1
    print('cut_cols', cut_cols)
    cut_segs = list(itertools.product(cut_rows, cut_cols))
    waffles_tab = [[0 for _ in range(C)] for _ in range(R)]
    waffles_tab[0] = [waffle[0] for waffle in waffles for i in range(len(waffles[0]))]
    return True

    # waffles_long = [waf for waffle in waffles for waf in waffle]
    # cumm_sums = [waffles_long[0]]
    # for i in range(1, len(waffles_long)):
    #     cumm_sums.append(cumm_sums[-1]+waffles_long[i])
    # print('cumm_sums', cumm_sums)
    # chips_per_seg = chips//((H+1)*(V+1))
    # imp_cumsums = [chips_per_seg*i for i in range(1, (H+1)*(V+1)+1)]
    # print('imp_cumsums', imp_cumsums)
    #
    # cut_segs = list(itertools.product(cut_rows, cut_cols))
    # imp_indices = [cut_seg[0]*C+cut_seg[1]-1 for cut_seg in cut_segs]
    # print('imp_indices', imp_indices)
    # cut_seg_chips = [cumm_sums[ind] for ind in imp_indices]
    # if cut_seg_chips!=imp_cumsums:
    #     return False
    # return True


T = int(input())
dic = {'@': 1, '.': 0}
dic2 = {True: 'POSSIBLE', False: 'IMPOSSIBLE'}
for t in range(T):
    R, C, H, V = map(int, input().split())
    waffles = []
    for _ in range(R):
        row = list(input())
        waffles.append([dic[l] for l in row])
    ans = waffleChop(R, C, H, V, waffles)
    print("Case #%s: %s" %(t+1, dic2[ans]))
