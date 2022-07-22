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
		
		bool valid = true;
		int cnt = 0, idx = 0;
		for(int x=0;x<n;x++){
			bool possible = false;
			for(int y=x+2;y>=max(2, x+2-cnt);y--){
				if(a[x] % y != 0){
					possible = true;
					break;
				}
			}
			
			if(possible){
				cnt++;
			} else {
				valid = false;
				break;
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

