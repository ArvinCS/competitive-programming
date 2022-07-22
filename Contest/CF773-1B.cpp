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
		
		map<int, int> mp;
		vector<int> a(n);
		for(int x=0;x<n;x++){
			cin >> a[x];
			mp[a[x]]++;
		}
		
		bool possible = true;
		for(auto p : mp){
			if(p.second&1){
				possible = false;
				break;
			}
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		vector<pair<int, int>> v;
		vector<int> d;
		while(!a.empty()){
			vector<int> w;
			int l = a.size()-1;
			for(l = ((int) a.size())-2;l>=0;l--){
				if(a[l] == a.back()){
					break;
				} else {
					w.push_back(a[l]);
				}
			}
			
			for(int x=0;x<w.size();x++){
				a.insert(a.begin()+l+x, w[x]);
				a.insert(a.begin()+l+x, w[x]);
				v.push_back({l+x-1, w[x]});
			}
			
			for(int x=0;x<2*(w.size()+1);x++){
				a.pop_back();
			}
			d.push_back(2*(w.size()+1));
		}
		
		reverse(d.begin(), d.end());
		
		cout << v.size() << "\n";
		for(auto p : v){
			cout << p.first+1 << " " << p.second << "\n";
		}
		
		cout << d.size() << "\n";
		for(int x=0;x<d.size();x++){
			if(x > 0) cout << " ";
			cout << d[x];
		}
		cout << "\n";
	}
	
    return 0;
}

