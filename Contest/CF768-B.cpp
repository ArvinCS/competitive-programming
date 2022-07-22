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
    	int n;
    	cin >> n;
    	
    	int a[n];
    	for(int x=0;x<n;x++){
    		cin >> a[x];
		}
		
		int ans = 0, last = n-1;
		for(int x=n-2;x>=0;x--){
			if(a[x] == a[n-1] && last == x+1){
				last = x;
				continue;
			}
			
			if(n-last == last-x){
				ans++;
				last = x;
			} else {
				if(x == 0){
					ans++;
					break;
				}
			}
		}
		
		cout << ans << "\n";
	}
    
	return 0;
}
