#include<iostream>
#include<string>
#include"linkList.h"
#include"selectingMenu.h"
using namespace std;


int main(){
    //Creating Menu
    int choice =-1;
    int val;
    int pos;
    bool flag = true;
    int no_of_options=12;
    string options[]= {
    "Quit",
    "Insert At Start",
    "Insert At End",
    "Insert After a value",
    "Delete from Start",
    "Delete from End",
    "Delete by Position",
    "Delete by value",
    // "Update by Position",
    "Update by Value",
    "Search by Value",
    "Sort - Ascending",
    "Sort - Descending",
    };
    SelectingMenu home_menu(options,no_of_options);
    
    //Creating LinkedList
    LinkList L;
    // Some Dummy Data to perform Actions eadsyly
    // L.InsertAtStart(1);
    // L.InsertAtStart(2);
    // L.InsertAtStart(3);
    // L.InsertAtStart(4);
    L.InsertAtEnd(5);
    L.InsertAtEnd(6);
    L.InsertAtEnd(8);
    L.InsertAtEnd(7);

    L.display();

    while(flag){
        system("CLS");
        L.display();
        choice = home_menu.menu();
        switch (choice)
        {
        case 1:
            flag=false;
            break;

        case 2:
            cout<<"Enter Value -> ";
            cin>>val;
            L.InsertAtStart(val);
            break;

        case 3:
            cout<<"Enter Value -> ";
            cin>>val;
            L.InsertAtEnd(val);
            break;

        case 4:
            int val_pos;
            int val;
            cout<<"Enter Value as Position -> ";
            cin>>val_pos;
            cout<<"Enter Value to be Inserted after Position -> ";
            cin>>val;
            L.insertAfter(val_pos,val);
            break;

        case 5:
            L.deleteAtStart();
            break;
        case 6:
            L.deleteAtEnd();
            break;
        case 7:
            cout<<" Not Working "<<endl;
            cout<<"Enter Position ->";
            cin>>pos;

            L.deleteByPosition(pos);
            break;
        case 8:
            cout<<"Enter Value -> ";
            cin>>val;
            L.DELETE(val);
            break;
        case 9:
            int before;
            int after;
            cout<<"Enter Value to Update ->";
            cin>>before;
            cout<<"Enter Value   ->";
            cin>>after;
            L.update(before,after);

            break;
        case 10:
            cout<<"Enter Val -> ";
            cin>>val;
            L.search(val);
            break;
        case 11:
            L.sort_ascending();
            
            break;
        case 12:
            // L.sort_dscending();
            L.sortDes();
            
            break;
        
        default:
            break;
        }
        cout<<"\nPress Any Key !";
        getch();
    
    }





}