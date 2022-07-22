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
//	freopen("traffic_control_input.txt","r",stdin);
//	freopen("traffic_control_output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		
		int ans[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				ans[x][y] = 1;
			}
		}
		
		int total = n+m-2;
		ans[n-1][0] = b-total;
		ans[n-1][m-1] = a-total;
		
		bool possible = true;
		if(b-total < 1 || a-total < 1 || b-total > 1000 || a-total > 1000){
			possible = false;
		}
		
		cout << "Case #" << i << ": "; 
		if(possible){
			cout << "Possible\n";
			
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					if(y > 0) cout << " ";
					cout << ans[x][y];
				}	
				cout << "\n";
			}
		} else {
			cout << "Impossible\n";
		}
	}

    return 0;
}

