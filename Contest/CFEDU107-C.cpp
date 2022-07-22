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

int data[maxN], color[55];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, q;
	cin >> n >> q;
	
	fill(color, color+55, inf_int);
	for(int x=0;x<n;x++){
		cin >> data[x];
		color[data[x]] = min(color[data[x]], x+1);
	}
	
	for(int x=0;x<q;x++){
		int t;
		cin >> t;
		
		int ans = color[t];
		for(int y=1;y<=50;y++){
			if(color[y] < ans){
				color[y]++;
			}
		}
		color[t] = 1;
		
		if(x > 0) cout << " ";
		cout << ans;
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

