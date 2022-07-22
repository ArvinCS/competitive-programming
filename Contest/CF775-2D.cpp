#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxC = 1e6 + 5;
const int maxN = 1e6 + 5;

int a[maxN], prefix[maxC];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		ll c;
		cin >> n >> c;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		fill(prefix, prefix+c+1, 0);
		
		for(int x=0;x<n;x++){
			prefix[a[x]]++;
		}
		for(int x=1;x<=c;x++){
			prefix[x] += prefix[x-1];
		}
		
		bool valid = true;
		for(int x=1;x<=c;x++){
			if(prefix[x]-prefix[x-1] > 0){
				for(int y=1;y*1ll*x<=c;y++){
					int cnt = prefix[min((y+1)*1ll*x-1, c)] - prefix[min(y*1ll*x-1, c)];
					
					if(cnt > 0){
						if(prefix[y]-prefix[y-1] == 0){
							valid = false;
							break;
						}
					}
				}
				
				if(!valid) break;
			}
		}
		
		cout << (valid ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

