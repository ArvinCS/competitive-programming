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
		
		pair<int, int> mn = {1e9 + 1, -1};
		int a[n], neg = 0;
		for(int x=0;x<n;x++){
			cin >> a[x];
			if(a[x] < 0) neg++;
			mn = min(mn, {abs(a[x]), x});
		}
		
		bool valid = true;
		for(int y=mn.second-1;y>=0;y--){
			if(abs(a[y]) * (y+1 <= neg ? -1 : 1) > abs(a[y+1]) * (y+2 <= neg ? -1 : 1)){
				valid = false;
			}
		}
		for(int y=mn.second;y+1<n;y++){
			if(abs(a[y]) * (y+1 <= neg ? -1 : 1) > abs(a[y+1]) * (y+2 <= neg ? -1 : 1)){
				valid = false;
			}
		}
		
		cout << (valid ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

