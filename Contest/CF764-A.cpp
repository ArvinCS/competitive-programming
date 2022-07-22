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
		int mx = 0, mn = 1e9;
		for(int x=0;x<n;x++){
			cin >> a[x];
			mx = max(mx, a[x]);
			mn = min(mn, a[x]);
		}
		
		cout << mx-mn << "\n";
	}
	
    return 0;
}

