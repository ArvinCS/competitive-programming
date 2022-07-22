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

int parrent[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	parrent[getParrent(y)] = getParrent(x);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<=n;x++) parrent[x] = x;
	
	while(m--){
		string t;
		int a, b;
		cin >> t >> a >> b;
		
		if(t == "union"){
			merge(a, b);
		} else {
			if(getParrent(a) == getParrent(b)){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar
