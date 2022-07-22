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
		
		int last = 0, last2 = n-1;
		for(int x=1;x<n;x++){
			if(a[x] == 1){
				last = x;
			} else {
				break;
			}
		}
		for(int x=n-2;x>=0;x--){
			if(a[x] == 1){
				last2 = x;
			} else {
				break;
			}
		}
		
		cout << max(0, last2-last) << "\n";
	}
	
    return 0;
}

