#include<iostream>
#include<conio.h>
#include"linkedList.h"
using namespace std;

int main() {
	LinkedList l;
	bool flag = true;
	int choice,key,val;
	
	// Dummy List
	l.insertTail(1);
	l.insertTail(2);
	l.insertTail(3);
	l.insertTail(4);
	l.insertTail(5);
	do{	
		cout<<"List "<<endl;
		l.displayForward();
		cout<<"Menu "<<endl;
		cout<<"0. Quit "<<endl;
		cout<<"1. Insert Node "<<endl;
		cout<<"2. Remove Node"<<endl;
		cout<<"3. Delte Node"<<endl;
		cout<<"4. Reverse Display "<<endl;
		do{
			cout<<"Enter Choice : ";
			cin>>choice;
		}while(choice<0 || choice>4);

		switch (choice)
		{
		case 0:
			flag=false;
			break;
		case 1:
			l.Insert();
			break;
		case 2:
			cout<<"Enter Value of Node to Remove"<<endl;
			cin>>val;
			if(l.remove(val)){
				cout<<"Succesfully Remove"<<endl;
			}
			else{
				cout<<"Fail to Remove ! Value not Found"<<endl;
			}
			break;
		case 3:
			cout<<"Enter Value of Node to Delete"<<endl;
			cin>>val;
			if(l.remove(val)){
				cout<<"Succesfully Delete"<<endl;
			}
			else{
				cout<<"Fail to Delte ! Value not Found"<<endl;
			}
			break;
		case 4:
			l.ReverseDisplay();
			break;
		
		default:
			break;
		}
		cout<<endl;
		cout<<"Press Any Key "<<endl;
		_getch();
	}while(flag);


	// getch();
}

