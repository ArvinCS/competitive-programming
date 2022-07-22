#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll mn = -pow(2ll, 31);
	ll mx = pow(2ll, 31)-1;
	
	if(mn <= n && n <= mx){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

