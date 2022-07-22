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
	
	int grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];
		}
	}
	
	int a[n], b[n], need[n][n];
	for(int x=0;x<n;x++){
		a[x] = inf_int;
		b[x] = 0;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			a[x] = min(a[x], grid[x][y]);
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			need[x][y] = (grid[x][y] - a[x]);
		}
	}
	
	for(int y=0;y<n;y++){
		bool valid = true;
		for(int x=0;x<n;x++){
			if(need[x][y] != need[0][y]){
				valid = false;
				break;
			}
		}
		
		if(valid){
			b[y] = need[0][y];	
		} else {
			cout << "No\n";
			return 0;
		}
	}
	
	cout << "Yes\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << a[x];
	}
	cout << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << b[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

