#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void solve(string s){
	us l = 0, r = s.length()-1;
	while(l < r){
		if(s[l] != s[r]){
			cout << "bukan palindrom\n";
			return;
		}
		l++;
		r--;
	}
	cout << "palindrom\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	while(n--){
		string s;
		cin >> s;
		
		solve(s);
	}
	
    return 0;
}

