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

int parrent[maxN], length[maxN], sz[maxN];

pair<int, int> getParrent(int x){
	if(parrent[x] == x) return {x, 0};
	pair<int, int> p = getParrent(parrent[x]);
	parrent[x] = p.first;
	length[x] += p.second;
	
	return {parrent[x], length[x] % 2};	
}

void merge(int x, int y){
	pair<int, int> a = getParrent(x);
	pair<int, int> b = getParrent(y);
	
	if(a.first != b.first){
		if(sz[a.first] < sz[b.first]){
			swap(a, b);
		}		
		
		parrent[b.first] = a.first;
		sz[a.first] += sz[b.first];
		length[b.first] = (1 + b.second + a.second) % 2;
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
		length[x] = 0;
		sz[x] = 1;
	}
	
	int shift = 0;
	for(int x=0;x<m;x++){
		int t, a, b;
		cin >> t >> a >> b;
		
		a = (a + shift) % n;
		b = (b + shift) % n;
		
		if(t == 0){
			merge(a, b);
		} else {
			if(check(a, b)){
				cout << "YES\n";
				shift = (shift + 1) % n;
			} else {
				cout << "NO\n";
			}
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

