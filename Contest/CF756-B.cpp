#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll a, b;
		cin >> a >> b;
		
		cout << min((a+b)/4, min(a, b)) << "\n";
	}
	return 0;
}

