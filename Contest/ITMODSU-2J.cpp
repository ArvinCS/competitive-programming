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

int parrent[maxN], sz[maxN], length[maxN];

pair<int, int> getParrent(int x){
	if(parrent[x] == x) return {x, 0};
	pair<int, int> p = getParrent(parrent[x]);
	parrent[x] = p.first;
	length[x] += p.second;
	
	return {parrent[x], length[x]%2};
}

void merge(int x, int y){
	pair<int, int> a = getParrent(x);
	pair<int, int> b = getParrent(y);
	
	if(a.first != b.first){
		if(sz[a.first] < sz[b.first]){
			swap(a, b);
		}
		
		parrent[b.first] = a.first;
		length[b.first] = (b.second + 1 + a.second) % 2;
		sz[a.first] += sz[b.first];
	}
}

bool check(int x, int y){
	return getParrent(x).second == getParrent(y).second;
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
		parrent[x] = x;
		sz[x] = 1;
		length[x] = 0;
	}
	
	int p1 = -1, p2 = -1;
	for(int x=1;x<=m;x++){
		int a, b;
		cin >> a >> b;
		
		merge(a, b);
		
		if(x == 1){
			p1 = a;
			p2 = b;
			continue;
		}
		
		if(check(a, b)){
			cout << x << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

