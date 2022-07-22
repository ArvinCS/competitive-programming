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

const int maxN = 2e5 + 5;

int parrent[maxN], sz[maxN];
bool active[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

int getSize(int x){
	return sz[getParrent(x)];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, q;
	cin >> n >> m >> q;
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		int t;
		cin >> t;
		
		parrent[x] = x;
		sz[x] = 1;
		while(t--){
			int a, b;
			cin >> a >> b;
			
			v.push_back({a, x});
			v.push_back({b+1, -x});
		}
	}
	
	sort(v.begin(), v.end());
	
	set<int> active;
	for(auto p : v){
		int time = p.first, curNode = p.second;
		if(active.count(abs(curNode))){
			active.erase(abs(curNode));
		} else {
			if(active.size() > 0){
				merge(*(active.begin()), curNode);
			}
			active.insert(curNode);
		}
	}
	
	for(int x=0;x<q;x++){
		int curNode;
		cin >> curNode;
		
		curNode--;
		cout << getSize(curNode) << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

