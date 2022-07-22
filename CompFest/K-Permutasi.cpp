#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n, k;

void solve(us s[], int i, bool inserted[11]){
	if(i == n){
		cout << s[0];
		for(us x=1;x<n;x++){
			cout << " " << s[x];
		}
		cout << "\n";
		return;
	}
	
	for(us x=1;x<=n;x++){
		if(inserted[x] || (i > 0 && abs(x-s[i-1]) > k)) continue;
		
		s[i] = x;
		inserted[x] = true;
		solve(s, i+1, inserted);
		inserted[x] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> k;
	
	us s[n];
	bool inserted[9];
	
	fill(begin(inserted), end(inserted), false);
	solve(s, 0, inserted);
	
    return 0;
}

