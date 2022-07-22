#include <iostream>

using namespace std;

bool palindrom(string kata){
	if(kata.length() <= 1){
		return true;
	} else {
		int len = kata.length();
		char first = kata[0];
		char last = kata[len - 1];
		if(first == last){
			kata = kata.substr(1,len-2);
			return palindrom(kata);
		} else {
			return false;
		}
	}
}

int main(){
	string kata;
	cin >> kata;

	if(palindrom(kata)) cout << "YA\n";
	else cout << "BUKAN\n"; 
	return 0;
}
