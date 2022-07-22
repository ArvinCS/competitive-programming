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
		
		int odd = 0, even = 0;
		for(int x=0;x<2*n;x++){
			int tmp;
			cin >> tmp;
			
			if(tmp&1) odd++;
			else even++;
		}
		
//		cout << even << " " << odd << "\n";
		if(even == odd){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}

