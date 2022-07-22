#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 3e4 + 5;
const int maxQ = 2e5 + 5;

struct Fenwick {
	int tree[maxA];
	
	void reset(){
		fill(tree, tree+maxA, 0);
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
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxA){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

int n;
pair<int, int> p[maxQ];
int k[maxQ];
Fenwick tree;

bool customSort(int a, int b){
	return k[a] < k[b];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	vector<int> w;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		w.push_back(a[x]);
	}
	
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	
	vector<int> z[w.size()];
	for(int x=0;x<n;x++){
		a[x] = lower_bound(w.begin(), w.end(), a[x]) - w.begin();
		z[a[x]].push_back(x);
	}
	
	int q;
	cin >> q;
	
	vector<int> v;
	for(int x=0;x<q;x++){
		cin >> p[x].first >> p[x].second >> k[x];
		p[x].first--; p[x].second--;
		
		v.push_back(x);
	}
	
	sort(v.begin(), v.end(), customSort);
	
	int ans[q], mn = w.size();
	for(int x=q-1;x>=0;x--){ // [L, R)
		int idx = v[x];
		int val = lower_bound(w.begin(), w.end(), k[idx]+1) - w.begin();
		while(mn > val){
			mn--;
			
			for(auto pos : z[mn]){
				tree.update(pos, 1);
			}
		}
		
		ans[idx] = tree.query(p[idx].second) - (p[idx].first > 0 ? tree.query(p[idx].first-1) : 0);
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

