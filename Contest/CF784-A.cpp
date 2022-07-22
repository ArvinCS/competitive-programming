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
		
		cout << "Division ";
		if(n <= 1399){
			cout << "4\n";
		} else if(n <= 1599){
			cout << "3\n";
		} else if(n <= 1899){
			cout << "2\n";
		} else {
			cout << "1\n";
		}
	}
	
    return 0;
}

