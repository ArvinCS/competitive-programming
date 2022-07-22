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
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll left = 1, right = 1e11, ans = inf_ll;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll cyan = a+b*mid, red = c*mid;
		if((cyan+red-1)/red <= d){
			right = mid-1;
			ans = min(ans, mid);
		} else {
			left = mid+1;
		}
	}
	
	cout << (ans == inf_ll ? -1 : ans) << "\n";
    return 0;
}

