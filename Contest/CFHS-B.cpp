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

bool check(string a, string b, int pos, string cur){
	if(cur.length() == b.length()){
		return (cur == b);
	}
	
	bool ans = false;	
	string tmp = cur;
	for(int x=pos+1;x<a.length();x++){
		tmp += a[x];
		
		if(tmp[tmp.length()-1] == b[tmp.length()-1]){
			ans |= check(a, b, x, tmp);
		} else {
			break;
		}
	}
	
	tmp = cur;
	for(int x=pos-1;x>=0;x--){
		tmp += a[x];
		
		if(tmp[tmp.length()-1] == b[tmp.length()-1]){
			ans |= check(a, b, x, tmp);
		} else {
			break;
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		string a, b;
		cin >> a >> b;
		
		bool possible = false;
		for(int x=0;x<a.length();x++){
			string tmp;
			for(int y=x;y<a.length();y++){
				tmp += a[y];
				
				string tmp2 = tmp;
				if(tmp2.back() != b[tmp2.length()-1]) break;
				if(tmp2 == b){
					possible = true;
					break;
				}
				
				for(int z=y-1;z>=0;z--){
					tmp2 += a[z];
					
					if(tmp2.back() != b[tmp2.length()-1]) break;
					if(tmp2 == b){
						possible = true;
						break;
					}
				}
				
				if(possible) break;
			}
			
			if(possible) break;
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

