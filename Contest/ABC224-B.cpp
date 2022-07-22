#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	bool ok = true;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			for(int i=x+1;i<n;i++){
				for(int j=y+1;j<m;j++){
					if(a[x][y] + a[i][j] > a[i][y] + a[x][j]){
						ok = false;
					}
				}
			}
		}
	}
	
	if(ok){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

