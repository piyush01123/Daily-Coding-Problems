
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
