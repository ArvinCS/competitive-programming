#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		if(s == "0" || s == "1" || s == "01" || s == "10"){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

