#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s, t;
		cin >> s >> t;
		
		vector<int> v[26];
		for(int x=0;x<s.length();x++){
			v[(s[x] - 'A')].push_back(x);
		}
		
		bool valid = true;
		int lst = s.length();
		for(int x=t.length()-1;x>=0;x--){
			int idx = (t[x] - 'A');
			if(v[idx].empty() || v[idx].back() >= lst){
				valid = false;
				break;
			}
			lst = v[idx].back();
			v[idx].pop_back();
		}
		
		cout << (valid ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

