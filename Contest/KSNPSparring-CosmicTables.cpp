#include <bits/stdc++.h>

#define ll long long

using namespace std;

int p[1005][1005];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> p[x][y];
		}
	}
	
	int row[n], col[m];
	for(int x=0;x<n;x++){
		row[x] = x;
	}
	for(int x=0;x<m;x++){
		col[x] = x;
	}
	
	for(int i=1;i<=k;i++){
		char t;
		int a, b;
		cin >> t >> a >> b;
		
		a--; b--;
		if(t == 'c'){
			swap(col[a], col[b]);
		} else if(t == 'r'){
			swap(row[a], row[b]);
		} else {
			cout << p[row[a]][col[b]] << "\n";
		}
	}
    return 0;
}

