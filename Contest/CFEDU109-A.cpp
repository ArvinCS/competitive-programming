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
		
		if(n == 100){
			cout << "1\n";
			continue;
		}
		
		int ans = inf_int;
		for(int a=1;a<=100;a++){
			for(int b=1;b<=100;b++){
				if((a*100) % (a+b) == 0 && (b*100) % (a+b) == 0){
					int tmp1 = (a*100)/(a+b), tmp2 = (b*100)/(a+b);
					
					if(tmp1 == n && tmp2 == (100-n)){
						ans = min(ans, a+b);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

