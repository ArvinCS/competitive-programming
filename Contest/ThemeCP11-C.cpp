#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> v;
	int l = 0, r = m-1;
	int cnt = 0;
	
	while(v.size() < n*m && l < r){
		v.push_back({cnt, l});
		v.push_back({(n-cnt-1)%n, r});
		
		cnt++;
		if(cnt >= n){
			cnt = 0;
			l++;
			r--;
		}
	}
	while(l == r && cnt < (n+1)/2){
		v.push_back({cnt, l});
		if((n-cnt-1)%n != cnt)v.push_back({(n-cnt-1)%n, l});
		cnt++;
	}
	
	for(auto p : v){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}
    return 0;
}

