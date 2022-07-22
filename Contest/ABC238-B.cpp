#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	bool d[360];
	fill(d, d+360, false);
	
	int cur = 0;
	d[cur] = true;
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		cur += val;
		cur %= 360;
		
		d[cur] = true;
	}
	
	int last = 0, mx = 0;
	for(int x=1;x<=360;x++){
		if(d[x%360]){
			mx = max(mx, x-last);
			last = x;
		}
	}
	
	cout << mx << "\n";
    return 0;
}

