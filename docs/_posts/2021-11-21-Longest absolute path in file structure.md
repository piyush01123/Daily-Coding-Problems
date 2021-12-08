---
layout: post
title: "Longest absolute path in file structure"
categories: misc
---

This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string `"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"` represents:

```
dir
    subdir1
    subdir2
        file.ext
```
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"` represents:

```
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
```

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is `"dir/subdir2/subsubdir2/file2.ext"`, and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.


My Solution(Python):
```

def longestAbsolutePath(fs: str) -> int:
    paths = fs.split('\n')
    max_len = 0
    path_lengths = {0: 0}
    depth = 0
    for path in paths:
        name = path.strip()
        depth = len(path)-len(name)
        if '.' in name:
            max_len = max(max_len, path_lengths[depth] + len(name))
        else:
            path_lengths[depth+1] = path_lengths[depth] + len(name) + 1
    return max_len


if __name__=='__main__':
    fsys= [
    "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext", \
    "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    ]
    for fs in fsys:
        print(longestAbsolutePath(fs))
```
