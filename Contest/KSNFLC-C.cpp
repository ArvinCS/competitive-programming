#include <bits/stdc++.h>

using namespace std;

#define ll long long

set<int> st;

bool add(int x){
	st.insert(x);
	cout << "+ " << x << endl;
	
	string res;
	cin >> res;
	
	return (res == "YES");
}

bool remove(int x){
	if(!st.count(x)) return false;
	
	st.erase(st.find(x));
	cout << "- " << x << endl;
	
	string res;
	cin >> res;
	
	return (res == "YES");
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int ans = -1;	
	int cur = 1;
	for(int x=1;x<=11;x++){
		if(add(cur)){
			ans = cur;
			break;
		}
		
		cur += 140;
	}
	cur -= 140;
	
	if(ans == -1){
		for(int x=2;x<=139;x++){
			if(add(x)){
				ans = x;
				break;
			}
		}
	}
	
	set<int> prv, nw;
	for(auto a : st){
		for(auto b : st){
			nw.insert(abs(a-b));
		}
	}
	
	remove(ans);
	
	for(auto a : st){
		for(auto b : st){
			prv.insert(abs(a-b));
		}
	}
	
	vector<int> v;
	for(auto a : nw){
		if(!prv.count(a)) v.push_back(a);
	}
	
	cur = 1e6;
	add(cur);
	
	for(auto a : v){
		if(add(cur+a)){
			ans = a;
			break;		
		}
		
		cur += 300000;
		add(cur);
	}
	
	cout << "! " << ans << endl;
    return 0;
}

