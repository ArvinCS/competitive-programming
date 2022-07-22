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

int query(int pos){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans += tree[pos];
		pos -= pos&(-pos);
	}
	return ans;
}

void update(int pos, int val){
	pos++;
	
	while(pos < maxN){
		tree[pos] += val;
		pos += pos&(-pos);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(tree, tree+maxN, 0);
	
	int n, m;
	cin >> n >> m;
	
	vector<tuple<int, int, int>> v;
	int left[m];
	for(int x=0;x<m;x++){
		int l, r, val;
		cin >> l >> r >> val;
		
		left[x] = l;
		v.push_back(make_tuple(l, val, x));
		v.push_back(make_tuple(r+1, -val, x));
	}
	
	sort(v.begin(), v.end());
	
	int a[n+1];
	fill(a, a+n+1, 0);
	
	vector<int> w;
	int cur = 0;
	for(int x=0;x<v.size();x++){
		int pos = get<0>(v[x]);
		int val = get<1>(v[x]);
		int idx = get<2>(v[x]);
		
		while(cur < pos){
			w.push_back(cur);
			cur++;
		}
		
		if(val < 0){
			int remain = abs(val) - (query(pos) - query(left[idx]-1));
			
			while(remain > 0){
				a[w.back()] = 1;
				update(w.back(), 1);
				
				w.pop_back();
				remain--;
			}
		}
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << a[x];
	}
	cout << "\n";
    return 0;
}

