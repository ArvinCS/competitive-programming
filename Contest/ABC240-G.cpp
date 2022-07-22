#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll x, y, z;
	cin >> x >> y >> z;
	
	ll sum = abs(x)+abs(y)+abs(z);
	
	if(sum < n-1){
		cout << "0\n";
		return 0;
	}
	
	
    return 0;
}

