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

const ll maxA = 2e7 + 5;

ll table[maxA];
int cnt[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(table, table+maxA, -1);
	
	for(int x=n-1;x>=0;x--){
		for(int y=1;y*1ll*y<=a[x];y++){
			if(a[x] % y == 0){
				cnt[y]++;
				
				if(a[x]/y != y){
					cnt[a[x]/y]++;
				}
			}
		}
	}
	
	for(int x=maxA-3;x>=1;x--){
		for(int y=2;y*x<maxA;y++){				
			if(table[y*x] != -1 && table[x] < table[x*y]+x*1ll*(cnt[x]-cnt[x*y])){
				table[x] = table[x*y]+x*1ll*(cnt[x]-cnt[x*y]);
			}
		}
		
		table[x] = max(table[x], x*1ll*cnt[x]);
	}
	
	cout << table[1] << "\n";
    return 0;
}

