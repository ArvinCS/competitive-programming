#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 15;

ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	table[0] = table[1] = 1;
	for(int x=2;x<maxN;x++){
		table[x] = (x * table[x-1]);
	}
	
	int n;
	cin >> n;
	
	int sz = pow(2, n);
	double ans = 0;
	for(int x=0;x<=n;x++){
		double val = x;
		for(int y=1;y<=x;y++){
			val *= 1.0 / 6;
		}
		for(int y=1;y<=n-x;y++){
			val *= 5.0 / 6;
		}
		ans += val;
	}
	
	cout << fixed << ans << "\n";
    return 0;
}

