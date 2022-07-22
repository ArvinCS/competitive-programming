#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll l, r;
	cin >> n >> l >> r;
	
	int a[n+1];
	for(int x=0;x<=n;x++){
		a[x] = x;
	}
	
	auto find = [&](ll val) -> int {
		int ans = 0;
		int left = 1, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			ll cnt = n*1ll*(n-1)/2 - (n-mid)*1ll*(n-1-mid)/2;
			if(cnt < val){
				ans = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		return ans+1;
	};
	
	int s = find(l), t = find(r);
	ll s2 = s+l-(n*1ll*(n-1)/2 - (n-s+1)*1ll*(n-s)/2);
	ll t2 = t+r-(n*1ll*(n-1)/2 - (n-t+1)*1ll*(n-t)/2);
	
	vector<int> v;
	if(s < t){
		v.push_back(s);
		for(int x=s2;x<=n;x++){
			v.push_back(x);
		}
	} else if(s == t){
		v.push_back(s);
		for(int x=s2;x<=t2;x++){
			v.push_back(x);
		}
	}
	
	for(int x=v.size()-1;x>0;x--){
		swap(a[v[x-1]], a[v[x]]);
	}
	
	v.clear();
	
	int rem = t-s-1;
	if(rem > 0){ // e.g. s < t
		vector<int> w;
		for(int x=s+1;x<=n;x++){
			w.push_back(a[x]);
		}
		for(int x=s+1;x<t;x++){
			a[x] = w.back();
			w.pop_back();
		}
		for(int x=t;x<=n;x++){
			a[x] = w[x-t];
		}
	}
	
	if(s < t){
		v.push_back(t);
		for(int x=t+1;x<=t2;x++){
			v.push_back(x);
		}
		
		for(int x=v.size()-1;x>0;x--){
			swap(a[v[x-1]], a[v[x]]);
		}
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << a[x];
	}
	cout << "\n";
    return 0;
}

