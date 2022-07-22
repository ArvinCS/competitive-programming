#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 20;

int n, a[maxN][maxN];

int solve(int idx, int b, int state){
	if(idx == 2*n){
		return b;
	}
	if(state&(1 << idx)){
		return solve(idx+1, b, state);
	}
	
	int ans = 0;
	for(int x=idx+1;x<2*n;x++){
		if(!(state&(1 << x))){
			ans = max(ans, solve(idx+1, b^a[idx][x], state|(1 << x)));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(int x=0;x<2*n;x++){
		for(int y=x+1;y<2*n;y++){
			cin >> a[x][y];
		}
	}
	
	cout << solve(0, 0, 0) << "\n";
	
    return 0;
}

