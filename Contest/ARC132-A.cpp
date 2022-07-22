#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int pos[n], pos2[n];
	int r[n], c[n];
	for(int x=0;x<n;x++){
		cin >> r[x];
		r[x]--;
		
		pos[r[x]] = x;
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
		c[x]--;
		
		pos2[c[x]] = x;
	}
	
	
	int q;
	cin >> q;
	
	while(q--){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(c[b] >= n-1-r[a] && r[a] >= n-1-c[b]){
			cout << "#";
		} else {
			cout << ".";
		}
	}
	cout << "\n";
    return 0;
}

