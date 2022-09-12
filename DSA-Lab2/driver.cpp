#include<iostream>
#include"linkList.h"
using namespace std;


int main(){
    LinkList L;

    L.InsertAtStart(1);
    L.InsertAtStart(2);
    L.display();

    L.InsertAtEnd(3);
    L.display();

    L.update(3,13);
    L.display();

    L.search(4);
    L.search(2);

    L.insertAfter(2,5);
    L.display();

}