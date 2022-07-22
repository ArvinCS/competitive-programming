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

const int maxN = 1e6 + 5;

ll cnt[maxN][3];
ll n, r1, r2, r3, d;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> r1 >> r2 >> r3 >> d;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<n;x++){
		cnt[x][0] = r1+r2;
		cnt[x][1] = (a[x]+2)*r1;
		cnt[x][2] = a[x]*r1 + r3;
	}
	
	ll table[n+1];
	table[n] = 0;
	table[n-1] = a[n-1]*r1 + r3;
	for(int x=n-2;x>=0;x--){
		table[x] = cnt[x][2] + d + table[x+1];
				
		for(int i=0;i<3;i++){
			table[x] = min(table[x], cnt[x][i] + 3*d + table[x+1] + (x+2 >= n ? -d : 0));
		}
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				table[x] = min(table[x], cnt[x][i]+cnt[x+1][j]+4*d+table[x+2]+(x+2 >= n ? -d : 0));
			}
		}
		
		if(x+3 <= n){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int k=0;k<3;k++){
						table[x] = min(table[x], cnt[x][i]+cnt[x+1][j]+cnt[x+2][k]+7*d+table[x+3]+(x+3 >= n-1 ? -d : 0));
					}
				}
			}
		}
	}
	
	cout << table[0] << "\n";
    return 0;
}

