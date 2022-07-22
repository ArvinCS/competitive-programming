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

int parrent[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]) swap(a, b);
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int t[n];
	for(int x=0;x<n;x++){
		cin >> t[x];
		t[x]--;
	}
	
	for(int x=0;x<m;x++){
		parrent[x] = x;
		sz[x] = 0;
	}
	
	vector<int> v[m];
	int ans = 0; // sum of components
	for(int x=n-1;x>=0;x--){
		v[t[x]].push_back(x);
		sz[t[x]]++;
	}
	
	for(int x=0;x<m;x++){
		for(int y=0;y+1<v[x].size();y++){
			if(v[x][y] != v[x][y+1]+1){
				ans++;
			}
		}
		ans++;
	}
	
	cout << ans-1 << "\n";
	for(int x=0;x<m-1;x++){ // O(M log N)
		int a, b;
		cin >> a >> b;
		
		a = getParrent(a-1);
		b = getParrent(b-1);
		
		if(sz[a] < sz[b]) swap(a, b);
		
		for(int y=0;y<v[b].size();y++){
			if(v[b][y]-1 >= 0 && t[v[b][y]-1] == a){
				ans--;
			}
			if(v[b][y]+1 < n && t[v[b][y]+1] == a){
				ans--;
			}
		}
		for(int y=0;y<v[b].size();y++){
			v[a].push_back(v[b][y]);
			t[v[b][y]] = a;
		}
		
		merge(a, b);
		
//		cout << a << " " << b << " -> " << ans-1 << "\n";
		cout << ans-1 << "\n";
	}
    return 0;
}

