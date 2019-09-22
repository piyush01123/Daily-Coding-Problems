
#include <iostream>
#include <list>

// struct for a linked list node
struct ListNode{
  int data;
  ListNode *next;
};

// create a linked list pointer
ListNode *createListNode(int _data){
  ListNode *temp = new ListNode;
  temp->data = _data;
  temp->next = NULL;
  return temp;
}

// struct for a binary tree node
struct TreeNode{
  int data;
  TreeNode *left, *right;
};

// create a binary tree pointer
TreeNode *createTreeNode(int _data){
  TreeNode *temp = new TreeNode;
  temp->data = _data;
  temp->left = temp->right = NULL;
  return temp;
}

// length of binary tree
int getListLength(ListNode *head){
  int len = 0;
  while (head!=NULL){
    len++;
    head = head->next;
  }
  return len;
}

// The workhorse function
// The entire success of this function is based on that ampersand!!
TreeNode *linkedListToBSTUtil(ListNode * &head, int n){
  if (n<=0) return NULL;
  TreeNode *left = linkedListToBSTUtil(head, n/2);
  // by the time it reaches the line  below, head has moved to appropriate position
  // because we are passing head by reference
  TreeNode *root = createTreeNode(head->data);
  root->left = left;
  head = head->next;
  TreeNode *right = linkedListToBSTUtil(head, n-n/2-1);
  root->right= right;
  return root;
}

// function to convert linked list to balanced bst.
TreeNode *linkedListToBST(ListNode *head){
  int len = getListLength(head);
  TreeNode *root = linkedListToBSTUtil(head, len);
  return root;
}

// The other way is to have pointer to pointer, so it can be changed.
// TreeNode *linkedListToBSTUtil(ListNode **head_ref, int n){
//   if (n<=0) return NULL;
//   TreeNode *left = linkedListToBSTUtil(head_ref, n/2);
//   TreeNode *root = createTreeNode((*head_ref)->data);
//   root->left = left;
//   (*head_ref) = (*head_ref)->next;
//   root->right= linkedListToBSTUtil(head_ref, n-n/2-1);
//   return root;
// }
//
// TreeNode *linkedListToBST(ListNode *head){
//   int len = getListLength(head);
//   TreeNode *root = linkedListToBSTUtil(&head, len);
//   return root;
// }


// level wise traversal on binary tree by bfs.
void levelWiseTraversal(TreeNode *root){
  // BFS on tree
  if (root==NULL) return;
  std::list<TreeNode *> Q;
  Q.push_back(root);
  while (!Q.empty()){
    TreeNode *root = Q.front();
    std::cout<<root->data<<' ';
    Q.pop_front();
    if (root->left) Q.push_back(root->left);
    if (root->right) Q.push_back(root->right);
  }
  std::cout<<'\n';
}

// traverse over linked list and print
void printLinkedList(ListNode *head){
  while (head!=NULL){ std::cout<<head->data<<' '; head=head->next; }
  std::cout<<'\n';
}

// convert a std::list to linked list
ListNode *createLinkedList(std::list<int> L){
  ListNode *head = createListNode(-1);
  ListNode *curr = head;
  while (!L.empty()){
    int _data = L.front();
    curr->next = createListNode(_data);
    curr = curr->next;
    L.pop_front();
  }
  return head->next;
}

// the main
int main(){
  std::list<int>  L {1,2,3,4,5,6,7};
  ListNode *head = createLinkedList(L);
  printLinkedList(head);
  TreeNode *root = linkedListToBST(head);
  levelWiseTraversal(root);
  return 0;
}
