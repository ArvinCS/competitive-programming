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
			p[x] = n-x;
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << p[x];
		}
		cout << "\n";
			
		for(int i=0;i<n-1;i++){
			swap(p[i], p[(i+1)%n]);
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << p[x];
			}
			cout << "\n";
			swap(p[i], p[(i+1)%n]);
		}
	}
	
    return 0;
}

