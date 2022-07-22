	#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6;
const int mx = 5078;

vector<int> v;
vector<int> w;
//bool picked[maxN];
int n, k;
bool picked[maxN];

void solve(vector<int> &cur){
	if(w.size() == (1 << n)) return;
//	if(w.size() >= mx) return;
//	if(cur.size() >= mx){
//		w = cur;
//		return;
//	}
	
	bool found = false;
	int pw = 1;
	for(int val=0;val<(1 << n);val++){
		if(!picked[val] && __builtin_popcount(val^cur.back()) == k){
			cur.push_back(val);
			picked[val] = true;
			solve(cur);
			picked[val] = false;
			cur.pop_back();
			found = true;
		}
	}
//		for(auto val : tmp){
//			if(cnt >= mx) break;
//			cnt++;
//			int cnt = __builtin_popcount(val)+__builtin_popcount(cur.back());
//			if(cnt >= prv && __builtin_popcount(val^cur.back()) == 1){
//				cur.push_back(val);
////				picked[val] = true;
//				st.erase(val);
//				solve(cur, cnt);
//				st.insert(val);
////				picked[val] = false;
//				cur.pop_back();
//				found = true;
//			}
//		}
	
	if(!found){
		if(cur.size() > w.size()) w = cur;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	fill(picked, picked+maxN, true);
	
	for(int state=0;state<(1 << n);state++){
//			v.push_back(state);
		picked[state] = false;
	}
	
	vector<int> tmp;
	tmp.push_back(0);
	picked[0] = true;
	solve(tmp);
	
	cout << w.size() << "\n";
	for(auto val : w){
		for(int x=0;x<n;x++){
			if(val&(1 << x)){
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}
	return 0;
}
