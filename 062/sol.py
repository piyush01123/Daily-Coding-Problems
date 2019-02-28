
def num_ways(M, N):
    if M==1 or N==1:
        return 1
    else:
        return num_ways(M,  N-1) + num_ways(M-1, N)

print(num_ways(2, 2))
print(num_ways(2, 3))
print(num_ways(5, 5))
