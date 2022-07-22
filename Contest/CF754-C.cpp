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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int ans = inf_int;
		for(int x=0;x<n;x++){
			int a = 0, b = 0, c = 0;
			for(int y=x;y<min(n, x+12);y++){
				if(s[y] == 'a') a++;
				else if(s[y] == 'b') b++;
				else c++;
				
				if(x < y && a > max(b, c)){
					ans = min(ans, y-x+1);
				}
			}
		}
		
		cout << (ans == inf_int ? -1 : ans) << "\n";
	}
	
    return 0;
}

