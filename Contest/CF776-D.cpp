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
		
		int ans[n];
		ans[0] = 0;
		
		for(int x=n-1;x>=0;x--){
			int pos = 0;
			for(int y=0;y<=x;y++){
				if(a[y] == x+1){
					pos = y;
					break;
				}
			}
			
			ans[x] = (pos+1) % (x+1);
			
			int new_a[n];
			for(int y=0;y<=x;y++){
				new_a[y] = a[(y-(x-pos)+x+1) % (x+1)];
			}
			for(int y=0;y<=x;y++){
				a[y] = new_a[y];
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

