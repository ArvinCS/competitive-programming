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
		int n, m;
		cin >> n;
		
		int mx1 = 0, mx2 = 0;
		for(int x=0;x<n;x++){
			int val;
			cin >> val;
			
			if(val > mx1) mx1 = val;
		}
		
		cin >> m;
		
		for(int x=0;x<m;x++){
			int val;
			cin >> val;
			
			if(val > mx2) mx2 = val;
		}
		
		if(mx2 < mx1){
			cout << "Alice\n";
			cout << "Alice\n";
		} else if(mx2 == mx1){
			cout << "Alice\n";
			cout << "Bob\n";
		} else {
			cout << "Bob\n";
			cout << "Bob\n";
		}
	}
	
    return 0;
}

