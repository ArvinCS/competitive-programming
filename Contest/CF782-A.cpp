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
		int n, r, b;
		cin >> n >> r >> b;
		
		int cnt = r/(b+1);
		int cnt2 = r%(b+1);
		int cnt1 = (b+1)-cnt2;
		
		string ans;
		while(cnt2 > 0){
			for(int x=0;x<cnt+1;x++){
				ans.push_back('R');
			}
			if(cnt2 != 1 || cnt1 != 0) ans.push_back('B');
			cnt2--;
		}
		while(cnt1 > 0){
			for(int x=0;x<cnt;x++){
				ans.push_back('R');
			}
			if(cnt1 != 1) ans.push_back('B');
			cnt1--;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

