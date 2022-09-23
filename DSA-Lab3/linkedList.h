#pragma once
#include <iostream>
#include "node.h"
using namespace std;

class LinkedList
{
private:
	Node *head;
	Node *tail;

public:
	// LinkedList Functionality
	LinkedList();
	void insertHead(int v);
	void insertTail(int v);
	bool isEmpty();

	void Insertion(int v);
	void InsertLast(int v);
	// void InsertBeforeLast(int v);
	void insertBeforeLast(int v);
	void InsertAfter(int key, int v);
	void InsertBefore(int key, int v);
	void Deletion();   // delete head
	void DeleteLast(); // delete tail
	void Delete_by_pos(int pos );

	void displayForward();
	void displayBackward();

	// Lab Task
	void Insert();
	void ReverseDisplay();
	Node *remove(int v);
	bool Delete(int k); // delete a Node
};

// Lab Task
void LinkedList::Insert()
{
	int choice,key,val;
	cout << " Select Option of Inserting " << endl;
	cout << " 1. Insert Before Head " << endl;
	cout << " 2. Insert Before Tail " << endl;
	cout << " 3. Insert Before a Num " << endl;
	do
	{
		cout << " Choice : ";
		cin >> choice;
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:
		cout << "Enter Value :";
		cin >> val;
		Insertion(val);
		break;
	case 2:
		cout << "Enter Value :";
		cin >> val;
		insertBeforeLast(val);
		break;
	case 3:
		cout<<"Enter Value of a Node to Add :";
		cin>>val;
		cout<<"Enter Key Value of a Node to Add After :";
		cin>>key;
		InsertBefore(key,val);
	default:
		break;
	}
	cout<<endl;
};
void LinkedList::ReverseDisplay()
{
	displayBackward();
}
Node* LinkedList::remove(int v)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return NULL;
	}
	else
	{
		Node *temp = head;
		while (temp != NULL)
		{
			if (temp->link == v)
			{
				if(temp->prev!=NULL){
				temp->prev->next = temp->next;
				}
				else{
					head = temp->next;
				}
				if(temp->next!= NULL){
				temp->next->prev = temp->prev;
				}
				else{
					tail = temp->prev ;
				}

				temp->next=temp->prev = NULL;
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
}
bool LinkedList::Delete(int v)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		Node *temp = head;
		while (temp != NULL)
		{
			if (temp->link == v)
			{
				if(temp->prev!=NULL){
				temp->prev->next = temp->next;
				}
				else{
					head = temp->next;
				}
				if(temp->next!= NULL){
				temp->next->prev = temp->prev;
				}
				else{
					tail = temp->prev ;
				}
				delete temp;
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}

/// Double Node Functionality

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LinkedList::insertHead(int v)
{
	Node *myNode = new Node(v);
	if (isEmpty())
	{
		head = myNode;
		tail = myNode;
	}
	else
	{
		head->prev = myNode;
		myNode->next = head;
		head = myNode;
	}
}
void LinkedList::insertTail(int v)
{
	Node *myNode = new Node(v);
	if (isEmpty())
	{
		head = myNode;
		tail = myNode;
	}
	else
	{
		tail->next = myNode;
		myNode->prev = tail;
		tail = myNode;
	}
}
void LinkedList::insertBeforeLast(int v){
	Node *myNode = new Node(v);
		if (isEmpty())
		{
			head = myNode;
			tail = myNode;
		}
		else
		{	
			// Previous Node 
			if (tail->prev == NULL)
			{
				head = myNode;
			}
			else
			{
				tail->prev->next = myNode;
			}

			// Node to be Add 
			myNode->prev = tail->prev;
			myNode->next = tail;

			// Tail 
			tail->prev = myNode;
		}
}
void LinkedList::displayForward()
{
	if (isEmpty())
	{
		cout << "List is empty " << endl;
	}
	else
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->link << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
}
void LinkedList::displayBackward()
{
	if (isEmpty())
	{
		cout << "List is empty " << endl;
	}
	else
	{
		Node *temp = tail;
		while (temp != NULL)
		{
			cout << temp->link << "\t";
			temp = temp->prev;
		}
		cout << endl;
	}
}

void LinkedList::Insertion(int v)
{
	insertHead(v);
}
void LinkedList::InsertLast(int v)
{
	insertTail(v);
}
void LinkedList::InsertAfter(int key, int v)
{
	// key is a key value
	bool found = false;

	if (isEmpty())
	{
		cout << "List is Empty " << endl;
	}
	else
	{
		Node *myNode = new Node(v);
		Node *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (count == key)
			{
				found = true;
				break;
			}
			temp = temp->next;
			count++;
		}
		if (found)
		{	
			Node *tempNextNode = temp->next;
			myNode->next = temp->next;
			temp->next = myNode;
			myNode->prev = temp;
		}
		else
		{
			delete myNode;
			cout << "No Element Found with this key " << endl;
		}
	}
}
void LinkedList::InsertBefore(int key, int v)
{
	// key is a key value
	bool found = false;

	if (isEmpty())
	{
		cout << "List is Empty " << endl;
	}
	else
	{
		Node *myNode = new Node(v);
		Node *temp = head;
		while (temp != NULL)
		{
			if (temp->link == key)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (found)
		{
			// Previous Node 
			if (temp->prev == NULL)
			{
				head = myNode;
			}
			else
			{
				tail->prev->next = myNode;
			}
			// Node to be Add
			myNode->prev = temp->prev;
			myNode->next = temp;

			//Selected Node;
			temp->prev = myNode;

		}
		else
		{
			delete myNode;
			cout << "Key not Found  " << endl;
		}
	}
}
void LinkedList::Deletion()
{
	if (isEmpty())
	{
		cout << "LIST IS EMPTY" << endl;
	}
	else
	{
		Node *temp = head;
		if (head->next == NULL)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		delete temp;
	}
}

void LinkedList::DeleteLast()
{
	if (isEmpty())
	{
		cout << "LIST IS EMPTY" << endl;
	}
	else
	{
		Node *temp = tail;
		if (tail->prev == NULL)
		{
			head = tail = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		delete temp;
	}
}
void LinkedList::Delete_by_pos(int pos )
{
	bool found = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		Node *temp = head->next;
		for (int i = 1; i < pos; i++)
		{
			if (temp->next == NULL)
			{
				found = false;
			}
			temp = temp->next;
		}
		// Deleting Code
		if (temp == head)
		{
			if (temp->next == NULL)
			{
				head = tail = NULL;
			}
			else
			{
				head = temp->next;
				temp->next->prev = NULL;
			}
			delete temp;
		}
		else
		{
			if (temp->next == NULL)
			{
				tail = temp->prev;
			}
			else
			{
				temp->next->prev = temp->prev;
			}
			temp->prev->next = temp->next;
			delete temp;
		}
	}
}