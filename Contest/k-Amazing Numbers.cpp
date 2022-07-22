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
		int n;
		cin >> n;
		
		int jarak[n+1], last[n+1];
		
		for(int x=0;x<=n;x++) jarak[x] = last[x] = 0;
		
		for(int x=1;x<=n;x++){
			int tmp;
			cin >> tmp;
			jarak[tmp] = max(jarak[tmp], x-last[tmp]);
			last[tmp] = x;
		}
		
		int ans[n+1];
		fill(ans, ans+n+1, -1);
		
		for(int x=1;x<=n;x++){
			jarak[x] = max(jarak[x], n-last[x]+1);
			for(int k=jarak[x];k<=n;k++){
				if(ans[k] != -1) break;
				ans[k] = x;
			}
		}
		
		for(int x=1;x<=n;x++){
			if(x > 1) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
    return 0;
}

