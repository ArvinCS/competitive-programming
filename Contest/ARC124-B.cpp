#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	vector<ll> v;
	for(int x=0;x<n;x++){
		map<ll, int> mp;
		for(int y=0;y<n;y++){
			mp[b[y]]++;
		}
		
		mp[b[x]]--;
		
		bool valid = true;
		int ans = a[0]^b[x];
		for(int y=1;y<n;y++){
			if(mp.find(a[y]^ans) != mp.end() && mp[a[y]^ans] > 0){
				mp[a[y]^ans]--;
			} else {
				valid = false;
			}
		}
		
		if(valid){
			v.push_back(ans);
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	cout << v.size() << "\n";
	for(int x=0;x<v.size();x++){
		cout << v[x] << "\n";
	}
    return 0;
}

