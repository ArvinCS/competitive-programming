#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n;
	cin >> n;
	
	ll sum = 0;
	for(int i=0;i<=n;i++){
		sum += (1ll << (i+1))-1;
	}
	
	cout << sum << "\n";
	return 0;
}
