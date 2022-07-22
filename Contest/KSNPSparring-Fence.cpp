#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
		if(x > 0) h[x] += h[x-1];
	}
	
	int ans = -1, sum = 1e9;
	for(int x=0;x+k<=n;x++){
		int val = h[x+k-1] - (x > 0 ? h[x-1] : 0);
		if(sum > val){
			sum = val;
			ans = x;
		}
	}
	
	cout << ans+1 << "\n";
    return 0;
}

