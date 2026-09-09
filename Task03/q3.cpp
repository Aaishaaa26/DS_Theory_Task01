#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		string data;
		Node* next;
		
		Node(string data) : data(data), next(nullptr){}
};

class circularList{
	Node* head;
	public:
		circularList(): head(nullptr){}
		
		void insertNode(string data){
			Node* newNode = new Node(data);
			if(head == nullptr){
				head = newNode;
				head->next = head;
				return;
			}
			
			Node* temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
		
		void display(){
			Node* temp = head;
			if(temp==nullptr){
				cout<<"Empty List\n"<< endl;
				return;
			}
			do{
				cout<< temp->data<< "->";
				temp= temp->next;
			}while(temp!= head);
			cout <<"back to "<< temp->data<<endl<<endl;
		}
		
		void removePlayer(){
	   		if(head == nullptr){
    		    return;
    		}
	   		Node* temp = head;
	   		cout<<"elimination: "<<endl;
    		while(head != head->next){
            	cout<<"->";
				temp = temp->next;        		
        		Node* curr = temp->next;
        		temp->next = curr->next;
        		if(curr == head){
            		head = curr->next;
        		}
        		cout<< curr->data;
        		delete curr;
				temp = temp->next;
    		}
    		cout << "Final remaining player: " << head->data << endl;
		}
	
		~circularList(){
			if(head==nullptr){
				return;
			}
			Node* temp = head->next;
			while(temp!=head){
				Node* nextNode = temp->next;
				delete temp;
				temp = nextNode;
			}
			delete head;
		}
};

int main(){
	circularList list1;
	list1.insertNode("Babar Azam");
	list1.insertNode("M.Rizwan");
	list1.insertNode("Fakhra Zaman");
	list1.insertNode("Saheed Afridi");
	list1.insertNode("Haris Rauf");
	list1.insertNode("Naseem Shah");
	list1.display();
	list1.removePlayer();
	
	//user input ;( eww
	int n;
	do{
		cout<< "Enter Number of players u want to enter(min 11): ";
		cin>> n;
	}while(n < 11);
	cin.ignore();
	string data;
	circularList list2;
	for(int i = 0; i < n; i++){

		cout<<"Enter Player " <<i+1<<" Name: ";
		getline(cin,data);
		list2.insertNode(data);
	}
	list2.display();
	list2.removePlayer();	
}
