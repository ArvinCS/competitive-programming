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

const int maxN = 1e5 + 5;

struct City{
	int idx;
	ll a, c;
	
	inline operator < (City &b){
		if(a == b.a){
			if(c == b.c) return idx < b.idx;
			return c < b.c;
		}
		return a < b.a;
	}
};

City city[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	City one;
	ll sumC = 0;
	for(int x=0;x<n;x++){
		cin >> city[x].a >> city[x].c;
		city[x].idx = x;
		
		if(x == 0) one = city[x];
		sumC += city[x].c;
	}
	
	sort(city, city+n);
	
	int pos = -1;
	ll prefix[n][2]; // 0 a 1 c
	for(int x=0;x<n;x++){
		if(city[x].idx == 0) pos = x;
		prefix[x][0] = city[x].a + (x > 0 ? prefix[x-1][0] : 0);
		prefix[x][1] = city[x].c + (x > 0 ? prefix[x-1][1] : 0);
	}
	
	priority_queue<pair<ll, int>> pq;
	pq.push({city[0].a + city[0].c, 0});
	
	int backtrack[n];
	fill(backtrack, backtrack+n, -1);
	
	ll ans = prefix[n-1][1];
	for(int x=1;x<n;x++){
		pair<ll, int> p = pq.top();
		
		backtrack[x] = p.second;
		pq.push({city[x].a + city[x].c, x});
	}
	
	int cur = n-1;
	while(cur >= 0){
		if(backtrack[cur] >= 0){
			ans += max(0ll, city[cur].a - city[backtrack[cur]].a - city[backtrack[cur]].c);
		}
		cur = backtrack[cur];	
	}
	
	cout << ans << "\n";
    return 0;
}

