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

	int n, m;
	cin >> n >> m;
	
	vector<string> ans;
	vector<string> v;
	int cnt[30][5], mn = m-1;
	fill(cnt[0], cnt[30], n);
	
	string s;
	s.push_back('2');
	for(int y=0;y<m-1;y++) s.push_back('0');
	
	for(int x=0;x<n;x++){
		for(int y=m-1;y>0;y--){
			if(s[y] > '2'){
				s[y] = '0';
				s[y-1]++;
				mn = min(mn, y-1);
			} else {
				break;
			}
		}
		
		for(int y=0;y<m;y++){
			cnt[y][(s[y] - '0')]--;
		}
		
		ans.push_back(s);
		s.back()++;
	}
	
	
	for(int i=0;i<2;i++){
		s.clear();
		s.push_back('0'+i);
		for(int x=1;x<mn;x++){
			s.push_back('0'+i+1);
		}
		for(int x=mn;x<m;x++){
			s.push_back('0');
		}
		
		int cnt2 = 0;
		while(cnt2 < n){
			for(int y=m-1;y>0;y--){
				if(s[y] > '2'){
					s[y] = '0';
					s[y-1]++;
				} else {
					break;
				}
			}
			
			bool ok = true;
			for(int y=0;y<m;y++){
				if(cnt[y][(s[y] - '0')] == 0){
					ok = false;
					break;
				}
			}
			
			if(ok){
				for(int y=0;y<m;y++){
					cnt[y][(s[y] - '0')]--;
				}
				
				ans.push_back(s);
				cnt2++;
			}
			s.back()++;
		}
	}
	
	for(auto s : ans){
		cout << s << "\n";
	}
    return 0;
}

