#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void guessingGame2(int totalPlayers, int currentPlayer, int number);
void guessingGame1(int totalPlayers, int currentPlayer, int number){
	int guess;
	cout<<"player "<<currentPlayer<<" enter ur guess: ";
	cin>> guess;
	if(guess == number){
		cout<<"Player "<< currentPlayer<< " guessed it";
		return;
	}
	else if(guess > number){
		cout<<"Guess was too hight\n";
	}
	else cout<< "Guess was too low\n";
	currentPlayer++;
	if(totalPlayers < currentPlayer) currentPlayer = 1;
	guessingGame2(totalPlayers, currentPlayer, number);
}

void guessingGame2(int totalPlayers, int currentPlayer, int number){
	int guess;
	cout<<"player "<<currentPlayer<<" enter ur guess: ";
	cin>> guess;
	if(guess == number){
		cout<<"Player "<< currentPlayer<< " guessed it";
		return;
	}
	else if(guess > number){
		cout<<"Guess was too hight\n";
	}
	else cout<< "Guess was too low\n";
	currentPlayer++;
	if(totalPlayers < currentPlayer) currentPlayer = 1;
	guessingGame1(totalPlayers, currentPlayer, number);
}


int main(){
	srand(time(0));
	int num = rand()%100 +1;
	int players;
	do{
		cout<<"Enter number of players: ";
		cin>> players;	
	}while(players < 1);
	guessingGame1(players,1,num);
}
