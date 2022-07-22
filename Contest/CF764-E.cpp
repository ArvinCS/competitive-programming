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
		int n, m;
		cin >> n >> m;
		
		string s[n+1];
		for(int x=0;x<=n;x++){
			cin >> s[x];
		}
		
		pair<int, int> two[26][26], three[26][26][26];
		fill(two[0], two[26], make_pair(-1, -1));
		fill(*three[0], *three[26], make_pair(-1, -1));
		
		for(int x=0;x<n;x++){
			for(int y=0;y+1<m;y++){
				two[(s[x][y] - '0')][(s[x][y+1] - '0')] = make_pair(x, y);
			}
			for(int y=0;y+2<m;y++){
				three[(s[x][y] - '0')][(s[x][y+1] - '0')][(s[x][y+2] - '0')] = make_pair(x, y);
			}	
		}
		
		bool valid = true, triple = false;
		vector<tuple<int, int, int>> ans;
		int pos = 0;
		while(pos < m){
			if(pos < 0){
				valid = false;
				break;
			}
			
			if(triple){
				if(pos+2 >= m){
					valid = false;
					break;
				}
				
				pair<int, int> p = three[(s[n][pos] - '0')][(s[n][pos+1] - '0')][(s[n][pos+2] - '0')];
				if(p.first == -1){
					valid = false;
					break;
				}
				
				ans.push_back(make_tuple(p.first, p.second, p.second+2));
				pos += 3;
				triple = false;
			} else {
				if(pos+1 >= m){
					pos -= 2;
					triple = true;
					if(!ans.empty()) ans.pop_back();
					continue;
				}
				
				pair<int, int> p = two[(s[n][pos] - '0')][(s[n][pos+1] - '0')];
				if(p.first == -1){
					pos -= 2;
					triple = true;
					if(!ans.empty()) ans.pop_back();
					continue;
				}
				
				ans.push_back(make_tuple(p.first, p.second, p.second+1));
				pos += 2;
			}
//			cout << pos << " " << triple << "\n";
		}
		
		if(!valid){
			cout << "-1\n";
			continue;
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << get<1>(p)+1 << " " << get<2>(p)+1 << " " << get<0>(p)+1 << "\n";
		}
	}
	
    return 0;
}

