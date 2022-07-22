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
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int ans = 0;
		for(int x=0;x<n-1;x++){			
			int min = x;
			for(int y=x+1;y<n;y++){
				if(data[y] < data[min]){
					min = y;
				}
			}
			reverse(data+x, data+min+1);
			ans += min-x+1;
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

