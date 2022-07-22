#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w;
	cin >> h >> w;
	
	int r, c;
	cin >> r >> c;
	
	int ans = 0;
	if(r > 1) ans++;
	if(r < h) ans++;
	if(c > 1) ans++;
	if(c < w) ans++;
	
	cout << ans << "\n";
	
    return 0;
}

