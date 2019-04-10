
#include <iostream>
#include <vector>

struct node{
  int data;
  node *next;
  node *random;
};

node *createNode(int data){
  node *temp = new node;
  temp->data = data;
  temp->next = NULL;
  temp->random = NULL;
  return temp;
}

void printLinkedList(node *head){
  //prints linked list
  std::cout << "PRINTING" << std::endl;
  while (head!=NULL){
    std::cout << "Data = "<< head->data << " Random = "<< head->random->data << std::endl;
    head = head->next;
  }
}

node *deepClone(node *start){
  node* curr = start, *temp;
  while (curr){
      temp = curr->next;
      curr->next = createNode(curr->data);
      curr->next->next = temp;
      curr = temp;
  }
  // start = 1->1->2->2->3->3->4->4->5->5->6->6
  // now copy the random links like 1->1->random = 1->random->next(same as random)
  curr = start;
  while (curr){
    if(curr->next) curr->next->random = curr->random?curr->random->next:\
    curr->random;
    curr = curr->next?curr->next->next:curr->next;
  }


  node *original = start;
  node *copy = start->next;
  // save the start of copied linked list
  temp = copy;
  // now separate the original list and copied list
  while (original && copy){
      original->next =
       original->next? original->next->next : original->next;
      copy->next = copy->next?copy->next->next:copy->next;
      original = original->next;
      copy = copy->next;
  }

  return temp;
}

void test(){
  std::vector<int> v {1,2,3,4,5,6};

  node *head = createNode(v[0]);
  node *curr = head;
  for (int i=1; i<v.size(); i++){
    curr->next = createNode(v[i]);
    curr = curr->next;
  }
  head->random = head->next->next; //1->3
  head->next->random = head; //2->1
  head->next->next->random = head->next->next->next; //3->4
  head->next->next->next->random = head->next; //4->2
  head->next->next->next->next->random = head->next->next->next->next->next; //5->6
  head->next->next->next->next->next->random = head->next->next->next->next; //6->5
  printLinkedList(head);

  node *head2 = deepClone(head);
  std::cout << "______________________" << '\n';
  printLinkedList(head2);
  std::cout << "______________________" << '\n';
}

int main(){
  test();
  return 0;
}
