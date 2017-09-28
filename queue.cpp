#include "stdafx.h"

#include "iostream"



using namespace std;



struct queue

{

	int data;

	queue*prev;

};




struct queue_tail {

	queue* tail = nullptr;
	int counter = 0;

};

struct queue_head {

	queue* head = nullptr ;

};



void enqueue(queue_tail*, queue_head*, int value);

int dequeue(queue_head*);





int main()

{



	queue_tail *descr_tail = new queue_tail;
	queue_head *descr_head = new queue_head;




	int n;

	cout << "number of element in stack = "; cin >> n;

	cout << endl;



	

	for (int i = 0; i < n; i++)

		{

			int value;

			cin >> value;

			enqueue(descr_tail,descr_head, value);

		}

	

	cout << endl;

	for (int i=0; i<n; i++)

		cout << dequeue(descr_head) << endl;

    _gettch();

	return 0;

}

void enqueue(queue_tail* descr_tail, queue_head* descr_head, int value) {

	queue *node = new queue;

	if (descr_tail->counter == 0)

	{
		descr_head->head = node;
		descr_tail->tail = node;
		node->data = value;
		descr_tail->counter = 1;
	}

	else
	{

		node->data = value;
		descr_tail->tail->prev = node;
		descr_tail->tail = node;
		descr_tail->counter++;
	}
}

int dequeue(queue_head* descr_head)

{               

	int newdata = descr_head->head->data;

	queue *save_headptr;

	save_headptr = descr_head->head;

	descr_head->head = descr_head-> head->prev;

	delete save_headptr;

	return newdata;

}

