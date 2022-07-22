#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int table[26][2];
		fill(table[0], table[26], -1e9);
		
		int n = s.length();
		int prv = 0;
		for(int x=0;x<n;x++){
			int idx = (s[x] - 'a');
			table[idx][0] = max(table[idx][0], table[idx][1]+1);
			table[idx][1] = max(table[idx][1], prv+1);
			prv = max(prv, table[idx][0]);
		}
		
		cout << n-prv << "\n";
	}
	
    return 0;
}

