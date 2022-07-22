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
		int n, m;
		cin >> n >> m;
		
		int mxr = 0, mxw = 0;
		for(int x=0;x<m;x++){
			int r, w;
			cin >> r >> w;
			
			mxr = max(mxr, r);
			mxw = max(mxw, w);
		}
		
		if(mxr+mxw <= n){
			for(int x=0;x<mxr;x++){
				cout << "R";
			}
			for(int x=0;x<mxw;x++){
				cout << "W";
			}
			for(int x=0;x<n-mxw-mxr;x++){
				cout << "W";
			}
			cout << "\n";
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
	
    return 0;
}

