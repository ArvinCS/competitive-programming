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
		int n, k;
		cin >> n >> k;
		
		if(k == 1){
			cout << "YES\n";
			for(int x=1;x<=n;x++){
				cout << x << "\n";
			}
		} else if(n % 2 == 0){
			cout << "YES\n";
			for(int x=1;x<=n/2;x++){
				int cur = (x-1)*4+1;

				for(int y=(x-1)*2*k+1;y<=x*2*k;y+=2){
					if(y > (x-1)*2*k+1) cout << " ";
					cout << y;
				}
				cout << "\n";
				
				for(int y=(x-1)*2*k+2;y<=x*2*k;y+=2){
					if(y > (x-1)*2*k+2) cout << " ";
					cout << y;
				}
				cout << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

