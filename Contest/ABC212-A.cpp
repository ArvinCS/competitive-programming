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

	int a, b;
	cin >> a >> b;
	
	if(a > 0 && b == 0){
		cout << "Gold\n";
	} else if(a == 0 && b > 0){
		cout << "Silver\n";
	} else {
		cout << "Alloy\n";
	}

    return 0;
}

