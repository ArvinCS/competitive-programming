#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

void madd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int mx = 2*n;
		ll table[mx+1], new_table[mx+1];
		fill(table, table+mx+1, 0);
		
		int cnt = 0;
		table[n] = 1;
		for(int x=0;x<n;x++){
			if(x > 0 && a[x-1] == a[x]) continue;
			
			fill(new_table, new_table+mx+1, 0);
			
			for(int y=0;y<=mx;y++){
				int rem = y+x-1-n;
				
				// 0 = y+(n-1)-n
				// y = 1
				if(rem >= 0){
					if(rem > 0){
						assert(y-1 >= 0);
						madd(new_table[y+(x-1)-x], table[y]);
					}
					madd(new_table[y], table[y]);
				}
			}
			
			for(int y=0;y<=mx;y++){
				cout << x << " " << y << " -> " << new_table[y] << "\n";
				table[y] = new_table[y];
			}
		}
		
		cout << table[1] << "\n";
	}
	
    return 0;
}

