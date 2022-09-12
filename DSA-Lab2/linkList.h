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

void LinkList::sort_ascending(){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
    }
    else{
        Node* outer_temp = head;
        Node* outer_temp_priv = NULL;
        Node* min_Node;
        Node* min_Node_priv;
        Node* inner_temp ;
        Node* inner_temp_priv ;
        int min=head->data;

        while (outer_temp != NULL)
        {
            min_Node = outer_temp;
            min_Node_priv = outer_temp_priv; 
            min = min_Node->data;

            inner_temp = outer_temp;
            inner_temp_priv = outer_temp_priv;
            while (inner_temp!=NULL){
                cout<<(min>inner_temp->data)<<"\t"<<min<<"\t"<<inner_temp->data<<endl; 
                if(min>inner_temp->data){
                    min=inner_temp->data;
                    min_Node=inner_temp;
                    min_Node_priv=inner_temp_priv;
                }
                inner_temp_priv=inner_temp;
                inner_temp=inner_temp->next;
            }
            //changing plaaces of two nodes;
            //In case nothing is null
            if(min_Node==outer_temp){}
            else{
                cout<<min_Node->data<<endl;
                cout<<outer_temp->data<<endl;
            if(min_Node_priv==NULL){
                cout<<"min are numm"<<endl;
            }else{
            min_Node_priv->next =outer_temp;
            }
            if(outer_temp_priv==NULL){
                cout<<"Outer are numm"<<endl;
            }
            else{
            outer_temp_priv->next = min_Node;
            }
            Node* temp = min_Node->next;
            min_Node->next = outer_temp->next;
            outer_temp->next = temp;
            }
                   outer_temp_priv=outer_temp;
            outer_temp = outer_temp->next;

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