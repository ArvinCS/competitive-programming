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
		int a, b, c;
		cin >> a >> b >> c;
		
		int ans = inf_int;
		tuple<int, int, int> t;
		for(int x=1;x<=10000;x++){
			for(int y=1;y*x<=20000;y++){
				for(int z=1;x*y*z<=40000;z++){
					int cnt = abs(a-x) + abs(b-x*y) + abs(c-x*y*z);
					if(cnt < ans){
						ans = cnt;
						t = make_tuple(x, x*y, x*y*z);
					}
				}
			}
		}
		
		cout << ans << "\n";
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
	}

    return 0;
}

