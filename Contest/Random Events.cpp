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

const int maxN = 1e5 + 5;

int data[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++) cin >> data[x];
		
		int pos = -1;
		for(int x=0;x<n;x++){
			if(data[x] != x+1){
				pos = x+1;
			}
		}
		
		double ans = (pos <= 0);
		for(int i=0;i<m;i++){
			int r;
			double p;
			cin >> r >> p;
			
			if(r >= pos){
				ans = max(ans+p-(ans*p), 0.0);
			}
		}
		
		cout << fixed << setprecision(6) << ans << "\n";
	}
	
    return 0;
}

