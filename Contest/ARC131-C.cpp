#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int sum = 0;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum ^= a[x];
	}
	
	for(int x=0;x<n;x++){
		if(a[x] == sum){
			cout << "Win\n";
			return 0;
		}
	}
	
	if(n&1){
		cout << "Win\n";
	} else {
		cout << "Lose\n";
	}
    return 0;
}

