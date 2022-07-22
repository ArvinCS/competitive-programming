#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}	
	
	set<vector<int>> st;
	for(int state=1;state<(1 << n);state++){
		vector<int> v;
		for(int y=0;y<n;y++){
			if(state&(1 << y)){
				v.push_back(a[y]);
			}
		}
		
		bool valid = true;
		vector<int> q;
		int prv = 0;
		for(auto val : v){
			if(abs(prv) == abs(val)){
				valid = false;
				break;
			}
			if(val > 0){
				if(q.empty() || q.back() == val){
					valid = false;
					break;
				}
				
				q.pop_back();
			} else {
				q.push_back(-val);
			}
			prv = val;
		}
		
		if(valid && q.empty()){
			st.insert(v);
		}
	}
	
//	for(auto v : st){
//		for(auto val : v){
//			cout << val << " ";
//		}
//		cout << "\n";
//	}
	cout << st.size() << "\n";
	return 0;
}
