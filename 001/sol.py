def twoSum(nums, target):
    comps = set()
    for num in nums:
        if num in comps:
            return True
        comps.append(target-num)
    return False
