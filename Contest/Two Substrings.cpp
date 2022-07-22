#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	bool ans = false, found = false;
	
	// Find first AB
	for(ui x=1;x<s.length();x++){
//		cout << x << "-\n";
		if(s[x-1] == 'A' && s[x] == 'B' && !found){
			found = true;
			x++;
		} else if(s[x-1] == 'B' && s[x] == 'A' && found){
			ans = true;
			break;
		}
//		cout <<"-"<< x << "\n";
	}
	
	found = false;
	// Find first BA
	for(ui x=1;x<s.length();x++){
		if(s[x-1] == 'A' && s[x] == 'B' && found){
			ans = true;
			break;
		} else if(s[x-1] == 'B' && s[x] == 'A' && !found){
			found = true;
			x++;
		}
//		cout << x << "\n";
	}
	
	if(ans){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

