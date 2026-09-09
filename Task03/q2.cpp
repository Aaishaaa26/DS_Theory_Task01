#include <iostream>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T>* next; //<T> Node for same data type
		Node(T data): data(data), next(nullptr){}		
};
template <class T>
class linkList{
	Node<T>* head;
	public:
		linkList(): head(nullptr){}
		
		void insertNode(T data){
			Node<T>* newNode = new Node<T>(data);
			if(head == nullptr){
				head = newNode;
				return;
			}
			Node<T>* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		
		void displayList(){
			Node<T>* temp = head;
			cout<<"\nList Display:\n";
			while(temp!= nullptr){
				cout<<temp->data<< "->";
				temp = temp->next;
			}
			cout<<"NULL\n";
		}
		
		void checkPal(){
			int count = 0;
			displayList();
			Node<T>* temp = head;
			while(temp!= nullptr){
				count++;
				temp = temp->next;
			}
			if(count == 0 || count == 1){
				cout<< "Palindrome\n";
				return;
			}
			T arr[count];
			temp = head;
			for(int i = 0; i < count; i++){
				arr[i] = temp->data;
				temp = temp->next;
			}
			for(int i = 0; i < count/2; i++){
				if(arr[i] != arr[count-1-i]){
					cout<<"Linked List is not a palindrome\n"<< endl;
					return;
				}
			}
			cout<<"Linked List Is a Palindrome (YAS)\n"<< endl;
		}
		
		~linkList(){
			Node<T>* temp = head;
			while(temp != nullptr){
				Node<T>* next = temp->next;
				delete temp;
				temp = next;
			}
		}
};

int main(){
	linkList<int> list1;
	int n;
	cout<<"enter number of integers you'll be entering: ";
	cin>> n;
	int data;
	for(int i = 0; i< n; i++){
		cout<<"Data "<<1+i<< ": ";
		cin>> data;
		list1.insertNode(data);
	}
	list1.checkPal();
	
	linkList<char> list2;
	list2.insertNode('B');
	list2.insertNode('O');
	list2.insertNode('R');
	list2.insertNode('R');
	list2.insertNode('O');
	list2.insertNode('W');
	list2.insertNode('O');
	list2.insertNode('R');
	list2.insertNode('R');
	list2.insertNode('O');
	list2.insertNode('B');	
	list2.checkPal();
	
	linkList<int> list3;
	list3.insertNode(5);
	list3.insertNode(4);
	list3.insertNode(3);
	list3.checkPal();
}
