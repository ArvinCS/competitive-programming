#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

const int maxK = 22;
ll n, pw[maxK+1];
vector<ll> v;

bool solve(int idx, ll cur){
	if(idx > maxK){
		cur -= n;
		for(int x=maxK;x>=0;x--){
			if(cur >= pw[x]){
				cur -= pw[x];
			}
		}
		return (cur == 0);
	}
	
	return (solve(idx+1, cur) | solve(idx+1, cur+pw[idx]));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<=maxK;x++){
		pw[x] = (5 * pw[x-1]);
	}
	
	cin >> n;
	
	if(solve(0, 0)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

