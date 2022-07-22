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

ll cnt[maxN];

bool customSort(int a, int b){
	return abs(cnt[a]) < abs(cnt[b]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	fill(cnt, cnt+n, 0);
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
		cnt[a] -= c;
		cnt[b] += c;
	}
	
	vector<int> a, b;
	for(int x=0;x<n;x++){
		if(cnt[x] < 0){
			a.push_back(x);
		} else if(cnt[x] > 0){
			b.push_back(x);
		}
	}
	
	sort(a.begin(), a.end(), customSort);
	sort(b.begin(), b.end(), customSort);
	
	vector<tuple<int, int, ll>> ans;
	int p = 0, q = 0;
	while(p < a.size() && q < b.size()){
		if(cnt[a[p]] == 0) p++;
		if(cnt[b[q]] == 0) q++;
		if(p == a.size() || q == b.size()) break;
		
		ll mn = min(-cnt[a[p]], cnt[b[q]]);
		ans.push_back(make_tuple(a[p], b[q], mn));
		cnt[a[p]] += mn; cnt[b[q]] -= mn;
	}
	
	cout << ans.size() << "\n";
	for(auto t : ans){
		cout << get<0>(t)+1 << " " << get<1>(t)+1 << " " << get<2>(t) << "\n";
	}
    return 0;
}

