---
layout: post
title: "Validate Map"
categories: misc
---


This problem was asked by Uber.

A rule looks like this:
```
A NE B
```
This means this means point A is located northeast of point B.
```
A SW C
```
means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:
```
A N B
B NE C
C N A
```
does not validate, since A cannot be both north and south of C.

```
A NW B
A N B
```
is considered valid.


My Solution(Python):
```

class Map:
    def __init__(self):
        self.map = {}

    @property
    def opp_dir(self):
        return {'N': 'S', 'S': 'N', 'E': 'W', 'W': 'E'}

    def isValid(self) -> bool:
        for v in self.map:
            v_map = self.map[v]
            if not set(v_map['N']).isdisjoint(v_map['S']):
                return False
            if not set(v_map['E']).isdisjoint(v_map['W']):
                return False
        return True


def validateRules(rules: "list(str)") -> bool:
    map = Map()
    for rule in rules:
        node1, dir, node2 = rule.split()
        print("%s is to the %s of %s" %(node1, dir, node2))

        if node1 not in map.map:
            map.map[node1] = {'N': [], 'S': [], 'W': [], 'E': []}
        for d in dir:
            map.map[node1][d].append(node2)
            for node in map.map[node1][d]:
                if node in map.map:
                    map.map[node][d].append(node2)

        if node2 not in map.map:
            map.map[node2] = {'N': [], 'S': [], 'W': [], 'E': []}
        for d in dir:
            map.map[node2][map.opp_dir[d]].append(node1)
            for node in map.map[node2][map.opp_dir[d]]:
                if node in map.map:
                    map.map[node][map.opp_dir[d]].append(node1)

        if not map.isValid():
            return False

    return True


if __name__=='__main__':
    print(validateRules(["A N B", "B NE C", "C N A"]))
    print(validateRules(["A NW B", "A N B"]))
```
