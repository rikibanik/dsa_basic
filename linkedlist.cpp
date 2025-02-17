#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
void addNodeAtBeginning(Node* &head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode; 
}
void addatEnd(Node*&head, int data){
    Node* newNode = createNode(data);

    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next !=nullptr)
    {
        temp= temp->next;
    }
    temp->next = newNode;
    
}
void insertAtPosition(Node *&head, int data, int position){
    if(position==0){
        //insert at beginning
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    Node* newNode = createNode(data);
    Node* temp = head;
    for(int i=0; i<position-1 && temp!=nullptr; i++){
        temp= temp->next;
    }
    if(temp==nullptr){
        cout<< "Out of Boud";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}