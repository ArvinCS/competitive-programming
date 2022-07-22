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

const int maxN = 3e5 + 5;

int parrent[maxN], sz[maxN], ans[maxN], cnt = 0, comp = 0;
stack<pair<int, int>> sv, st;

struct Query {
	int a, b;
	int l, r;
	
	Query(int a, int b, int l, int r) : a(a), b(b), l(l), r(r){
	}
};

int getParrent(int x){
	if(parrent[x] == x) return x;
	return getParrent(parrent[x]);
}

void merge(int x, int y){
	x = getParrent(x);
	y = getParrent(y);
	
	if(x != y){
		if(sz[x] < sz[y]){
			swap(x, y);
		}
		
		cnt++;
		comp--;
		st.push({y, sz[y]});
		parrent[y] = x;
		sz[x] += sz[y];
	}
}

void save(){
	sv.push({cnt, comp});
	cnt = 0;
}

void rollback(){
	pair<int, int> cur = sv.top();
	sv.pop();
	
	for(int x=1;x<=cnt;x++){
		pair<int, int> p = st.top();
		st.pop();
		
		sz[getParrent(p.first)] -= p.second;
		sz[p.first] = p.second;
		parrent[p.first] = p.first;
	}
	cnt = cur.first;
	comp = cur.second;
}

void solve(int left, int right, vector<Query> v){ // [left, right]
	if(left > right) return;
	if(left == right){
		save();
		for(auto q : v){
			if(q.l <= left && q.r >= right){
				merge(q.a, q.b);
			}
		}
		ans[left] = comp;
		rollback();
		return;
	}
	
	save();
	vector<Query> tmp;
	for(auto q : v){
		if(q.l <= left && q.r >= right){
			merge(q.a, q.b);
			continue;
		}
		if(q.l <= right && q.r >= left){
			tmp.push_back(q);
		}
	}
	
	int mid = (left+right) >> 1;
	solve(left, mid, tmp); // [left, mid]
	solve(mid+1, right, tmp); // [mid+1, right]
	rollback();
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	cnt = 0;
	comp = n;
	for(int x=0;x<=n+1;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	map<pair<int, int>, int> mp;
	vector<Query> v;
	vector<int> w;
	for(int x=0;x<m;x++){
		char c;
		cin >> c;
		
		if(c == '?'){
			w.push_back(x);
		} else {
			int a, b;
			cin >> a >> b;
			
			if(a > b) swap(a, b);
			if(c == '+'){
				v.push_back(Query(a, b, x, inf_int)); // [l, inf)
				mp[{a, b}] = v.size()-1;
			} else if(c == '-'){
				v.push_back(Query(a, b, v[mp[{a, b}]].l, x-1)); // [l, r]
				v[mp[{a, b}]].l = inf_int;
				mp.erase(mp.find({a, b}));
			}
		}
	}
	
	solve(0, m-1, v);
	
	for(auto i : w){
		cout << ans[i] << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar
