#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

ll a[maxN], b[maxN];

bool customSort(int idx, int idx2){
	if(max(a[idx], b[idx]) == max(a[idx2], b[idx2])){
		return idx < idx2;
	}
	return max(a[idx], b[idx]) > max(a[idx2], b[idx2]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	
	vector<int> v;
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(x);
	}	
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	sort(v.begin(), v.end(), customSort);
	
	ll left = 1, right = max(a[v[0]], b[v[0]])*m, ans = 1;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll cnt = 0;
		for(int i=0;i<n;i++){
			int x = v[i];
			
			if(a[x] >= b[x]){
				ll need = (mid+a[x]-1)/a[x];
				
				if(need > m){
					cnt -= (mid-m*a[x]+b[x]-1)/b[x];
					
					if(cnt < 0) break;
				} else {
					cnt += m-need;
				}
			} else {
				ll need = (mid+b[x]-1)/b[x];
				
				if(need > m){
					cnt -= need-m;
					
					if(cnt < 0) break;
				} else {
					cnt += m-need;
				}
			}
		}
		
		if(cnt >= 0){
			left = mid+1;
			ans = max(ans, mid);
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

