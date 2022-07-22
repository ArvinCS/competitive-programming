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
		
		if(a[n-2] > a[n-1]){
			cout << "-1\n";
			continue;
		}
		if(a[n-1] < 0){
			bool valid = true;
			for(int x=0;x+1<n;x++){
				if(a[x] > a[x+1]){
					valid = false;
					break;
				}
			}	
			
			if(valid){
				cout << "0\n";
			} else {
				cout << "-1\n";
			}
			continue;
		}
		
		vector<tuple<int, int, int>> ans;
		for(int x=n-3;x>=0;x--){
			ans.push_back(make_tuple(x, n-2, n-1));
		}
		
		cout << ans.size() << "\n";
		for(auto t : ans){
			cout << get<0>(t)+1 << " " << get<1>(t)+1 << " " << get<2>(t)+1 << "\n";
		}
	}
	
    return 0;
}

