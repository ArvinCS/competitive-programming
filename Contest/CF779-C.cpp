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
		
		int c[n];
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		bool valid = false;
		int pos = -1;
		for(int x=0;x<n;x++){
			if(c[x] == 1){
				if(pos == -1){
					pos = x;
					valid = true;
				} else {
					valid = false;
				}
			}
		}
		
		if(!valid){
			cout << "NO\n";
			continue;
		}
		
		for(int x=1;x<n;x++){
			if(c[(pos+x)%n]-c[(pos+x-1+n)%n] > 1){
				valid = false;
			}
		}
		
		cout << (valid ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

