#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int n, m, h[100000];

void solve(){
	cin >> n >> m;
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	sort(h, h+n);
	int max = 0;
	for(int x=0;x<n;x++){
		if(m >= h[x]){
			max++;
			m -= h[x];
		}
	}
	cout << max << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	int cases, i = 1;
	cin >> cases;
	while(cases--){
		cout << "Case #" << i << ": ";
		solve();
		i++;
	}
    return 0;
}
