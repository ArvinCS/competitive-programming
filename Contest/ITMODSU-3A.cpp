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

const int maxN = 2e5 + 10;

int cnt = 0, comp = 0;
stack<pair<int, int>> sv;
stack<pair<int, int>> st;
int parrent[maxN], sz[maxN];

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
	pair<int, int> cur = sv.top();
	sv.pop();
	
	comp = cur.second;
	for(int i=1;i<=cnt;i++){
		pair<int, int> p = st.top();
		st.pop();
		
		sz[getParrent(p.first)] -= p.second;
		sz[p.first] = p.second;
		parrent[p.first] = p.first;
	}
	cnt = cur.first;
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
	for(int x=0;x<maxN;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	for(int x=0;x<m;x++){
		string s;
		cin >> s;
		
		if(s == "union"){
			int a, b;
			cin >> a >> b;
			
			merge(a, b);
			cout << comp << "\n";
		} else {
			if(s == "persist"){
				save();
			} else {
				rollback();
				cout << comp << "\n";
			}
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

