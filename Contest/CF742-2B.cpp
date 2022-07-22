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
		int a, b;
		cin >> a >> b;
		
		int res = 0;
		if((a-1)%4 == 0){
			res = a-1;
		} else if((a-1)%4 == 1){
			res = 1;
		} else if((a-1)%4 == 2){
			res = a;
		} else {
			res = 0;
		}
		
		if(res == b){
			cout << a << "\n";
		} else if((res^b) == a){
			cout << a+2 << "\n";
		} else {
			cout << a+1 << "\n";
		}
	}
	
    return 0;
}

