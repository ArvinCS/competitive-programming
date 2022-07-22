#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	map<ll, int> mp;
	for(int x=0;x<n;x++){
		mp[a[x]]++;
	}
	
	vector<pair<ll, int>> v;
	for(auto p : mp){
		v.push_back(p);
	}
	
	int left = 0, right = v.size()-1;
	int cntLeft = v[left].second, cntRight = v[right].second;
	ll curLeft = v[left].first, curRight = v[right].first;
	while(left < right){
		if(k < min(cntLeft, cntRight)) break;
		
		if(cntLeft <= cntRight){
			ll need = min((v[left+1].first-v[left].first)*cntLeft, k/cntLeft * cntLeft);
			
			k -= need;
			curLeft += need/cntLeft;
			
			if(curLeft == v[left+1].first){
				left++;
				cntLeft += v[left].second;
			}
		} else {
			ll need = min((v[right].first-v[right-1].first)*cntRight, k/cntRight * cntRight);
			
			k -= need;
			curRight -= need/cntRight;
			
			if(curRight == v[right-1].first){
				right--;
				cntRight += v[right].second;
			}
		}
	}
	
	cout << curRight-curLeft << "\n";
    return 0;
}

