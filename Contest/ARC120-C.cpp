#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	int ans = 0, ans2 = 0;
	for(int x=0;x<n;x++){
		ans += a[x]-(x+1);
		ans2 += b[x]-(x+1);
	}
	
	if(ans < 0) ans = -1;
	cout << ans << " " << ans2 << "\n";
    return 0;
}

