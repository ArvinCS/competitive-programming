#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define ll long long

const ll mod = 1e9+7;
const int maxN = 5e5 + 5;
const int logN = log2(maxN)+1;

ll h[maxN];
ll pw[maxN];
vector<pair<int, int>> v;
string s;

bool compare(pair<int, int> p1, pair<int, int> p2){
	int mn = min(s.length()-p1.first, s.length()-p2.first);
	int left = 0, right = mn-1, bound = -1;
	int pos1 = p1.first, pos2 = p2.first;
//	assert(v[idx].first+v[idx].second <= s.length() && v[idx2].first+v[idx2].second <= s.length());
	while(left <= right){
		int mid = (left+right) >> 1;
		
		ll val1 = (h[pos1] - h[pos1+mid+1] * pw[mid+1] % mod + mod);
		ll val2 = (h[pos2] - h[pos2+mid+1] * pw[mid+1] % mod + mod);
		
		if(val1 >= mod) val1 -= mod;
		if(val2 >= mod) val2 -= mod;
		
		if(val1 == val2){
			if(bound < mid) bound = mid;
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	if(bound+1 == mn){
		return (p1.first > p2.first);
	}
	
	ll val1 = (h[pos1+bound+1] - h[pos1+bound+2] * pw[1] % mod + mod);
	ll val2 = (h[pos2+bound+1] - h[pos2+bound+2] * pw[1] % mod + mod);
	
	if(val1 >= mod) val1 -= mod;
	if(val2 >= mod) val2 -= mod;
		
	return val1 < val2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = 29*pw[x-1] % mod;
	}
	
	int n, k;
	cin >> n >> k;
	
	cin >> s;
	
	int a[k][k];
	for(int x=0;x<k;x++){
		for(int y=0;y<k;y++){
			char c;
			cin >> c;
			
			a[x][y] = (c == '1');
		}
	}
	
	stack<pair<char, int>> st;
	int pos[n];
	st.push({s[0], 0});
	for(int x=0;x<n;x++){
		while(!st.empty() && !a[(st.top().first - 'a')][(s[x] - 'a')]){
			pos[st.top().second] = x;
			st.pop();
		}
		st.push({s[x], x});
	}
	while(!st.empty()){
		pos[st.top().second] = n;
		st.pop();
	}
	
	h[n] = h[n+1] = 0;
	
	int idx = n;
	h[idx] = 0;
	v.push_back({n, n});
	
	for(int x=n-1;x>=0;x--){		
		int bestIdx = v.size()-1;
		pair<int, int> best = v.back();
		v.pop_back();
		while(!v.empty() && v.back().second <= pos[x]){
			if(compare(v.back(), best)){
				best = v.back();
			}
			v.pop_back();
		}
		
		idx = best.first-1;
		v.push_back(best);
		
		h[idx] = ((s[x] - 'a') + h[idx+1] * pw[1] % mod);
		if(h[idx] >= mod) h[idx] -= mod;
		
		v.push_back({idx, x});
//		cout << x << " -> " << idx << " " << best.first << " " << best.second << " " << h[idx] << " " << h[idx+1]*pw[1]<< "\n";
	}
	
	for(int x=idx;x<n;x++){
		ll idx = (h[x] - h[x+1] * pw[1] % mod + mod);
		if(idx >= mod) idx -= mod;
		
		char c = ('a' + idx);
		cout << c;
	}
	cout << "\n";
	return 0;
}
