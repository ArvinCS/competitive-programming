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
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int l = n, r = -1;
		for(int x=0;x<n;x++){
			if(a[x] != 0){
				l = x;
				break;
			}
		}
		for(int x=n-1;x>=0;x--){
			if(a[x] != 0){
				r = x;
				break;
			}
		}
		
		bool ok = true;
		for(int x=l+1;x<r;x++){
			if(a[x] == 0){
				ok = false;
				break;
			}
		}
		
		if(!ok){
			cout << "2\n";
			continue;
		}
		
		int zero = 0;
		for(int x=0;x<n;x++){
			if(a[x] == 0) zero++;
		}
		
		cout << (zero != n) << "\n";
	}
	
    return 0;
}

