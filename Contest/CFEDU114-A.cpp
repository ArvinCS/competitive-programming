#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int cnt = 0;

void solve(int idx, int n, int cur, int use, string s){
	if(cnt >= n) return;
	if(idx == 2*n){
		if(cur == 0){
			cout << s << "\n";
			cnt++;
		}
		return;
	}
	
	if(use > 0){
		s.push_back('(');
		solve(idx+1, n, cur+1, use-1, s);
		s.pop_back();
	}
	if(cur > 0){
		s.push_back(')');
		solve(idx+1, n, cur-1, use, s);
		s.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cnt = 0;
		solve(0, n, 0, n, "");
	}
	
    return 0;
}

