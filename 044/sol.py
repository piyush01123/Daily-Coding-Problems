
def mergeSort(A):
    n = len(A)
    if n<=1:
        return  A
    l = A[:n//2]
    r = A[n//2:]
    return mergeAndCount(mergeSort(l), mergeSort(r))

def mergeAndCount(l, r):
    global count
    i=0
    j=0
    sorted = []
    while i<len(l) and j<len(r):
        if l[i]<r[j]:
            sorted.append(l[i])
            i+=1
        else:
            sorted.append(r[j])
            j+=1
            count += (len(l)- i) #because all elements to the right of i in L will be inverted.
    sorted.extend(l[i:])
    sorted.extend(r[j:])
    return sorted

count = 0
A = [2, 4, 1, 3, 5]
print(mergeSort(A))
print(count)

count = 0
A = [5, 4, 3, 2, 1]
print(mergeSort(A))
print(count)
