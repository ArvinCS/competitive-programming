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

const int maxN = 1e3 + 5;

int n, a[maxN], num[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		fill(num, num+maxN, 0);
		
		int depth = 0;
		for(int x=0;x<n;x++){
			while(depth > 0 && num[depth+1]+1 != a[x]){
				depth--;
			}
			
			num[depth+1] = a[x];
			string ans;
			for(int y=1;y<=depth+1;y++){
				if(y > 1) ans += '.';
				ans += to_string(num[y]);	
			}
			for(int y=depth+2;y<maxN;y++) num[y] = 0;
			depth++;
			
			cout << ans << "\n";
		}
	}

    return 0;
}

