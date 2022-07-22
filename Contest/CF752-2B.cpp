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
		
		if(n % 2 == 0){
			cout << "YES\n";
			continue;
		}
		
		bool valid = false;
		for(int x=0;x+1<n;x++){
			if(a[x] >= a[x+1]){
				valid = true;
			}
		}
		
		if(valid){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

