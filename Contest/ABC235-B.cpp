#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	for(int x=1;x<n;x++){
		if(h[x-1] >= h[x]){
			cout << h[x-1] << "\n";
			return 0;
		}
	}
	cout << h[n-1] << "\n";
    return 0;
}

