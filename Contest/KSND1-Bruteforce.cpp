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

int n, m, k;

int solve(int idx, string s){
	if(idx == n){
		int cnt = 0;
		for(int x=0;x+m-1<n;x++){
			bool same = true;
			for(int y=x+1;y<x+m;y++){
				if(s[y-1] != s[y]) same = false;
			}
			
			if(same) cnt++;
		}
		return (cnt == k);
	}
	
	s.push_back('a');
	int a = solve(idx+1, s);
	s.pop_back();
	
	s.push_back('b');
	int b = solve(idx+1, s);
	s.pop_back();
	
	return a+b;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m >> k;	
	
	string s;
	cout << solve(0, s) << "\n";
    return 0;
}

