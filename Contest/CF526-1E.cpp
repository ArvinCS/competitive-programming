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
		
		while(dq.size() > 1 && dq.back().second <= l.intersect(dq.back().first)){
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
			if(dq[0].first.calc(x) <= dq[1].first.calc(x)) dq.pop_front();
			else break;
		}
		
		return dq[0].first.calc(x);
	}
};

const int maxN = 1e6 + 5;

tuple<ll, ll, ll> data[maxN];
ll table[maxN];
CHT cht;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
		data[x] = make_tuple(a, b, c);
	}
	
	sort(data, data+n);
	
	cht.insert(0, 0);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ll a = get<0>(data[x]), b = get<1>(data[x]), c = get<2>(data[x]);
		table[x] = cht.query(b) + (a*b) - c;
		ans = max(ans, table[x]);
		cht.insert(-a, table[x]);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

