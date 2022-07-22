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
	
	vector<pair<tuple<ll, ll, ll>, int>> data;
	for(int i=0;i<n;i++){
		int x, y, z;
		cin >> x >> y >> z;
		
		data.push_back({make_tuple(x, y, z), i});
	}
	
	unordered_set<int> st;
	for(int x=0;x<n;x++){
		if(st.count(x)) continue;
		ll a = get<0>(data[x].first), b = get<1>(data[x].first), c = get<2>(data[x].first);
		int idx = -1;
		ll dist = inf_ll;
		for(int y=0;y<n;y++){
			if(st.count(y) || x == y) continue;
			ll d = get<0>(data[y].first), e = get<1>(data[y].first), f = get<2>(data[y].first);
			ll tmp = (a-d)*(a-d) + (b-e)*(b-e) + (c-f)*(c-f);
			if(tmp < dist){
				dist = tmp;
				idx = y;
			}
		}
		st.insert(x);
		st.insert(idx);
		
		cout << x+1 << " " << idx+1 << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

