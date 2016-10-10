#include<iostream>
using namespace std;

template <typename NodeType>
struct Node{
	NodeType data;
	Node *next;
};


template <class QueueType>
class Queue{

public:
	Queue();
	void enqueue(QueueType element);
	void dequeue();
	bool isEmpty();
	void print();
	QueueType get_front();
	~Queue();

private:
	Node<QueueType>* head;
	Node<QueueType>* tail;


};

template <class QueueType>
Queue<QueueType>::Queue(){
	head = NULL;
	tail = NULL;
}

template <class QueueType>
Queue<QueueType>::~Queue(){
	bool result = isEmpty();
	if (result == false){
		cout << "Destroying the queue" << endl;
		Node<QueueType> *currentPtr = head, *temp;

		while (currentPtr != 0){
			temp = currentPtr;
			currentPtr = currentPtr->next;
			delete temp;
		}
	}
}


template <class QueueType>
bool Queue<QueueType>::isEmpty(){
	if (head == 0){
		return true;
	}
	else return false;
}

template <class QueueType>
QueueType Queue<QueueType>::get_front(){
	bool result = isEmpty();
	if (result == true) //if queue is empty
	{
		cout << "Queue is empty, we cant have first element" << endl;

	}

	else {
		return head->data;
	}
	return 0;

}


template <class QueueType>
void Queue<QueueType>::enqueue(QueueType element){
	Node<QueueType>* newPtr = new Node<QueueType>();
	newPtr->data = element;
	newPtr->next = NULL;
	cout << element << " is enqueued in queue" << endl;

	bool result = isEmpty();
	if (result == true) //if queue is empty
	{
		tail = head = newPtr;
	}

	else
	{
		tail->next = newPtr;
		tail = newPtr;
	}
}


template <class QueueType>
void Queue<QueueType>::dequeue(){

	bool result = isEmpty();
	if (result == true){
		cout << "Queue is empty, we cant dequeue element" << endl;
		return;
	}

	else{

		if (tail == head){
			cout << head->data << " dequeued from queue" << endl;
			head = tail = NULL;
		}
		else {

			cout << head->data << " dequeued from queue" << endl;
			head = head->next;
		}

	}
}


template <class QueueType>
void Queue<QueueType>::print(){

	bool result = isEmpty();
	if (result == true){
		cout << "Queue is empty" << endl;
		return;
	}

	else{

		Node <QueueType>*temp = head;
		cout << "Queue is: ";
		while (temp != 0){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}


int main(){
	
	Queue<int> q;
	q.dequeue();
	q.enqueue(5);
	cout << "The first element is " << q.get_front() << endl;
	q.print();
	q.enqueue(10);
	q.enqueue(15);
	q.print();
	q.dequeue();
	q.dequeue();
	q.print();

	cout << endl;
	//Now lets check for doubles
	Queue<double> q2;
	q2.dequeue();
	q2.enqueue(5.6);
	cout << "The first element is " << q2.get_front() << endl;
	q2.print();
	q2.enqueue(10.12);
	q2.enqueue(15.3);
	q2.print();
	q2.dequeue();
	q2.dequeue();
	q2.print();

	system("pause");
}