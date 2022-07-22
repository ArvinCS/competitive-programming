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
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int ans = 0;
		while(!is_sorted(a, a+n)){
			for(int y=ans%2;y<n-1;y+=2){
				if(a[y] > a[y+1]){
					swap(a[y], a[y+1]);
				}
			}
			
			ans++;
		}
		
		cout << ans << "\n";
	}

    return 0;
}
