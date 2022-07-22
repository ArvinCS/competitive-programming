#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			if(y % 2 == 1) cout << ".";
			else cout << "*";
		}
		cout << "\n";
	}
	
    return 0;
}

