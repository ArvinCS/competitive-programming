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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n, greater<int>());
		
		if(a[0] > m-1){
			cout << "NO\n";
			continue;
		}
		
		bool possible = true;
		int pos = 2*a[0]+2;
		for(int x=1;x<n;x++){
			if(pos > m){
				possible = false;
				break;
			}
			
			pos += a[x]+1;
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

