#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data) : data(data), next(nullptr){}
};

int search(Node* head, int val, int index){
	if(head == nullptr) return -1;
	if(head->data == val) return index;
	return search(head->next, val, index+1);
}

int main(){
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	
	int pos = search(head, 2, 0);
	if(pos==-1) cout<<"Not found";
	else cout<<"Found at pos: "<< pos;
}
