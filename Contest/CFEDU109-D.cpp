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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	vector<int> v, w;
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		if(data[x] == 1) v.push_back(x);
		else w.push_back(x);
	}
	
	if(v.size() == 0){
		cout << "0\n";
		return 0;
	}
	
	int table[n][n];
	fill(table[0], table[n], inf_int);
	
	for(int x=0;x<w.size();x++){
		table[x][0] = abs(w[x]-v[0]);
	}
	for(int x=1;x<v.size();x++){
		int mn = table[x-1][x-1];
		for(int y=x;y<w.size();y++){
			table[y][x] = abs(w[y]-v[x]) + mn;
			mn = min(mn, table[y][x-1]);
		}
	}
	
	int ans = inf_int;
	for(int x=0;x<w.size();x++){
		ans = min(table[x][v.size()-1], ans);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

