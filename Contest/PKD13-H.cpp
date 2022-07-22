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
	
	int idx = 0, prv[n];
	fill(prv, prv+n, -1);
	
	map<pair<int, int>, int> last;
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
		prv[x] = last[data[x]];
		last[data[x]] = x;
	}
	
	set<pair<int, int>> st;
	int ans = 0, pos = -1;
	for(int x=0;x<n;x++){
		if(prv[x] >= pos){
			if(st.count(data[x])){
				ans++;
				st.clear();
				pos = x;
			} else {
				st.insert(data[x]);
			}
		}
	}
	if(st.size() > 0) ans++;
	
	cout << ans << "\n";
    return 0;
}

