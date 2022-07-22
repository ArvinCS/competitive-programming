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

	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int m = s.length();
		bool possible = false;
		
		int last[26];
		fill(last, last+26, -1);
		
		for(int x=0;x<m;x++){
			last[(s[x] - 'a')] = x;	
		}
		
		vector<pair<int, int>> v;
		for(int x=0;x<26;x++){
			if(last[x] >= 0){
				v.push_back({last[x], x});
			}
		}
		
		sort(v.begin(), v.end());
		
		string a, b;
		
		for(int x=0;x<v.size();x++){
			b.push_back(('a' + v[x].second));
		}
		
		int cnt[26];
		fill(cnt, cnt+26, 0);
		string cur;
		
		for(int x=0;x<m;x++){
			cur.push_back(s[x]);
			cnt[(s[x] - 'a')]++;
			
			int sum = 0, n = x+1;
			for(int y=0;y<b.length();y++){
				sum += cnt[(b[y] - 'a')];
				n += x+1-sum;
			}
			
			if(n == m){
				possible = true;
				a = cur;
				break;
			}
		}
		
		string res = a;
		string tmp = a;
		for(int x=0;x<b.length();x++){
			string tmp2;
			for(int y=0;y<tmp.length();y++){
				if(b[x] == tmp[y]) continue;
				
				res.push_back(tmp[y]);
				tmp2.push_back(tmp[y]);
			}
			
			swap(tmp, tmp2);
		}
		
		if(res != s){
			possible = false;
		}
		
		if(possible){
			cout << a << " " << b << "\n";
		} else {
			cout << "-1\n";
		}
	}

    return 0;
}

