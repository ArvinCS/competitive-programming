#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	vector<int> w[n];
	map<int, int> mp;
	for(int x=0;x<n;x++){
		int val = a[x];
		
		while(val > 0){
			w[x].push_back(val%10);
			val /= 10;
		}
		while(w[x].size() < 6) w[x].push_back(0);
		reverse(w[x].begin(), w[x].end());
		
		for(int y=0;y<w[x].size();y++){
			cout << w[x][y];
		}cout << "\n";
		val = a[x];
		vector<int> tmp;
		while(val > 0){
			tmp.push_back(9-(val%10));
			val /= 10;
		}
		while(tmp.size() < 6) tmp.push_back(9);
		reverse(tmp.begin(), tmp.end());
		
		for(int x=0;x<tmp.size();x++){
			val *= 10;
			val += tmp[x];
		}
		for(int y=0;y<tmp.size();y++){
			cout << tmp[y];
		}cout << "\n";
		mp[val]++;
	}
	
	ll ans = 0;
	int pos = n-1;
	for(int x=1000000-1;x>=0;x--){
		vector<int> v;
		int cur = x;
		while(cur > 0){
			v.push_back(cur%10);
			cur /= 10;
		}
		while(v.size() < 6) v.push_back(0);
		reverse(v.begin(), v.end());
		
		while(pos >= 0){
			bool ok = true;
			for(int y=0;y<6;y++){
				if(v[y] > w[pos][y]){
					break;
				} else if(v[y] < w[pos][y]){
					ok = false;
					break;
				}
			}
			
			if(!ok) pos--;
			else break;
		}
		
		if(mp[x] > 0) cout << x << " -> " << mp[x] << " " << pos << "\n";
		ans += mp[x]*(pos+1);
	}
	
	cout << ans << "\n";
    return 0;
}

