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

const int maxN = 305;

int tree[maxN][maxN];

int query(int row, int pos){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans += tree[row][pos];
		pos -= pos&(-pos);
	}
	return ans;
}

void update(int row, int pos, int val){
	pos++;
	
	while(pos < maxN){
		tree[row][pos] += val;
		pos += pos&(-pos);
	}
}

bool customSort(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		map<int, int> mp;
		vector<int> v;
		int a[n*m];
		for(int x=0;x<n*m;x++){
			cin >> a[x];
			v.push_back(a[x]);
		}
		
		v.erase(unique(v.begin(), v.end()), v.end());
		
		sort(v.begin(), v.end());
		
		for(int x=0;x<v.size();x++){
			mp[v[x]] = x;
		}
		for(int x=0;x<n*m;x++){
			a[x] = mp[a[x]];
		}
		
		ll ans = 0;
		int prefix[n*m], cnt[n*m];
		fill(prefix, prefix+n*m, 0);
		
		for(int x=0;x<n*m;x++){
			prefix[a[x]]++;
			cnt[x] = 0;
		}
		for(int x=1;x<n*m;x++){
			prefix[x] += prefix[x-1];
		}
		
		fill(tree[0], tree[n], 0);
		
		vector<pair<int, int>> w[n*m];
		for(int x=0;x<n*m;x++){
			int pos = (a[x] > 0 ? prefix[a[x]-1] : 0) + cnt[a[x]];
			w[a[x]].push_back({pos/m, pos%m});
			cnt[a[x]]++;
		}
		for(int x=0;x<n*m;x++){
			sort(w[x].begin(), w[x].end(), customSort);
		}
		
		for(int x=0;x<n*m;x++){
			pair<int, int> p = w[a[x]].back();
			w[a[x]].pop_back();
			
//			cout << p.first << " " << p.second << "\n";
			ans += query(p.first, p.second-1);
			update(p.first, p.second, 1);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

