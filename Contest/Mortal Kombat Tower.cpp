#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ui n;
		cin >> n;
		
		us data[n];
		for(ui x=0;x<n;x++) cin >> data[x];
		
		int table[n+1][2];
		fill(table[0], table[n+1], inf_int);
		
		table[0][1] = 0;
//		table[n][1] = table[n][0] = 0;
		for(int i=0;i<n;i++){
			for(us u=0;u<2;u++){
				for(us kill=1;kill<=min(n-i,(ui) 2);kill++){
					us point = data[i] + (kill > 1 ? data[i+1] : 0);
//					table[i][u] = min(table[i][u], table[i+kill][!u] + u * point);
					table[i+kill][!u] = min(table[i+kill][!u], table[i][u] + u * point);
				}
			}
		}
//		
//		for(us x=0;x<=n;x++){
//			cout << table[x][0] << " " << table[x][1] << "\n";
//		}

		cout << min(table[n][0], table[n][1]) << "\n";
//		cout << table[0][1] << "\n";
	}
	
    return 0;
}

