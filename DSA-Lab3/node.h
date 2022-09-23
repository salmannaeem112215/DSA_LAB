#pragma once
#include<iostream>
using namespace std;

class Node {
public:
	int link;
	Node* next;
	Node* prev;

	Node(int v) {
		link = v;
		next = NULL;
		prev = NULL;
	}
};