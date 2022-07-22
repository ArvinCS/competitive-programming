#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, int>> v[27][2][2];
char ans[maxN];
int level[maxN], prv[maxN], nxt[maxN], last[maxN][27][2];
bool open[maxN];
string s;

void solve(int l, int r){
	if(l < 0 || l >= s.length() || l >= r) return;
		
	int idx = (s[l] - 'a');
	if(v[idx][(l&1)^1][open[l]^1].empty()){
		solve(l+1, r-1);
		return;
	}
	
	auto it = upper_bound(v[idx][(l&1)^1][open[l]^1].begin(), v[idx][(l&1)^1][open[l]^1].end(), make_pair(level[l], r));
	if(it == v[idx][(l&1)^1][open[l]^1].begin()){
		solve(l+1, r-1);
		return;
	}
	
	it--;
	if((*it).first < level[l]){
		solve(l+1, r-1);
		return;
	}
	
	if(nxt[l] >= (*it).second){
		solve(l+1, (*it).second-1);
		solve((*it).second+1, r);
		return;
	}
	
	ans[l] = '(';
	ans[nxt[l]] = '(';
	ans[prv[(*it).second]] = ')';
	ans[(*it).second] = ')';
	
	nxt[nxt[l]] = prv[(*it).second];
	prv[prv[(*it).second]] = nxt[l];
	
	solve(l+1, (*it).second-1);
	solve((*it).second+1, r);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("output.txt","r",stdin);
	
	cin >> s;
	
	if(s.length()&1){
		cout << "-1\n";
		return 0;
	}
	
	stack<int> st;
	
	int cur = 0;
	fill(prv, prv+s.length(), s.length());
	fill(nxt, nxt+s.length(), 0);
	
	for(int x=0;x<s.length();x++){
		if(!st.empty() && s[st.top()] == s[x]){
			cur--;
			level[x] = cur;
			
			ans[st.top()] = '(';
			ans[x] = ')';
			
			open[st.top()] = true;
			open[x] = false;
			
			prv[x] = st.top();
			nxt[st.top()] = x;
			
			v[(s[x] - 'a')][st.top()&1][open[st.top()]].push_back(make_pair(cur, st.top()));
			v[(s[x] - 'a')][x&1][open[x]].push_back(make_pair(cur, x));
			st.pop();
		} else {
			st.push(x);
			level[x] = cur;
			cur++;
		}
	}
	
	if(!st.empty()){
		cout << "-1\n";
		return 0;
	}
	
	solve(0, s.length()-1);
	
	for(int x=0;x<s.length();x++){
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

