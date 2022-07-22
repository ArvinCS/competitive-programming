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

int parrent[maxN], length[maxN];

pair<int, int> getParrent(int x){
	if(parrent[x] == x) return {x, length[x]};
	
	pair<int, int> p = getParrent(parrent[x]);
	length[x] = p.second+length[x];
	parrent[x] = p.first;
	return {parrent[x], length[x]};
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
	}
	
	for(int x=0;x<m;x++){
		int t, a;
		cin >> t >> a;
		
		if(t == 1){
			int b;
			cin >> b;
			
			parrent[a] = b;
			length[a] = (1 + length[a] + length[b]);
		} else {
			cout << getParrent(a).second << "\n";
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

