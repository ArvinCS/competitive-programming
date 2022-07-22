#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int lg = log2(max(n, m)-1)+1;
	int fullstate = (1 << lg);
	
	int table[fullstate+1];
	fill(table, table+fullstate+1, 0);
	
	for(int x=0;x<n;x++){
		table[fullstate-(n-x)] ^= a[x];
	}
	
	for(int x=0;x<lg;x++){
		int bit = (1 << x);
		for(int state=0;state<=fullstate;state++){
			if(state&bit){
				table[state^bit] ^= table[state];
			}
		}
	}
	
	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		cout << table[x];
	}
	cout << "\n";
    return 0;
}

