#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	assert(n == 1);
	
	cout << a[0] << " " << a[0]*(a[0]-1)/2 << "\n";
	
    return 0;
}

