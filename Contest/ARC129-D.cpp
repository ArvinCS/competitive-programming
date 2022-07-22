#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll sum = 0;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += abs(a[x]);
	}
	
	int mn = 0;
	for(int x=1;x<n;x++){
		if(a[mn] > a[x]){
			mn = x;
		}
	}
	
	int depth[n];
	fill(depth, depth+n, n);
	for(int x=0;x<n;x++){
		depth[(mn+x)%n] = min(depth[(mn+x)%n], x);
		depth[(mn-x+n)%n] = min(depth[(mn-x+n)%n], x);
	}
	
	vector<int> v[n];
	for(int x=0;x<n;x++){
		v[depth[x]].push_back(x);
	}
	
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		for(auto idx : v[i]){
			if(a[idx] == 0) continue;
			
			if(a[idx] < 0){
				int need = (abs(a[idx])+1)/2;
				ans += need;
				
				a[idx] += need*2;
				a[(idx-1+n)%n] -= need;
				a[(idx+1)%n] -= need;
			} else {
				int need = a[idx];
				ans += need;
				
				if(depth[(idx-1+n)%n] == i-1){
					a[idx] -= need;
					a[(idx-1+n)%n] += need*2;
					a[(idx-2+n)%n] -= need;
				} else {
					a[idx] -= need;
					a[(idx+1)%n] += need*2;
					a[(idx+2)%n] -= need;
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(a[x] != 0){
			cout << "-1\n";
			return 0;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

