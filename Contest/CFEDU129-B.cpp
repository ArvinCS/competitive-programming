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
		
		int m;
		cin >> m;
		
		int b[m];
		for(int x=0;x<m;x++){
			cin >> b[x];
		}
		
		int pos = 0;
		for(int x=0;x<m;x++){
			pos += b[x];
			pos %= n;
		}
		
		cout << a[pos] << "\n";
	}
	
    return 0;
}

