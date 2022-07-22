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
		
		if(a[0] < 0){
			cout << "No\n";
			continue;
		}
		if(a[n-1] > 0){
			cout << "No\n";
			continue;
		}
		
		int lst = n;
		for(int x=n-1;x>=0;x--){
			if(a[x] != 0) break;
			lst = x;
		}
		
		if(lst == 0){
			cout << "Yes\n";
			continue;
		}
		
		bool possible = true;
		ll mn = 0;
		for(int x=0;x<lst-1;x++){
			if(a[x]+(x>0) <= mn){
				possible = false;
				break;
			}
			
			mn = -((a[x]+(x>0))-1-mn);
		}
		if(a[lst-1] != mn-1){
			possible = false;
		}
		
		cout << (possible ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

