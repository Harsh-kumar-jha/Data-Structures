#include <iostream>
using namespace std;

// This is a Class for Doubly Linked list 
class Node{
public: 
  int data;
  Node*next;
  Node*prev;
  Node(){
    this->data = 0;
    this->next = NULL;
    this->prev = NULL;
  }
  Node(int data ){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
~Node(){
  cout<<endl;
  cout<<"Deleted"<<this->data<<endl;
}
};

// How to print a doubly linked list 
// same as singly linked list
void printDLL(Node* &head){
  Node*temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
// finding the length of DLL
int getLen(Node* &head){
  int len = 0;
  Node*temp = head;
  while(temp!=NULL){
    temp = temp->next;
    len++;
  }
  return len;
}
// inserting at the head of DLL 
void insertAtHead(Node* &head,Node* &tail,int data){
   // checking if the head is empty or not
  if(head == NULL){
    Node * newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node* newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

// inserting at the tail of a DLL
void insertAtTail(Node* &head,Node* &tail,int data){
  // checking if the head is empty or not 
  if(head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node* newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

// inserting at any position of a DLL
void insertAtPos(Node* &head, Node* &tail, int pos, int data ){
  // check is the give list is empty or not 
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // check if the position is one means head 
  if(pos == 1){
    insertAtHead(head,tail,data);
    return;
  }
  // check if the position is end 
  int len =getLen(head);
  if(pos>=len){
    insertAtTail(head,tail,data);
    return;
  }
  // now insert at middle of DLL
  int i = 1;
  Node*prevNode = head;
  if(i<pos-1){
    prevNode = prevNode->next;
    i++;
  }
  Node* curr = prevNode->next;
  Node* newNode = new Node(data);
  prevNode->next = newNode;
  newNode->prev = prevNode;
  curr->prev = newNode;
  newNode->next = curr;
}

// Delete at a give position 
void deleteANode(Node* &head,Node* &tail,int pos){
  // checking if the list is already empty 
  if(head == NULL) {
    cout<<"The list is already empty...";
    return;
  }
  // deleting the head node 
  if(pos == 1){
    Node* newNode = head;
    head = head->next;
    head->prev = NULL;
    delete newNode;
    return;
  }
  // deleting the tail node
  int len = getLen(head);
  if(pos>=len){
    Node* deleteTo = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete deleteTo;
    return;
  }
  // Deleting the middle node 
  int i = 1;
  Node*prevNode = head;
  if(i<pos-1){
    prevNode = prevNode->next;
    i++;
  }
  Node*deleteTo = prevNode->next;
  Node*nextNode = deleteTo->next;
  prevNode->next = nextNode;
  nextNode->prev = prevNode;
  delete deleteTo;
}


int main() {
  // naive way to insert data in a doubly linked list 
  Node*head = new Node(10);
  Node*first = new Node(20);
  Node*second = new Node(30);
  Node*third = new Node(40);
  Node*tail = new Node(50);

  head->next = first; //head previous will remain NULL coz it is not a circular Doubly LL

  first->prev = head;
  first->next = second;

  second->prev = first;
  second->next = third;

  third->prev = second;
  third->next = tail;

  tail->prev = third; //tail next will remain null 
  
  printDLL(head);
  
  // insertAtHead(head, tail,5);
  // cout<<endl;
  // printDLL(head);

  // cout<<endl;
  // insertAtTail(head,tail,55);
  // printDLL(head);

  cout<<endl;
  insertAtPos(head,tail,1,25);
  printDLL(head);
   cout<<endl;

  deleteANode(head, tail, 2);
  printDLL(head);

  return 0;
  
}