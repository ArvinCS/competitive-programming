#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	cout << max(0ll, min(9ll, (n-9)/10ll)) << "\n";
    return 0;
}

