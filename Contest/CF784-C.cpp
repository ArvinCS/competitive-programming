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
		
		bool odd = true, even = true;
		for(int x=0;x<n;x+=2){
			if(a[x] % 2 != a[0] % 2){
				even = false;
			}
		}
		for(int x=1;x<n;x+=2){
			if(a[x] % 2 != a[1] % 2){
				odd = false;
			}
		}
		
		cout << (odd&&even ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

