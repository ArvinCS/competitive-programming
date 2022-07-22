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

int n, m;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	string data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll a = 0, b = 0;
	for(int x=0;x<n;x++){
		int cnt = 0;
		for(int y=0;y<m;y++){
			if(data[x][y] == '1') cnt++;
		}
		if(cnt&1) a++;
		else b++;
	}
	
	cout << a*b << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

