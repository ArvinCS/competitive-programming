#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
    	int n;
    	cin >> n;
    	
    	int a[n], b[n];
    	for(int x=0;x<n;x++){
    		cin >> a[x];
		}
		for(int x=0;x<n;x++){
    		cin >> b[x];
		}
		
		for(int x=0;x<n;x++){
			if(a[x] < b[x]) swap(a[x], b[x]);
		}
		
		sort(a, a+n);
		sort(b, b+n);
		
		cout << a[n-1]*b[n-1] << "\n";
	}
    
	return 0;
}
