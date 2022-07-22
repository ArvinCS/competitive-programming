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

int ask(int x, int y){
	cout << "? " << x+1 << " " << y+1 << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	int n;
	cin >> n;
	
	int tmp1 = ask(0, 1), tmp2 = ask(1, 2), tmp3 = ask(0, 2);
	
	int ans[n];
	ans[1] = (tmp1+tmp2-tmp3)/2;
	ans[0] = tmp1-ans[1];
	ans[2] = tmp2-ans[1];
	
	for(int x=2;x+1<n;x++){
		ans[x+1] = ask(x, x+1) - ans[x];
	}
	
	cout << "!";
	for(int x=0;x<n;x++){
		cout << " " << ans[x];
	}
	cout << endl;
    return 0;
}

