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

const int maxN = 30;

ll table[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	ll num[2*n];
	bool active[2*n];
	fill(active, active+2*n, true);
	
	num[2*n-1] = num[0] = 0; 
	num[1] = 1;
	for(int x=2;x<2*n-1;x++){
		num[x] = num[x-1]*2ll;
	}
	
	table[0][0] = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			table[x][y] = (num[x+y] * active[x+y]);
			active[x+y] = !active[x+y];
			
			if(y > 0) cout << " ";
			cout << table[x][y];
		}
		cout << endl;
	}
	
	int q;
	cin >> q;
	
	for(int x=0;x<q;x++){
		ll sum;
		cin >> sum;
		
		pair<int, int> cur = {0, 0};
		cout << "1 1" << endl;
		while(cur.first != n-1 || cur.second != n-1){
			if(num[cur.first+cur.second+1]&sum){
				if(cur.first+1 < n && table[cur.first+1][cur.second] != 0){
					cur.first++;
				} else {
					cur.second++;
				}
			} else {
				if(cur.first+1 < n && table[cur.first+1][cur.second] == 0){
					cur.first++;
				} else {
					cur.second++;
				}
			}
			cout << cur.first+1 << " " << cur.second+1 << endl;
		}
	}
    return 0;
}

