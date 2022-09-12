#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class LinkList
{
public:
    Node *head;
    Node *tail;

    LinkList()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtStart(int val);
    void InsertAtEnd(int val);
    void update(int val_to_update, int val_after_update);
    void display();
    void search(int val);
    void insertAfter(int val, int val_to_insert_after);
    void sort_ascending();
    void sort_dscending();
};

void LinkList::InsertAtStart(int val)
{
    Node *myNode = new Node(val);
    if (head == NULL)
    {
        head = myNode;
        tail = myNode;
    }
    else
    {
        myNode->next = head;
        head = myNode;
    }
}

void LinkList::InsertAtEnd(int val)
{
    Node *myNode = new Node(val);
    if (head == NULL)
    {
        head = myNode;
        tail = myNode;
    }
    else
    {
        tail->next = myNode;
        tail = myNode;
    }
}

void LinkList::update(int val_to_update, int val_after_update)
{
    bool found = false;
    if (head == NULL)
    {
        cout << "Linked List is Emplty" << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val_to_update)
            {
                temp->data = val_after_update;
                found =false;
            }
            temp = temp->next;
        }
        if(!found){
            cout<<"Value Not Found in Linked List "<<endl;
        }
    }
}
void LinkList::search(int val){
    if (head == NULL)
    {
        cout << "No Item in List " << endl;
    }
    else
    {
        Node *temp = head;
        int no_of_times=0;
        while (temp != NULL)
        {
           if(temp->data==val){
            no_of_times++;
           }
            temp = temp->next;
        }
        if(no_of_times){
            cout<<"Value find "<<no_of_times
                <<((no_of_times==1)?" time":"times")
                <<" in List "<<endl;
        }
        else{
            cout<<"Value not found "<<endl;
        }
    }
}

void LinkList::insertAfter(int val, int val_to_insert_after){
    if (head == NULL)
    {
        cout << "No Item in List " << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
           if(temp->data == val ){
            //creating
            Node *myNode= new Node(val_to_insert_after);
            //Inserting 
            myNode->next = temp->next;
            temp->next = myNode;
            //skipping the inserted Node
            temp=myNode;
           }
            temp = temp->next;
        }
        
    }
}

void LinkList::display()
{
    if (head == NULL)
    {
        cout << "No Item in List " << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << endl;
}

#endif