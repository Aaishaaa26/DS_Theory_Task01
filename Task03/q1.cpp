#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data) : data(data), next(nullptr){}
};

class linkList{
	Node *head;

	public:
		linkList() : head(nullptr){}
		
		void insertNode(int data){  	//assuming tail se kr rhe hoge abhhi sirf
		
			Node* newNode = new Node(data);
			if(head == nullptr){
				head = newNode;
				return;
			}
			Node *temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void display(){
			if(head == nullptr){
				cout<<"No data"<<endl;
				return;
			}
			Node* temp = head;
			cout<<"Display:\n";
			while(temp != nullptr){
				cout <<temp->data << "->";
				temp = temp->next;
			}
			cout <<"NULL"<<endl<<endl;
		}
		
		void arrange(){
			Node* evenStart = nullptr, *oddStart = nullptr;
			Node* evenEnd = nullptr, *oddEnd = nullptr;
			Node* curr = head;
			while(curr!= nullptr){
				Node* next = curr->next;
				curr->next = nullptr; //agay se store na ho agle ka address
				if(curr->data % 2 ==0){
					if(evenStart == nullptr){
						evenStart = curr;
						evenEnd = curr;
					}
					else{
						evenEnd->next = curr;
						evenEnd = curr;
					}	
				}
				else{
					if(oddStart == nullptr){
						oddStart = curr;
						oddEnd = curr;
					}
					else{
						oddEnd->next = curr;
						oddEnd = curr;
						}
					}
					curr = next;
			}
			if(evenStart == nullptr){
				head = oddStart;
			}
			else{
				head = evenStart;
				evenEnd->next = oddStart;
			}
		}
		
		
		~linkList(){
			Node* temp = head;
			while(temp != nullptr){
				Node* nextNode = temp->next;
				delete temp;
				temp = nextNode;
			}
			
		}
		
};

int main(){
	linkList list1, list2, list3;
	int n, data;
	cout<<"Enter Number of data u want to enter: ";
	cin>> n;
	for(int i = 0; i < n; i++){
		cout<<"Enter Data "<<i+1<<": ";
		cin>> data;
		list1.insertNode(data);
	}
	list1.display();
	list1.arrange();
	list1.display();
	
	//showing rest of them for logic (not taking user input)
	list2.insertNode(8);
	list2.insertNode(12);
	list2.insertNode(10);
	list2.display();
	list2.arrange();
	list2.display();
	
	list3.insertNode(1);
	list3.insertNode(3);
	list3.insertNode(5);
	list3.insertNode(7);
	list3.display();
	list3.arrange();
	list3.display();
	
}
