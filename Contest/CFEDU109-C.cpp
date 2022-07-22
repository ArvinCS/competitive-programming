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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		ll data[n];
		map<ll, int> mp;
		vector<ll> leftOdd, leftEven, rightOdd, rightEven;
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		set<ll> st, st2, st3, st4;
		for(int x=0;x<n;x++){
			char c;
			cin >> c;
			
			bool right = (c == 'R');
			if(right){
				if(data[x]&1) st2.insert(data[x]);
				else st4.insert(data[x]);
			} else {
				if(data[x]&1) st.insert(data[x]);
				else st3.insert(data[x]);
			}
		}
		
		for(auto v : st){
			auto it = st2.lower_bound(v);
			if(it == st2.begin()) continue;
			
			it--;
			
			int meet = (v+*it)/2;
			
			mp[v] = mp[*it] = abs(v-meet);
			st2.erase(it);
		}
		
		vector<ll> tmp;
		for(auto v : st){
			if(mp[v] == 0) tmp.push_back(v);
		}
		swap(tmp, leftOdd);
		tmp.clear();
		for(auto v : st2){
			if(mp[v] == 0) tmp.push_back(v);
		}
		swap(tmp, rightOdd);
		
		for(auto v : st3){
			auto it = st4.lower_bound(v);
			if(it == st4.begin()) continue;
			
			it--;
			
			int meet = (v+*it)/2;
			
			mp[v] = mp[*it] = abs(v-meet);
			st4.erase(it);
		}
		
		tmp.clear();
		for(auto v : st3){
			if(mp[v] == 0) tmp.push_back(v);
		}
		swap(tmp, leftEven);
		tmp.clear();
		for(auto v : st4){
			if(mp[v] == 0) tmp.push_back(v);
		}
		swap(tmp, rightEven);
		
		// odd
		for(int x=0;x+1<leftOdd.size();x+=2){
			int meet = (leftOdd[x]+leftOdd[x+1])/2 - (leftOdd[x]);
			
			mp[leftOdd[x]] = mp[leftOdd[x+1]] = (leftOdd[x+1]-meet);
		}
		for(int x=rightOdd.size()-1;x-1>=0;x-=2){
			int meet = (rightOdd[x]+rightOdd[x-1])/2 + (m - rightOdd[x]);
			
			mp[rightOdd[x]] = mp[rightOdd[x-1]] = (meet-rightOdd[x-1]);
		}
		// even
		for(int x=0;x+1<leftEven.size();x+=2){
			int meet = (leftEven[x]+leftEven[x+1])/2 - (leftEven[x]);
			
			mp[leftEven[x]] = mp[leftEven[x+1]] = (leftEven[x+1]-meet);
		}
		for(int x=rightEven.size()-1;x-1>=0;x-=2){
			int meet = (rightEven[x]+rightEven[x-1])/2 + (m - rightEven[x]);
			
			mp[rightEven[x]] = mp[rightEven[x-1]] = (meet-rightEven[x-1]);
		}
		
		// odd
		if(leftOdd.size() % 2 == 1 && rightOdd.size() % 2 == 1){
			if(leftOdd.back() <= m-rightOdd.front()){
				int tmp = rightOdd.front()+leftOdd.back();
				int meet = (tmp)/2 + (m-tmp);
				
				mp[rightOdd.front()] = mp[leftOdd.back()] = (leftOdd.back() + meet);
			} else {
				int tmp = leftOdd.back()-(m-rightOdd.front());
				int meet = (tmp+m)/2 - (tmp);
				
				mp[leftOdd.back()] = mp[rightOdd.front()] = (m-rightOdd.front() + (m-meet));
			}
		}
		
		// even
		if(leftEven.size() % 2 == 1 && rightEven.size() % 2 == 1){
			if(leftEven.back() <= m-rightEven.front()){
				int tmp = rightEven.front()+leftEven.back();
				int meet = (tmp)/2 + (m-(tmp));
				
				mp[leftEven.back()] = mp[rightEven.front()] = (leftEven.back() + meet);
			} else {
				int tmp = leftEven.back()-(m-rightEven.front());
				int meet = (tmp+m)/2 - (tmp);
				
				mp[leftEven.back()] = mp[rightEven.front()] = (m-rightEven.front() + (m-meet));
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			if(mp[data[x]] == 0) cout << "-1";
			else cout << mp[data[x]];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

