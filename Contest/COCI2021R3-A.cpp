#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int l=0;l<n;l++){
		for(int r=l+k-1;r<n;r+=k){
			int length = (r-l+1)/k;
			
			bool valid = true;
			for(int x=l;x<=r;x+=length){
				for(int y=0;y<length;y++){
					if(a[x+y] != a[l+y]){
						valid = false;
						break;
					}
				}
				if(!valid) break;
			}		
			
			if(valid){
				cout << length << "\n";
				for(int y=0;y<length;y++){
					if(y > 0) cout << " ";
					cout << a[l+y];
				}
				cout << "\n";
				return 0;
			}
		}
	}
	
	cout << "-1\n";
	return 0;
}
