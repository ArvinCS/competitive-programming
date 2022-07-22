#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	for(int x=0;x<s.length();x++){
		if(s[x] >= '5' && (x == 0 && s[x] < '9' || x > 0)){
			s[x] = '9' - (s[x] - '0');
		}	
	}
	
	cout << s << "\n";
	
    return 0;
}
