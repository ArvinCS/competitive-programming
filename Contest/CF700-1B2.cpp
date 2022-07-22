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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v[n+1];
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v[a[x]].push_back(x);
	}
	for(int x=0;x<=n;x++) v[x].push_back(inf_int);
	
	int ans = 1;
	int last[2];
	last[0] = a[0];
	last[1] = 0;
	for(int x=1;x<n;x++){
		if(last[0] == a[x]){
			last[0] = a[x];
		} else if(last[1] == a[x]){
			last[1] = a[x];
		} else {
			if(last[1] == 0){
				last[1] = a[x];
				ans++;
			} else {
				auto it1 = upper_bound(v[last[0]].begin(), v[last[0]].end(), x);
				auto it2 = upper_bound(v[last[1]].begin(), v[last[1]].end(), x);
				
				if(*it1 >= *it2){
					last[0] = a[x];
				} else {
					last[1] = a[x];
				}
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

