#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	
    	if(k == 0){
    		for(int x=0;x<n;x++){
    			int inv = (n-1)^x;
    			
    			if(x < inv && inv < n){
    				cout << x << " " << inv << "\n";
				}
			}
		} else if(k > 0 && k < n-1){
			for(int x=1;x<n-1;x++){
    			int inv = (n-1)^x;
    			
    			if(inv == k || x == k) continue;
    			if(x < inv){
    				cout << x << " " << inv << "\n";
				}
			}
			cout << 0 << " " << ((n-1)^k) << "\n";
			cout << k << " " << n-1 << "\n";
		} else if(k == n-1){
			if(n == 4){
				cout << "-1\n";
				continue;
			}
			
			cout << n-1 << " " << n-2 << "\n";
			cout << n-3 << " " << 1 << "\n";
			cout << 0 << " " << 2 << "\n";
			for(int x=3;x<n-3;x++){
				int inv = (n-1)^x;
				
				if(x < inv){
					cout << x << " " << inv << "\n";
				}
			}
		} else {
			cout << "-1\n";
		}
	}
    
	return 0;
}
