def productExceptSelf(nums):
    leftProducts = [1]
    rightProducts = [1]
    for i in range(1, len(nums)):
        leftProducts.append(nums[i-1]*leftProducts[i-1])
        rightProducts.append(nums[-i]*rightProducts[i-1])
    prods = []
    for i in range(len(nums)):
        prods.append(leftProducts[i]*rightProducts[-1-i])
    return prods
