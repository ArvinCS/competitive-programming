#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int ans = 0;
	for(int a=1;a<n;a++){
		for(int b=a;a*1ll*b<n;b++){
			int c = n-(a*1ll*b);
			if(c > 0){
//				cout << a << " * " << b << " + " << c << "\n";
				if(a == b) ans++;
				else ans += 2;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

