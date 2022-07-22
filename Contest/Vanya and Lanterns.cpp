#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	ui l;
	cin >> n >> l;
	
	ui latern[n+1];
	for(us x=0;x<n;x++){
		cin >> latern[x];	
	}
	
	sort(latern, latern+n);
	
	double ans = latern[0];
	for(us x=0;x<n;x++){
		ans = max(ans, x+1 < n ? (latern[x+1] - latern[x])/2.0 : l - latern[x]);
	}

	cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
