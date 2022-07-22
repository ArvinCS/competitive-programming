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
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		int l = 0;
		for(int x=0;x<n;x++){
			if(p[x] == x+1) continue;
			
			l = x;
			break;
		}
		int r = l;
		for(int x=l;x<n;x++){
			if(p[r] > p[x]){
				r = x;
			}
		}
		
		reverse(p+l, p+r+1);
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << p[x];
		}
		cout << "\n";
	}
	
    return 0;
}

