#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	int k;
	cin >> s >> k;
	
	vector<int> v;
	v.push_back(0);
	
	for(int x=1;x<s.length();x++){
		while(!v.empty() && s[x] < s[v.back()] && v.size()+(s.length()-x-1) >= k){
			v.pop_back();
		}
		v.push_back(x);
	}
	
	for(int x=0;x<k;x++){
		cout << s[v[x]];
	}
	cout << "\n";
    return 0;
}

