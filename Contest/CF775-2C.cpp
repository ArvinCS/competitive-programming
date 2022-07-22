#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxC = 1e5 + 5;
const int maxM = 1e5 + 5;

struct SegmentTree {
	pair<ll, int> tree[2*maxM];
	
	void reset(){
		fill(tree, tree+2*maxM, make_pair(0, 0));
	}
	
	void update(int pos, pair<ll, int> val){
		pos += maxM;
		
		tree[pos].first += val.first;
		tree[pos].second += val.second;
		
		for(int x=pos;x>1;x>>=1){
			tree[x>>1].first = (tree[x].first+tree[x^1].first);
			tree[x>>1].second = (tree[x].second+tree[x^1].second);
		}
	}
	
	pair<ll, int> query(int left, int right){
		pair<ll, int> ans = {0, 0};
		
		for(left += maxM, right += maxM; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans.first += tree[left].first;
				ans.second += tree[left].second;
				left++;
			}
			if(right&1){
				--right;
				ans.first += tree[right].first;
				ans.second += tree[right].second;
			}
		}
		return ans;
	}
};

vector<pair<int, int>> v[maxC];
SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			v[a[x][y]].push_back({x, y});
		}
	}
	
	tree.reset();
	
	ll ans = 0;
	for(int c=1;c<maxC;c++){
		ll sum = 0;
		for(int x=0;x<v[c].size();x++){
			// row
			ans += v[c][x].first*1ll*x - sum;
			
			// col left
			pair<ll, int> q = tree.query(0, v[c][x].second+1);
			ans += v[c][x].second*1ll*q.second - q.first;
			
			// col right
			q = tree.query(v[c][x].second+1, m+1);
			ans += q.first - v[c][x].second*1ll*q.second;
			
			sum += v[c][x].first;
			tree.update(v[c][x].second, {v[c][x].second, 1});
		}
		
		for(auto p : v[c]){
			tree.update(p.second, {-p.second, -1});
		}
	}
	
	cout << ans << "\n";
    return 0;
}

