#include <iostream>
using namespace std;

// How to Create a Singly linked list
class Node {
public:
  int data;
  Node *next;
  Node() {
    this->data = 0;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  ~Node(){
    cout <<endl<<"the element is deleted" << this->data <<endl;
  }
};

// Printing the data of the singly linked list
void print(Node* &head){
  Node* temp = head;
  while(temp != NULL ){
    cout<<temp->data << " ";
    temp = temp->next;
  }
}

// Inserting Data at the Head of Singly Linked List
void insertAtHead(Node *&head,Node *&tail,int data){
  // Checking is the linked List is empty or not 
  if(head == NULL){
    Node *newNode = new Node (data);
    head = newNode;
    tail = newNode;
    return;
  }
  // If not empty then this method applies
  Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

// Insert at the tail or end of a singly linked List
void insertAtTail(Node* &head,Node* &tail,int data)
{
   // Checking is the linked List is empty or not
  if(head == NULL){
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // If not empty then this method applies
  Node* newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;
}

// finding the length of  the singly linked list 
int findLen(Node* &head){
  int len = 0;
  Node *temp = head;
  while(temp!=NULL){
    temp = temp->next;
    len++;
  }
  return len;
}
// Insert at any position or middle of a singly linked list 
void insertAtPosition(int data , int position,Node* &head, Node* &tail){
  // Checking is the linked List is empty or not
  if(head == 0){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // if we want to insert at head 
  if(position == 0){
    insertAtHead(head,tail,data);
    return;
  }
  int len = findLen(head); //get he lenght of linked list 
  // if the position is greater or equal to the length of singly LL then we will insert the data at the tail of a singly linked list 
  if(position>=len){
    insertAtTail(head,tail,data);
    return;
  }
  // if we want to insert at any position of a singly linked list apply this method 
  int i = 1;
  Node* prev = head;
  while(position > i){
    prev = prev->next;
    i++;
    }
  Node* curr = prev->next;
  Node* newNode = new Node(data);
  newNode->next = curr;
  prev->next = newNode;
}

// delete a node in a singly linked list at any giver position  
void deleteANodeAtAnyPosition(int position , Node* &head , Node* &tail){
  // firstly we will check if the linked list is empty or not 
  if(head == 0 ) {
    cout<<"The Linked list is already empty";
    return;
  }
  // if we want to delete the first node of a linked list 
  if(position == 1){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
  }
  // if we wanted to delete last node of tail node of a linked list 
  int len = findLen(head);
  if(position == len ){
    int i = 1;
    Node* prevNode = head; 
    while(i<position-1){
      prevNode = prevNode->next;
      i++;
    }
    prevNode->next = NULL;
    Node* temp = tail;
    tail = prevNode;
    delete temp;
    return;
  }
  // if we want to delete a linked list in the middle or any position between right and left node
  int i = 1;
  Node* prevNode = head;
  while(i<position - 1){
    prevNode = prevNode->next;
    i++;
  }
  Node* curr = prevNode->next;
  prevNode->next = curr->next;
  curr->next = NULL;
  delete curr;
}

int main() {
  Node *head = new Node(10);
  Node *tail = new Node(50);
  Node *first = new Node(20);
  Node *second = new Node(30);
  Node *third = new Node(40);

  head->next = first;
  first->next = second;
  second->next = third;
  third->next = tail;
  insertAtHead(head,tail,5);
  insertAtTail(head,tail,55);
  
  print(head);
  // cout<<endl;
  // cout<<findLen(head)<<endl;
  insertAtPosition(45,5,head,tail);
  cout<<endl;
  print(head);
  cout<<endl;

  deleteANodeAtAnyPosition(5,head,tail);
  print(head);
}