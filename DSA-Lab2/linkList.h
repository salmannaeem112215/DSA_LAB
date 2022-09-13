#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include<conio.h>
#include "Node.h"
using namespace std;

class LinkList
{
public:
    Node *head;

    LinkList()
    {
        head = NULL;
    }

    void InsertAtStart(int val);
    void InsertAtEnd(int val);
    void insertAfter(int val_pos, int val);
    void DELETE(int val);
    void deleteAtStart();
    void deleteAtEnd();
    void deleteByPosition(int pos);
    void update(int val_to_update, int val_after_update);
    void display();
    void search(int val);
    void sort_ascending();
    void sort_dscending();
};

void LinkList::InsertAtStart(int val)
{
    Node *myNode = new Node(val);
    if (head == NULL)
    {
        head = myNode;
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
    }
    else
    {   
        Node * temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = myNode;

    }
}
void LinkList::deleteAtStart(){
    if(head==NULL){
        cout<<"List Empty";
    }
    else{
        Node* temp = head;
        head=head->next;
        delete temp;
    }
}
void LinkList::deleteAtEnd(){
    if(head==NULL){
        cout<<"List Empty";
    }
    else
    {   
        Node* temp = head;
        if(head->next == NULL){
            deleteAtStart();
        }
        else{

        while(temp->next->next != NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        }

    }

}
void LinkList::deleteByPosition(int pos){
    if(head==NULL){
        cout<<"List Empty";
    }
    else
    {   
        Node* temp = head;
        int count;
        bool found =false;
        if(pos==0){
            deleteAtStart();
        }
        else{

        while(temp->next->next!= NULL ){
            if(count+1==pos){
                found=true;
                break;
            }
            count++;
            temp=temp->next;
        }
        Node* temp_a = temp->next->next;
        delete temp->next;
        temp->next = temp_a;
        }

    }
    if(pos==0){
        deleteAtStart();
    }
    else{
        int count=0; 
        bool remove =false;
        Node* temp =head;
        while (temp != NULL)
        {
            if(pos==count){
                remove= true;
            }

            temp=temp->next;
        }
        
    }
}
void LinkList::DELETE(int val) {
		if (head == NULL) {
			cout << "List is Empty , value can't be Delete" << endl;
		}
		else {
			bool found = false;
			Node* temp_curr = head;
			Node* temp_priv = NULL;

			while (temp_curr != NULL) {
                if(temp_curr->data==val && temp_curr==head){
                cout<<"1";
                deleteAtStart();
                //to Stay the same
                temp_priv = temp_priv;
                temp_curr = head;
                // break;
                }

                else if (temp_curr->data == val && temp_curr!= head) {
                cout<<"2";
                cout<<"Second Exceuted"<<endl;
					found = true;
					temp_priv->next = temp_curr->next;
					delete	temp_curr;

                //to Stay the same
                    temp_priv = temp_priv;
                    temp_curr = temp_priv->next;
                    // break;
				}

                else{
                cout<<"3";
				temp_priv = temp_curr;
				temp_curr = temp_curr->next;
                }

			}

			if (!found) {
				cout << "Node not found with value " << val << endl;
			}
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
                found = false;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Value Not Found in Linked List " << endl;
        }
    }
}
void LinkList::search(int val)
{
    if (head == NULL)
    {
        cout << "No Item in List " << endl;
    }
    else
    {
        Node *temp = head;
        int no_of_times = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                no_of_times++;
            }
            temp = temp->next;
        }
        if (no_of_times)
        {
            cout << "Value find " << no_of_times
                 << ((no_of_times == 1) ? " time" : "times")
                 << " in List " << endl;
        }
        else
        {
            cout << "Value not found " << endl;
        }
    }
}

void LinkList::insertAfter(int val_pos, int val)
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
            if (temp->data == val_pos)
            {
                // creating
                Node *myNode = new Node(val);
                // Inserting
                myNode->next = temp->next;
                temp->next = myNode;
                // skipping the inserted Node
                temp = myNode;
            }
            temp = temp->next;
        }
    }
}

void LinkList::sort_ascending()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node *outer = head;
        Node *min;
        int min_val ;
        while (outer != NULL)
        {
            min = outer;
            min_val=outer->data;
            Node* inner= outer;
            while (inner!= NULL)
            {

                if(min_val>inner->data){
                    min_val= inner->data;
                    min=inner;
                }
                inner=inner->next;
            }

            // Swap value;
            min->data = outer->data;
            outer->data = min_val;

            
            // Updating Address for next Node Interation
            outer = outer->next;
        }
    }
}
void LinkList::sort_dscending()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node *outer = head;
        Node *max;
        int max_val ;
        while (outer != NULL)
        {
            max = outer;
            max_val=outer->data;
            Node* inner= outer;
            while (inner!= NULL)
            {

                if(max_val<inner->data){
                    max_val= inner->data;
                    max=inner;
                }
                inner=inner->next;
            }

            // Swap value;
            max->data = outer->data;
            outer->data = max_val;

            
            // Updating Address for next Node Interation
            outer = outer->next;
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
        cout<<"List : ";
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

#endif