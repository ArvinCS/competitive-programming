#include <bits/stdc++.h>

using namespace std;

#define ll long long

string ask(vector<int> v, vector<int> w){
	cout << "? " << v.size() << " " << w.size() << endl;
	for(int x=0;x<v.size();x++){
		if(x > 0) cout << " ";
		cout << v[x];
	}
	cout << endl;
	
	for(int x=0;x<w.size();x++){
		if(x > 0) cout << " ";
		cout << w[x];
	}
	cout << endl;
	
	string res;
	cin >> res;
	
	assert(res != "WASTED");
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int cnt = 0;
		int pos = 1;
		for(int x=0;x<10;x++){
			int sz = (1 << x);
			if(pos+sz > n) continue;
			if(sz > pos) continue;
			
			vector<int> v, w;
			for(int y=1;y<=sz;y++){
				v.push_back(y);
			}
			for(int y=pos+1;y<=pos+sz;y++){
				w.push_back(y);
			}
			
			cnt++;
			if(ask(v, w) == "EQUAL"){
				pos += sz;
			} else {
				break;
			}
		}
		for(int x=log2(pos);x>=0;x--){
			int sz = (1 << x);
			if(pos+sz > n) continue;
			if(sz > pos) continue;
			
			vector<int> v, w;
			for(int y=1;y<=sz;y++){
				v.push_back(y);
			}
			for(int y=pos+1;y<=pos+sz;y++){
				w.push_back(y);
			}
			
			cnt++;
			if(ask(v, w) == "EQUAL"){
				pos += sz;
			}
		}
		
		int p1 = 1, p2 = pos+1;
		pos = p2;
		for(int x=0;x<10;x++){
			int sz = (1 << x);
			if(pos+sz > n) continue;
			if(p2+sz-1 > pos) continue;
			
			vector<int> v, w;
			for(int y=1;y<=sz;y++){
				v.push_back(p2+y-1);
			}
			for(int y=pos+1;y<=pos+sz;y++){
				w.push_back(y);
			}
			
			cnt++;
			if(ask(v, w) == "EQUAL"){
				pos += sz;
			} else {
				break;
			}
		}
		for(int x=log2(pos-p1);x>=0;x--){
			int sz = (1 << x);
			if(pos+sz > n) continue;
			if(p2+sz-1 > pos) continue;
			
			vector<int> v, w;
			for(int y=1;y<=sz;y++){
				v.push_back(p2+y-1);
			}
			for(int y=pos+1;y<=pos+sz;y++){
				w.push_back(y);
			}
			
			cnt++;
			if(ask(v, w) == "EQUAL"){
				pos += sz;
			}
		}
		
		{
			vector<int> v, w;
			v.push_back(p1);
			w.push_back(p2);
			
			cnt++;
			if(ask(v, w) == "SECOND"){
				cout << "! " << p1 << endl;
				continue;
			}
		}
		
		if(pos == n){
			cout << "! " << p2 << endl;
			continue;
		}
		
		bool found = false;
		for(int x=1;x<=50-cnt;x++){
			int idx = (rng()-1)%n + 1;
			while(idx <= pos){
				idx = (rng()-1)%n + 1;
			}
			
			vector<int> v, w;
			v.push_back(p1);
			w.push_back(idx);
			
			if(ask(v, w) == "SECOND"){
				cout << "! " << p1 << endl;
				found = true;
				break;
			}
		}
		
		if(!found){
			cout << "! " << p2 << endl;
		}
	}
	
    return 0;
}

