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

const int maxN = 3e5 + 5;

int parrent[maxN], mn[maxN], mx[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a == b) return;
	if(sz[a] < sz[b]){
		swap(a, b);
	}
	
	parrent[b] = a;	
	sz[a] += sz[b];
	mn[a] = min(mn[a], mn[b]);
	mx[a] = max(mx[a], mx[b]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<=n;x++){
		parrent[x] = mn[x] = mx[x] = x;
		sz[x] = 1;
	}
	
	while(m--){
		string t;
		int a;
		cin >> t >> a;
		
		if(t == "union"){
			int b;
			cin >> b;
			
			merge(a, b);
		} else {
			cout << mn[getParrent(a)] << " " << mx[getParrent(a)] << " " << sz[getParrent(a)] << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

