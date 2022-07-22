#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxM = 1e5 + 5;

ll parrent[maxM][2]; // 0 right 1 left
ll val[maxM], sz[maxM], idx = 0;
map<ll, int> mp;

void init(){
	idx = 0;
}

void create(ll x){
	if(mp.find(x) != mp.end()) return;
	
	parrent[idx][0] = parrent[idx][1] = idx;
	val[idx] = x;
	sz[idx] = 1;
	mp[x] = idx;
	idx++;	
}

int getParrent(int x, int id){
	if(parrent[x][id] == x) return x;
	return parrent[x][id] = getParrent(parrent[x][id], id);
}

void mergeRight(int x, int y){
	int a = getParrent(x, 0);
	int b = getParrent(y, 0);
	
	if(a != b){
		parrent[a][0] = y;
	}
}

void mergeLeft(int x, int y){
	int a = getParrent(x, 1);
	int b = getParrent(y, 1);
	
	if(a != b){
		parrent[a][1] = y;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n, m;
		cin >> n >> m;
		
		init();
		mp.clear();
		
		vector<pair<ll, int>> v;
		pair<ll, ll> s[n];
		for(int x=0;x<n;x++){
			cin >> s[x].first >> s[x].second;
			v.push_back({s[x].first, 1});
			v.push_back({s[x].second, -1});
		}
		
		v.push_back({-inf_ll, -1});
		v.push_back({inf_ll, 1});
		
		sort(v.begin(), v.end());
		
		ll a[m], ans[m];
		for(int x=0;x<m;x++){
			cin >> a[x];
		}
		
		for(int x=0;x<m;x++){
			auto it1 = lower_bound(v.begin(), v.end(), make_pair(a[x], -1));
			
			pair<ll, int> left = *(it1-1), right = *it1;
			
			if(left.second == 1){ // in range
				create(a[x]);
				
				int p = getParrent(mp[a[x]], 1), p2 = getParrent(mp[a[x]], 0);
				
//				cout << x << " -> "<< val[p] << " " << val[p2] << " l\n";
				if(abs(val[p]-a[x]) <= abs(val[p2]-a[x])){					
					it1 = lower_bound(v.begin(), v.end(), make_pair(val[p], -1));
					it1--;
					
					ans[x] = val[p];
					
					if((*it1).second == 1){
						create(val[p]-1);
						mergeLeft(p, mp[val[p]-1]);
					} else {
						create((*it1).first);
						mergeLeft(p, mp[(*it1).first]);
					}
					
					if(val[p2] == a[x]){
						it1 = lower_bound(v.begin(), v.end(), make_pair(val[p2]+1, -1));
						
						if((*it1).second == -1){
							create(val[p2]+1);
							mergeRight(p2, mp[val[p2]+1]);
						} else {
							create((*it1).first);
							mergeRight(p2, mp[(*it1).first]);
						}
					}
				} else {
					it1 = lower_bound(v.begin(), v.end(), make_pair(val[p2]+1, -1));
					
					ans[x] = val[p2];
					if((*it1).second == -1){
						create(val[p2]+1);
						mergeRight(p2, mp[val[p2]+1]);
					} else {
						create((*it1).first);
						mergeRight(p2, mp[(*it1).first]);
					}
					
					if(val[p] == a[x]){
						it1 = lower_bound(v.begin(), v.end(), make_pair(val[p], -1));
						it1--;
						
						if((*it1).second == 1){
							create(a[x]-1);
							mergeLeft(p, mp[a[x]-1]);
						} else {
							create((*it1).first);
							mergeLeft(p, mp[(*it1).first]);
						}
					}
				}
			} else { // not in range
				create(left.first);
				create(right.first);
				
				int p = getParrent(mp[left.first], 1), p2 = getParrent(mp[right.first], 0);
				
//				cout << x << " -> "<< val[p] << " " << val[p2] << " r\n";
				if(abs(val[p]-a[x]) <= abs(val[p2]-a[x])){
					it1 = lower_bound(v.begin(), v.end(), make_pair(val[p], -1));
					it1--;
					
					ans[x] = val[p];
					
					if((*it1).second == 1){
						create(val[p]-1);
						mergeLeft(p, mp[val[p]-1]);
					} else {
						create((*it1).first);
						mergeLeft(p, mp[(*it1).first]);
					}
				} else {
					it1 = lower_bound(v.begin(), v.end(), make_pair(val[p2]+1, -1));
					
					ans[x] = val[p2];
					
					if((*it1).second == -1){
						create(val[p2]+1);
						mergeRight(p2, mp[val[p2]+1]);
					} else {
						create((*it1).first);
						mergeRight(p2, mp[(*it1).first]);
					}
				}
			}
			
//			cout << left.first << " " << left.second << " " << right.first << " " << right.second << "\n";
		}
		
		cout << "Case #" << i << ":";
		for(int x=0;x<m;x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

