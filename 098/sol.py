
class Node:
    def __init__(self, char, neighbours, visited=False):
        self.char = char
        self.neighbours = neighbours
        self.visited = visited


def get_nodes(board):
    nodes = []
    n_rows, n_cols = len(board), len(board[0])
    for i in range(n_rows):
        for j in range(n_cols):
            neighbours = []
            if i==0:
                neighbours.append(board[i+1][j])
            elif i==n_rows-1:
                neighbours.append(board[i-1][j])
            elif i>0 and i<n_rows-1:
                neighbours.append(board[i-1][j])
                neighbours.append(board[i+1][j])
            if j==0:
                neighbours.append(board[i][j+1])
            elif j==n_cols-1:
                neighbours.append(board[i][j-1])
            elif j>0 and j<n_cols-1:
                neighbours.append(board[i][j-1])
                neighbours.append(board[i][j+1])
            node = Node(char=board[i][j], neighbours=neighbours, visited=False)
            nodes.append(node)
    return nodes


def exists(board, word):
    word = list(word)
    nodes = get_nodes(board)
    while word:
        found = False
        letter = word.pop(0)
        if not word:
            for node in nodes:
                if node.char == letter and node.visited == False:
                    return True
                else:
                    continue
            return False
        next_letter = word[0]
        # print(letter, next_letter)
        for node in nodes:
            if node.char == letter and next_letter in node.neighbours and node.visited == False:
                found = True
                node.visited = True
                break
            else:
                continue
        if not found:
            return False

def main():
    board = [['A','B','C','E'],
             ['S','F','C','S'],
             ['A','D','E','E']
            ]
    print(exists(board, "ABCCED"))
    print(exists(board, "SEE"))
    print(exists(board, "ABCB"))


if __name__=='__main__':
    main()
