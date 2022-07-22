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
	
	int data[n], pos[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		data[x]--;
		pos[data[x]] = x;
	}
	
	tuple<ll, ll, ll> cost[n];
	for(int x=0;x<n;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
		cost[x] = make_tuple(a, b, c);
	}
	
	vector<int> left, right, any;
	for(int x=0;x<n;x++){
		ll a = get<0>(cost[x]), b = get<1>(cost[x]), c = get<2>(cost[x]);
		
		if(a <= min(b, c)){
			any.push_back(x);
		} else if(b <= min(a, c)){
			right.push_back(x);
		} else {
			left.push_back(x);
		}
	}
	
	sort(left.rbegin(), left.rend());
	sort(right.begin(), right.end());
	
	vector<vector<int>> v;
	int origin[n];
	bool visited[n];
	fill(visited, visited+n, false);
	
	vector<pair<int, int>> cur;
	for(int x=0;x<n;x++){
		vector<int> tmp;
		auto it = lower_bound(cur.begin(), cur.end(), make_pair(data[x], x));
		if(it == cur.begin()){
			origin[x] = v.size();
			tmp.push_back(x);
			v.push_back(tmp);
			continue;
		}
		
		cout << (*it).first << "\n";
		
		cur.push_back({data[x], x});
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

