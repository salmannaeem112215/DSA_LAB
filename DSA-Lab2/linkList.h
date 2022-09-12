#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
#include"Node.h"
using namespace std;

class LinkList {
    public: 
       Node* head;
       Node* tail;
     
     LinkList(){
        head = NULL;
        tail = NULL;
     }

     void InsertAtStart(int val);
     void InsertAtEnd(int val);
     void update(int val_to_update,int val_after_update);
     void display();
     void search(int val);
     void insertAfter(int val,int val_to_insert_after);
     void sort_ascending();
     void sort_dscending();
    
};

void LinkList::InsertAtStart(int val){
    Node* myNode = new Node(val);
    if(head==NULL){
        head=myNode;
        tail=myNode;
    }
    else{
        myNode->next = head;
        head = myNode;
    }
}

void LinkList::InsertAtEnd(int val){

}

void LinkList::display(){
    if(head==NULL){
        cout<<"No Item in List "<<endl;
    }
    else{
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
}

#endif