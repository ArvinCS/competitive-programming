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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int mn = n, mx = -1;
		for(int x=0;x+1<n;x++){
			if(a[x] == a[x+1]){
				mn = min(mn, x);
				mx = max(mx, x+1);
			}
		}
		
		if(mn > mx || mx-mn-1 == 0){
			cout << 0 << "\n";
		} else if(mx-mn-1 == 1){
			cout << 1 << "\n";
		} else {
			cout << mx-mn-2 << "\n";
		}
	}
	
    return 0;
}

