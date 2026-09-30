#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data) : data(data), next(nullptr){}
};

void display(Node* head){
	if(head==nullptr){
		cout<<"NULL";
		return;	
	} 
	cout<<head->data<<"->";
	display(head->next);
}

int main(){
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	display(head);
}
