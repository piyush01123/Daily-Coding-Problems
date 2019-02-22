
This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:
```
    a
   / \
  b   c
 / \  /
d   e f
```
should become:
```
  a
 / \
 c  b
 \  / \
  f e  d
```

Our solution is able to achieve this:
```
______57______
/             \
__16__          __72__
/     \         /     \
16      20      69      90
/         \             /  
7          52          76     



______57______
/             \
__72__          __16__
/     \         /     \
90      69      20      16
\             /         \
76          52           7 
```
