#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll k, s, n;
	cin >> k >> s >> n;
	
	if(k == 0 && s == 0){
		cout << "1\n";
		return 0;
	}
	if(s == 0){
		cout << n+1 << "\n";
		return 0;
	}
	if(k == 0){
		cout << n*(n-1)/2 + 1 << "\n";
		return 0;
	}
	
	ll sz = n*(n-1)/2 * s + n*k;
	
	int table[n+1][sz+1];
	fill(table[0], table[n+1], 0);
	
	table[0][0] = 1;
	for(int x=0;x<n;x++){
		for(int y=0;y<=sz;y++){
			if(y+(x+1)*s+k <= sz) table[x+1][y+(x+1)*s+k] += table[x][y];
			table[x+1][y] += table[x][y];
		}
	}
	
	set<ll> st;
	for(int y=0;y<=sz;y++){
		if(table[n][y]){
			st.insert(y-(sz-y));
		}
	}
	cout << st.size() << "\n";
    return 0;
}

