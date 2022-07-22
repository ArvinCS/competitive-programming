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

const int maxN = 2e5 + 5;

int tree[maxN];

void update(int pos, int val){
	pos++;
	
	while(pos < maxN){
		tree[pos] += val;
		pos += pos&(-pos);
	}
}

int query(int pos){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans += tree[pos];
		pos -= pos&(-pos);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, h, m, k;
	cin >> n >> h >> m >> k;
	
	m >>= 1;
	
	vector<int> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x] >> a[x];
		
		a[x] %= m;
		v.push_back(a[x]);
		v.push_back(m+a[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	map<int, int> mp;
	for(int x=0;x<v.size();x++){
		mp[v[x]] = x;
	}
	
	fill(tree, tree+maxN, 0);
	
	vector<int> w[2*v.size()];
	for(int x=0;x<n;x++){
		w[mp[a[x]]].push_back(x);
		w[mp[a[x]+m]].push_back(x);
		
		update(mp[a[x]], 1);
		update(mp[a[x]+m], 1);
	}
	
	int ans = v[0];
	for(int x=0;x*2<v.size();x++){
		int prv1 = lower_bound(v.begin(), v.end(), (ans-k+1+m)) - v.begin();
		int prv2 = lower_bound(v.begin(), v.end(), (v[x]-k+1+m)) - v.begin();
		
		int cur1 = lower_bound(v.begin(), v.end(), ans+m) - v.begin();
		int cur2 = lower_bound(v.begin(), v.end(), v[x]+m) - v.begin();
		
		int cnt1 = query(cur1-1), cnt2 = query(cur2-1);
		cnt1 -= query(prv1-1);
		cnt2 -= query(prv2-1);
		
//		cout << prv2 << " " << cur2 << "\n";
		if(cnt2 < cnt1){
			ans = v[x];
		}
	}
	
	int prv = lower_bound(v.begin(), v.end(), ans-k+1+m) - v.begin();
	int cur = lower_bound(v.begin(), v.end(), ans+m) - v.begin();
	
	vector<int> remove;
	for(int x=prv;x<cur;x++){
		for(auto idx : w[x]) remove.push_back(idx);
	}
	
	cout << remove.size() << " " << ans << "\n";
	for(int x=0;x<remove.size();x++){
		if(x > 0) cout << " ";
		cout << remove[x]+1;
	}
	cout << "\n";
	
    return 0;
}

