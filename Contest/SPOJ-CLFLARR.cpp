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

int parrent[maxN], color[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<=n;x++){
		color[x] = 0;
		parrent[x] = x;
	}

	tuple<int, int, int> qr[q];
	for(int x=0;x<q;x++){
		int l, r, c;
		cin >> l >> r >> c;
		
		l--; r--;
		qr[x] = make_tuple(l, r, c);
	}
	
	for(int x=q-1;x>=0;x--){
		int l = get<0>(qr[x]), r = get<1>(qr[x]), c = get<2>(qr[x]);
		
		for(int y=getParrent(l); y<=r; y=getParrent(y)){
			color[y] = c;
			parrent[y] = y+1;
		}
	}
	
	for(int x=0;x<n;x++) cout << color[x] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

