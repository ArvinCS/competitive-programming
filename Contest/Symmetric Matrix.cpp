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
		short n, m;
		cin >> n >> m;
		
		short type[n][4];
		for(short x=0;x<n;x++){
			cin >> type[x][0] >> type[x][1] >> type[x][2] >> type[x][3];
		}
		
		if(m % 2 == 1){
			cout << "NO\n";
		} else {
			bool possible = false;
			for(short x=0;x<n;x++){
				if(type[x][1] == type[x][2]){
					possible = true;
					break;
				}
			}
			if(possible) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
    return 0;
}

