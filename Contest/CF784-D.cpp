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
		
		bool possible = true;
		bool r = false, b = false;
		int last = 0;
		for(int x=0;x<n;x++){
			if(s[x] == 'W'){
				if(last < x){
					if(!r || !b || (x-last) == 1){
						possible = false;
					}	
				}
				
				r = false;
				b = false;
				last = x+1;
			}
			
			if(s[x] == 'R') r = true;
			if(s[x] == 'B') b = true;
		}
		if(last < n){
			if(!r || !b || (n-last) == 1){
				possible = false;
			}
		}
		
		cout << (possible ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

