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

int parrent[maxN][2], sz[maxN][2];

int getParrent(int x, int id){
	if(parrent[x][id] == x) return x;
	return parrent[x][id] = getParrent(parrent[x][id], id);
}

void merge(int x, int y, int id){
	int a = getParrent(x, id);
	int b = getParrent(y, id);
	
	if(a != b){
		if(sz[a][id] < sz[b][id]){
			swap(a, b);
		}
		
		parrent[b][id] = a;
		sz[a][id] += sz[b][id];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, p, q;
	cin >> n >> p >> q;
	
	set<int> st;
	for(int x=0;x<n;x++){
		parrent[x][0] = parrent[x][1] = x;
		sz[x][0] = sz[x][1] = 1;
		st.insert(x);
	}
	
	for(int x=0;x<p;x++){
		int a, b;
		cin >> a >> b;
		
		merge(a-1, b-1, 0);
		st.erase(b-1);
	}
	
	for(int x=0;x<q;x++){
		int a, b;
		cin >> a >> b;
		
		merge(a-1, b-1, 1);
	}
	
	vector<pair<int, int>> ans;
	for(int x=0;x<n;x++){
		vector<int> v;
		for(auto y : st){
			if(getParrent(x, 0) != getParrent(y, 0) && getParrent(x, 1) != getParrent(y, 1)){
				merge(x, y, 0);
				merge(x, y, 1);
				ans.push_back({x, y});
				
				v.push_back(y);
			}
		}
		for(auto y : v) st.erase(y);
	}
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}
    return 0;
}

