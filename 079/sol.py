
def modNonDecreasing(arr: list) -> bool:
    count = 0
    for i in range(1, len(arr)):
        if arr[i]<arr[i-1]:
            count+=1
            if count>1:
                return False
    return True

print(modNonDecreasing([10, 5, 7]))
print(modNonDecreasing([10, 5, 1]))
