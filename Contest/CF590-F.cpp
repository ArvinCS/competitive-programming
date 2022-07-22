#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxBit = (1 << 20);

int table[maxBit];
bool exist[maxBit];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	fill(exist, exist+maxBit, false);
	
	for(int x=0;x<s.length();x++){
		for(int y=x, state=0;y>=max(0, x-19);y--){
			int idx = (s[y] - 'a');
			
			if(state&(1 << idx)){
				break;
			}
			
			state |= (1 << idx);
			
			exist[state] = true;
		}
	}
	
	fill(table, table+maxBit, 0);
	
	for(int x=0;x<maxBit;x++){
		if(exist[x]){
			table[x] = __builtin_popcount(x);
		}
	}
	for(int x=0;x<20;x++){
		for(int state=0;state<maxBit;state++){
			if(state&(1 << x)){
				cout << state << " -> " << (state^(1 << x)) << "\n";
				table[state] = max(table[state], table[state^(1 << x)]);
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<maxBit;x++){
		if(exist[x]){
			ans = max(ans, __builtin_popcount(x)+table[(maxBit-1)^x]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

