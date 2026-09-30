#include <iostream>
#include <string>
using namespace std;

bool palindrome(string word, int start, int end){
	if (start >= end) return true;
	if(word[start] != word[end]) return false;
	return palindrome(word, start+1, end-1);
}

int main(){
	string word;
	cin>>word;
	if(palindrome(word, 0, word.length()-1)) cout<<"palindrome";
	else cout<<"no";
}
