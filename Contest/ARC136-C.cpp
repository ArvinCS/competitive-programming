#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n], mx = 0, sum = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		mx = max(mx, a[x]);
	}
	
	for(int x=0;x<n;x++){
		sum += abs(a[x]-a[(x+1)%n]);
	}
	
	cout << max(mx, sum/2) << "\n";
    return 0;
}

