
def validParantheses(S: str) -> bool:
    if set(S).union({"(", ")"}) != {"(", ")"}:
        return "Invalid characters found"
    ctr = 0
    for char in S:
        if char=="(":
            ctr+=1
        elif char==")":
            ctr-=1
        if ctr<0:
            return False
    if ctr!=0:
        return False
    return True


def minParanthesesRemoval(S: str) -> int:
    ctr = 0
    ans = 0
    for char in S:
        if char=="(":
            ctr+=1
        elif char==")":
            ctr-=1
        if ctr<0:
            ans+=1
            ctr+=1
    return ans+ctr


if __name__=='__main__':
    print(minParanthesesRemoval("()())()"))
    print(minParanthesesRemoval(")("))
