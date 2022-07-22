#include "towns.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int find_town(int n) {
	vector<int> v; // v for outgoing edges 1, w for outgoing edges 0
	for(int x=0;x<n;x++){
		v.push_back(x);
	}
	
	vector<int> w[2];
    int last = -1, id = 1;
    bool recent = false;
    set<pair<int, int>> st;
	while(v.size() > 1){
		int a = v.back();
		v.pop_back();
		int b = v.back();
		v.pop_back();
		
		st.insert({a, b});
		st.insert({b, a});
		if(check_road(a, b)){
			if(last != b){
				last = b;
				id ^= 1;
				recent = true;
			}
			
			v.push_back(b);
			w[id].push_back(a);
		} else {
			if(last != a){
				last = a;
				id ^= 1;
				recent = true;
			}
			
			v.push_back(a);
			w[id].push_back(b);
		}
	}
	
	int cnt = 0;
	for(int i=0;i<2;i++){
//		cout << " --- \n";
		vector<int> new_w;
		for(auto node : w[i]){
			if(!st.count({node, v[0]})){
				st.insert({node, v[0]});
				st.insert({v[0], node});
				
				if(cnt >= 2){
					new_w.push_back(node);
					continue;
				}
				
				if(check_road(v[0], node)){
					cnt++;
					new_w.push_back(node);
				}
			} else {
				new_w.push_back(node);
			}
		}
		swap(w[i], new_w);
		
		while(w[i].size() > 1){
			int a = w[i].back();
			w[i].pop_back();
			int b = w[i].back();
			w[i].pop_back();
			
//			cout << a << " " << b << "\n";
			if(check_road(a, b)){
				w[i].push_back(b);
			} else {
				w[i].push_back(a);
			}
		}
	}
	
	if(cnt <= 1){
		return v[0];
	}
	
	for(int i=0;i<2;i++){
		if(w[i].empty()) continue;
		
		int cnt = 0;
		for(int x=0;x<n;x++){
			if(w[i][0] == x) continue;
			if(check_road(w[i][0], x)){
				cnt++;
			}
		}
		
		if(cnt <= 1){
			return w[i][0];
		}
	}
 	return -1;
}
