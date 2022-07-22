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

int table[105][2];

bool solve(int cnt, bool filco){
	if(table[cnt][filco] != -1) return table[cnt][filco];
	if(cnt == 0){
		return !filco;
	}
	
	if(filco){
		bool ans = solve(cnt-1, !filco);
		
		if(cnt >= 3){
			ans |= solve(cnt-2, !filco);
		}
		return table[cnt][filco] = ans;
	} else {
		bool ans = solve(cnt-1, !filco);
		
		if(cnt >= 3){
			ans &= solve(cnt-2, !filco);
		}
		return table[cnt][filco] = ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(table[0], table[105], -1);
	
	string s;
	cin >> s;
	
	int cnt = 1;
	for(int x=1;x<s.length();x++){
		if(s[x-1] != s[x]){
			cnt++;
		}
	}
	
	cout << (solve(cnt, true) ? "Filco" : "Riberto") << "\n";
    return 0;
}

