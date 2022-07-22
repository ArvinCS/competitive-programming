#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int maxA = 4e8 + 5;
const int maxN = 1e5 + 5;
	
struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	int query(int l, int r){
		if(l > r) return 0;
		return query(r) - query(l-1);
	}
};
 
Fenwick tree;
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x] = {p[x].first+p[x].second, p[x].first-p[x].second};
	}
	
	vector<int> val;
	for(int x=0;x<n;x++){
		val.push_back(p[x].second + maxA);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	
	int comp[n];
	for(int x=0;x<n;x++){
		comp[x] = lower_bound(val.begin(), val.end(), p[x].second+maxA) - val.begin();
	}
	
	int ans = 0;
	int left = 1, right = maxA;
	while(left <= right){ // log(N.logN.logMaxA)
		int mid = (left+right) >> 1;
		
		tree.reset();
		
		vector<array<int, 4>> v;
		for(int x=0;x<n;x++){
			int idx =  lower_bound(val.begin(), val.end(), p[x].second-mid + maxA) - val.begin();
			int idx2 = lower_bound(val.begin(), val.end(), p[x].second+mid + maxA + 1) - val.begin();
			
			v.push_back({p[x].first-mid-1, x+1, idx, idx2});
			v.push_back({p[x].first+mid, x+1, idx, idx2});
			v.push_back({p[x].first, 0, comp[x], x});
		}
		
		sort(v.begin(), v.end());
		
		ll sum = 0;
		for(auto a : v){
			if(a[1] == 0){
				tree.update(a[2], 1);
			} else {
				if(p[a[1]-1].first <= a[0]){
					sum += tree.query(a[2], a[3]-1) - 1;
				} else {
					sum -= tree.query(a[2], a[3]-1);
				}
			}
		}
		
		if(sum >= 2*k){
			ans = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}
