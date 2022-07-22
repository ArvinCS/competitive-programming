#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w;
	cin >> h >> w;
	
	int a[h][w];
	for(int x=0;x<h;x++){
		for(int y=0;y<w;y++){
			cin >> a[x][y];
		}
	}
	
	for(int y=0;y<w;y++){
		for(int x=0;x<h;x++){
			if(x > 0) cout << " ";
			cout << a[x][y];
		}
		cout << "\n";
	}
    return 0;
}

