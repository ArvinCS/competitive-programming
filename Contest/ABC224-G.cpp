#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, s, t, a, b;
	cin >> n >> s >> t >> a >> b;
	
	if(s == t){
		cout << fixed << setprecision(6) << 0 << "\n";
	} else if(s < t){
		
	} else {
		cout << fixed << setprecision(6) << a*b << "\n";
	}
	
    return 0;
}

