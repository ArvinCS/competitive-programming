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

const int maxN = 2 * 1e5 + 10;

int l[maxN], r[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	string s, t;
	cin >> s >> t;
	
	int i = 0;
	for(int x=0;x<m;x++){
		while(i+1 < n && t[x] != s[i]) i++;
		l[x] = i++;
	}
	
	i = n-1;
	for(int x=m-1;x>=0;x--){
		while(i > 0 && t[x] != s[i]) i--;
		r[x] = i--;
	}
	
	int best = 0;
	for(int x=0;x<m-1;x++){
		best = max(best, r[x+1] - l[x]);
	}
	cout << best << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

