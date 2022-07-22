#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int r, c;
	cin >> r >> c;
	
	int a[2][2];
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++){
			cin >> a[x][y];
		}
	}	
	
	cout << a[r-1][c-1] << "\n";
    return 0;
}

