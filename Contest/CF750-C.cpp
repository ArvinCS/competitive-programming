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
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int ans = inf_int;
		for(char c='a';c<='z';c++){
			int cnt = 0;
			int left = 0, right = n-1;
			while(left < right){
				if(s[left] != s[right]){
					if(s[left] == c){
						left++;
						cnt++;
					} else if(s[right] == c){
						right--;
						cnt++;
					} else {
						cnt = inf_int;
						break;
					}
				} else {
					left++;
					right--;
				}
			}
			
			ans = min(ans, cnt);
		}
		
		cout << (ans != inf_int ? ans : -1) << "\n";
	}

    return 0;
}

