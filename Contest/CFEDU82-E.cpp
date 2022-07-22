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

const int maxN = 405;

bool table[2][maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		string a, b;
		cin >> a >> b;
		
		int n = a.length(), m = b.length();
		
		if(m > n){
			cout << "NO\n";
			continue;
		}
		
		bool possible = false;
		for(int x=0;x<m;x++){
			fill(*table[0], *table[2], false);
			
			table[0][0][0] = true;
			for(int y=0;y<n;y++){
				for(int l=0;l<=min(x+1, y);l++){
					for(int r=max(0, y-l+m-n);r<=y-l;r++){
						int s = y-l-r;
						
						if(table[y&1][l][r]){
							if(x+r+1 < n && a[y] == b[x+r+1]){
								table[(y+1)&1][l][r+1] = true;
							}
							if(l < n && a[y] == b[l]){
								table[(y+1)&1][l+1][r] = true;
							}
							table[(y+1)&1][l][r] = true;
						}
					}
				}
			}
			
			if(table[n&1][x+1][m-x-1]){
				possible = true;
				break;
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

