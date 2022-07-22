#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n, m;

ui solve(us a, us b){
	if(a == n && b == m) return 1;
	
	ui ans = 0;
	if(a + 1 <= n) ans += solve(a+1, b);
	if(b + 1 <= m) ans += solve(a, b+1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	cout << solve(1,1) << "\n";
	
    return 0;
}

