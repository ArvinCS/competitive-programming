#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, k;
	cin >> n >> k;
	
	vector<us> v[n+1];
	
	us ans = 0;
	for(us x=0;x<n;x++){
		us tmp;
		cin >> tmp;
		
		ans += v[(k-tmp)%k].size();
		v[tmp%k].push_back(tmp);
	}
	
	cout << ans << "\n";
    return 0;
}

