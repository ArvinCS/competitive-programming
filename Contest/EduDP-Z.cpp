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

struct CHT {
	struct Line {
		ll slope, yi;
		
		Line(ll slope, ll yi) : slope(slope), yi(yi){
			
		}
		
		ll calc(ll x){
			return slope*x + yi;
		}
		
		ll intersect(Line b){
			return ceil((1.0 * b.yi-yi)/(slope-b.slope));
		}
	};
	
	deque<pair<Line, ll>> dq;
	
	void insert(ll slope, ll yi){
		Line l(slope, yi);
		
		while(!dq.empty() && dq.back().second >= l.intersect(dq.back().first)){
			dq.pop_back();
		}
		
		if(dq.empty()){
			dq.push_back({l, yi});
		} else {
			dq.push_back({l, l.intersect(dq.back().first)});
		}
	}
	
	ll query(ll x){
		while(dq.size() > 1){
			if(dq[1].second <= x) dq.pop_front();
			else break;
		}
		
		return dq[0].first.calc(x);
	}
};

const int maxN = 2e5 + 5;
ll table[maxN];
CHT cht;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m;
	cin >> n >> m;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	table[0] = 0;
	for(int x=0;x<n;x++){		
		if(x > 0){
			table[x] = cht.query(data[x]) + data[x]*data[x] + m;
		}
		cht.insert(-2*data[x], data[x]*data[x] + table[x]);
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

