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

	int n, k;
	cin >> n >> k;
	
	int ans = 0;
	for(int x=0;x<pow(2,k);x++){
		for(int y=0;y<pow(2,k);y++){
			for(int z=0;z<pow(2, k);z++){
				if((x&y&z) >= (x^y^z)){
					cout << x << " " << y << " " << z << " -> " << (x&y&z) << " " << (x^y^z) << "\n";
					ans++;
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

