#include <iostream>
using namespace std;

class BankAccount{
	double balance;
	static int id;
	public:
		BankAccount(){
			balance = 0.0;
		}
		BankAccount(double bal) :balance(bal) {}
		BankAccount(const BankAccount& Acc){
			balance = Acc.balance;
		}
		void transaction(double amount){
			balance -= amount;
		}
		void show(){
			cout <<"Balance: " << balance << endl << endl;
		}
};

int main(){
	BankAccount account1;
	account1.show();
	BankAccount account2(1000);
	account2.show();
	BankAccount account3(account2);
	account3.transaction(200);
	account3.show();
	account2.show();
}

