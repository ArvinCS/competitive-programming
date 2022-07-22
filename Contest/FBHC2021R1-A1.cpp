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
//	freopen("weak_typing_chapter_1_input.txt","r",stdin);
//	freopen("weak_typing_chapter_1_output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		vector<char> v;
		for(int x=0;x<n;x++){
			if(s[x] != 'F'){
				v.push_back(s[x]);
			}
		}
		
		int ans = 0;
		for(int x=0;x+1<v.size();x++){
			if(v[x] != v[x+1]){
				ans++;
			}
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

