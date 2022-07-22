#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a, b;
	getline(cin, a);
	getline(cin, b);
	
	unsigned int eko = 0, draw = 0, round = (a.length() + 1)/2;
	for(int x=0;x<a.length();x+=2){
		if(a[x] == 'a' && b[x] == 'e'){
			eko++;
		} else if(a[x] == 'h' && b[x] == 'a'){
			eko++;
		} else if(a[x] == 'e' && b[x] == 'h'){
			eko++;
		} else if(a[x] == b[x]){
			draw++;
		}
	}
	
	if(eko > round-eko-draw){
		cout << "Eko wins\n";
	} else if(eko == round-eko-draw){
		cout << "Draw\n";
	} else {
		cout << "Ganesh wins\n";
	}
    return 0;
}
