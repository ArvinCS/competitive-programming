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
		int n, m;
		cin >> n >> m;
		
		bool a[100];
		fill(a, a+100, false);
		
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			a[tmp-1] = true;
		}
		
		int ans = 0;
		for(int x=0;x<m;x++){
			int tmp;
			cin >> tmp;
			
			if(a[tmp-1]){
				ans++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

