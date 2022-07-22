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

const int maxN = 1e5;

int parrent[maxN], sz[maxN], cnt = 0, comp = 0;
stack<pair<int, int>> st, sv;

int getParrent(int x){
	if(parrent[x] == x) return x;
	return getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		cnt++;
		comp--;
		st.push({b, sz[b]});
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

void save(){
	sv.push({cnt, comp});
	cnt = 0;
}

void rollback(){
	pair<int, int> tmp = sv.top();
	sv.pop();
	
	for(int x=1;x<=cnt;x++){
		pair<int, int> p = st.top();
		st.pop();
		
		sz[getParrent(p.first)] -= p.second;
		sz[p.first] = p.second;
		parrent[p.first] = p.first;		
	}
	cnt = tmp.first;
	comp = tmp.second;
}

int block = 1;
bool customSort(tuple<int, int, int> a, tuple<int, int, int> b){
	if(get<0>(a)/block == get<0>(b)/block) return get<1>(a) < get<1>(b);
	return (get<0>(a)/block) < (get<0>(b)/block);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	block = sqrt(m);
//	cnt = 0;
//	comp = n;
	pair<int, int> edge[m];
	for(int x=0;x<m;x++){
		cin >> edge[x].first >> edge[x].second;
	}
	
	int k;
	cin >> k;
	
	vector<tuple<int, int, int>> q;
	for(int i=0;i<k;i++){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		q.push_back(make_tuple(l, r, i));
	}
	
	sort(q.begin(), q.end(), customSort);
	
	int ans[k];
	fill(ans, ans+k, -1);
	
	int idx = 0;
	for(int i=1;i<=(m+block-1)/block + 1;i++){		
		while(!st.empty()) st.pop();
		while(!sv.empty()) sv.pop();
		cnt = 0;
		comp = n;
		for(int x=0;x<=n;x++){
			parrent[x] = x;
			sz[x] = 1;
		}
		
		int left = i*block, right = i*block;
		while(idx < k && get<0>(q[idx]) < i*block){
			int l = get<0>(q[idx]), r = get<1>(q[idx]), cur = get<2>(q[idx]);
			if(r <= i*block){
				save();
				for(int x=l;x<=r;x++){
					merge(edge[x].first, edge[x].second);
				}
				ans[cur] = comp;
				rollback();
				idx++;
				continue;
			}
			
			while(right <= r){
				merge(edge[right].first, edge[right].second);
				right++;
			}
			
			save();
			while(left > l){
				merge(edge[left-1].first, edge[left-1].second);
				left--;
			}
			ans[cur] = comp;
			
			rollback();
			left = i*block;
			idx++;
		}
	}
	
	for(int x=0;x<k;x++) cout << ans[x] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

