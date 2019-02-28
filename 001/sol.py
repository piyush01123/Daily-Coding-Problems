def twoSum(nums, target):
    comps = set()
    for num in nums:
        if num in comps:
            return True
        comps.add(target-num)
    return False

if __name__=='__main__':
    nums = [2, 7, 5, 11, -7, 6, -131]
    target = 1
    print(twoSum(nums, target))
