#include <iostream>

using namespace std;

void swapString(string &s, int a, int b){
	char temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string currency;
	cin >> currency;
	
	int lastDigit = currency.length() - 1;
	int lastPos = 0;
	bool found = false;
	for(int x=0;x<currency.length();x++){
		int n = currency[x] - '0';
		if(n % 2 == 0){
			lastPos = x;
			found = true;
			if(currency[lastDigit] > currency[x]) break;
		}
	}
	
	if(found){
		char temp = currency[lastPos];
		currency[lastPos] = currency[lastDigit];
		currency[lastDigit] = temp;
		found = true;
		cout << currency << "\n";
	} else cout << "-1\n";
	
    return 0;
}
