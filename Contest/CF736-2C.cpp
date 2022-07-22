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

	int n, m;
	cin >> n >> m;
	
	int less[n], great[n];
	for(int x=0;x<n;x++){
		less[x] = great[x] = 0;
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		if(a > b) swap(a, b);
		
		great[a]++;
		less[b]++;
	}
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(great[x] == 0){
			ans++;
		}
	}
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 3){
			cout << ans << "\n";
		} else {
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			
			if(a > b) swap(a, b);
			
			if(t == 1){
				if(great[a] == 0){
					ans--;
				}
				
				great[a]++;
				less[b]++;
			} else {
				great[a]--;
				less[b]--;
				
				if(great[a] == 0){
					ans++;
				}
			}
		}
	}
    return 0;
}

