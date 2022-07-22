#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		ll n;
		cin >> n;
		
		ll a = n;
		ll b = n+1;
		
		if(a&1) b >>= 1;
		else a >>= 1;
		
		cout << "Case #" << i << ": " << a*b << "\n";
	}

    return 0;
}

