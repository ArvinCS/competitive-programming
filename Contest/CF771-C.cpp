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
			cin >> p[x];
		}
		
		int mx = p[0];
		vector<int> v;
		v.push_back(p[0]);
		for(int x=1;x<n;x++){
			while(!v.empty() && v.back() >= p[x]){
				v.pop_back();
			}
			mx = max(mx, p[x]);
			v.push_back(mx);
		}
		
		cout << v.size() << "\n";
	}
	
    return 0;
}

