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
	
	string s;
	cin >> s;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			int ans = n-max(x,y);
			for(int i=0;max(x,y)+i<n;i++){
				if(s[x+i] != s[y+i]){
					ans = i;
					break;
				}
			}
			
			cout << ans << " ";
		}
		cout << "\n";
	}

    return 0;
}

