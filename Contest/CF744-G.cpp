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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int table[2005];
		fill(table, table+2005, inf_int);
		
		table[0] = 0;
		for(int x=0;x<n;x++){
			int new_table[2005];
			fill(new_table, new_table+2005, inf_int);
			
			for(int y=0;y<=2000;y++){
				if(table[y] == inf_int) continue;
				
				if(a[x] > y){
					new_table[a[x]-y+table[y]] = min(new_table[a[x]-y+table[y]], a[x]-y+table[y]); // telan Y
//					cout << a[x]-y+table[y] << " " << y << " --\n";
					if(a[x]+y <= 2000) new_table[a[x]+y] = min(new_table[a[x]+y], a[x]+y); // tambah Y
				} else {
					if(y+a[x] <= 2000) new_table[a[x]+y] = min(new_table[a[x]+y], max(table[y], a[x]+y)); // tambah Y
					
					new_table[max(table[y]-(y-a[x]), y-a[x])] = min(new_table[max(table[y]-(y-a[x]), y-a[x])], table[y]);
//					cout << max(table[y]-(y-a[x]), y-a[x]) << " " << y << "\n";
				}
			}
			
			swap(table, new_table);
			
//			for(int y=0;y<=15;y++){
//				cout << table[y] << " ";
//			}
//			cout << "\n";
		}
		
		int ans = inf_int;
		for(int x=0;x<=2000;x++){
			ans = min(ans, table[x]);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

