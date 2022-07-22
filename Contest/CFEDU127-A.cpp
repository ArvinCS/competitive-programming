#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 55;

bool valid[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(valid, valid+maxN, false);
	
	valid[0] = true;
	for(int x=0;x<maxN;x++){
		for(int y=x;y<maxN;y++){
			if((y-x) % 2 == 0 || (y-x) % 3 == 0){
				valid[y] |= valid[x];
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		bool possible = true;
		int last = 0;
		for(int x=0;x<s.length();x++){
			if(s[x] != s[last]){
				possible &= valid[x-last];
				last = x;
			}
		}
		possible &= valid[s.length()-last];
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

