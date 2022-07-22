#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	ll sum = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
	}
	
	bool possible = true;
	if(a[n-1] > (sum+1)/2){
		possible = false;
	}
	for(int x=n-2;x>=0;x--){
		if(a[x] > sum/2){
			possible = false;
			break;
		}
	}
	
	cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}

