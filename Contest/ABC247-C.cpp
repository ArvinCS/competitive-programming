#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = (1<<16)+5;

int ans[maxN];

void solve(int idx, int l, int r){
	if(l > r) return;
	
	int m = (l+r+1)>>1;
	
	ans[m] = idx;
	
	solve(idx-1, l, m-1);
	solve(idx-1, m+1, r);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int len = (1 << n)-1;
	solve(n, 1, len);
	
	for(int x=1;x<=len;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

