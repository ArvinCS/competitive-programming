#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans = -1e9;
	int mn = a[0];
	
	for(int x=1;x<n;x++){
		ans = max(ans, a[x]-mn);
		mn = min(mn, a[x]);
	}
	
	cout << ans << "\n";
    return 0;
}

