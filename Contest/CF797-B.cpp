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
		
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		bool possible = false;
		int left = 1, right = 1e9;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool less = false, great = false;
			for(int x=0;x<n;x++){
				if(max(0, a[x]-mid) < b[x]){
					less = true;
				}
				if(max(0, a[x]-mid) > b[x]){
					great = true;
				}
			}
			
			if(less&&great){
				break;
			}
			if(!less && !great){
				possible = true;
				break;
			}
			
			if(great){
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

