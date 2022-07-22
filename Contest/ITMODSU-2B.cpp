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

int parrent[maxN];

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

	int n;
	cin >> n;
	
	for(int x=0;x<=n;x++){
		parrent[x] = x;
	}
	
	for(int x=0;x<n;x++){
		int m;
		cin >> m;
		
		m--;
		int tmp = getParrent(m);
		tmp %= n;
		
		if(x > 0) cout << " ";
		cout << tmp + 1;
		
		parrent[tmp] = getParrent((tmp+1)%n);
	}
	cout << "\n";

    return 0;
}

// Santai
// Pikirin dengan benar-benar

