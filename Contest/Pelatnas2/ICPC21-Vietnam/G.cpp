#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		if(a[x] == 1) a[x] = 0;
	}
	
	sort(a, a+n);
	
	for(int x=1;x<n;x++){
		a[x] += a[x-1];
	}
	
	cout << (k > 0 ? a[k-1] : 0) << " " << (n > 0 ? a[n-1]-(n-1-k >= 0 ? a[n-1-k] : 0) : 0) << "\n";
	return 0;
}
