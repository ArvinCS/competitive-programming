#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	bool zigzag = true;
	for(int x=0;x<n;x++){
		if(s[x] == s[(x+1)%n]){
			zigzag = false;
		}
	}
	
	if(zigzag){
		if(k&1){
			for(int x=0;x<n;x++){
				if(s[x] == 'W') s[x] = 'B';
				else s[x] = 'W';
			}
		}
		cout << s << "\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		s.push_back(s[x]);
	}
	
	vector<pair<int, int>> v;
	int pos = 0;
	for(int x=1;x<s.length();x++){
		if(s[x-1] == s[x]){
			pos = x;
			break;
		}
	}
	
	for(int x=pos;x<s.length();x++){
		if(s[x] == s[(x+1)%n]){
			if(pos+1 <= x-1){
				v.push_back({pos+1, x-1});
			}
			pos = x+1;
		}
	}
	
	string ans = s;
	for(auto p : v){
		int length = p.second-p.first+1;
		
		for(int x=0;x<min(k, length/2);x++){
			ans[(p.first+x)%n] = s[(p.first-1+n)%n];
			ans[(p.second-x+n)%n] = s[(p.second+1)%n];
		}
		if(length&1 && k >= (length+1)/2){
			int pos = (p.first+(length+1)/2-1+n)%n;
			
			int cnt = (s[pos] == 'B') + (s[(p.first-1+n)%n] == 'B') + (s[(p.second+1)%n] == 'B');
			ans[pos] = (cnt > 1 ? 'B' : 'W');
		}
		
		for(int x=k;x<(length+1)/2;x++){
			if(k&1){
				if(s[(p.first+x)%n] == 'W'){
					ans[(p.first+x)%n] = 'B';
				} else {
					ans[(p.first+x)%n] = 'W';
				}
				
				if(s[(p.second-x+n)%n] == 'W'){
					ans[(p.second-x+n)%n] = 'B';
				} else {
					ans[(p.second-x+n)%n] = 'W';
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

