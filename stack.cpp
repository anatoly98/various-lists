
#include "stdafx.h"
#include "iostream"

using namespace std;

struct node_s
{
	int data;
	node_s*prev;
};

struct stack_descr {
	node_s* top = nullptr;
};

void push(stack_descr*, int value);
int pop(stack_descr*);


int main()
{

	stack_descr *descr = new stack_descr;

	int n;
	cout << "number of element in stack = "; cin >> n;
	cout << endl;

	
	for (int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			push(descr, value);
		}
	
	cout << endl;
	for (int i=0; i<n; i++)
		cout << pop(descr) << endl;
    _gettch();
	return 0;
}
void push(stack_descr* descr, int value) {
	node_s *node = new node_s;
	node->data = value;
	node->prev = descr->top;
	descr->top = node;
}
int pop(stack_descr* descr)
{               
	int newdata = descr->top->data;
	node_s *save_topptr;
	save_topptr = descr->top;
	descr->top = descr-> top->prev;
	delete save_topptr;
	return newdata;
}