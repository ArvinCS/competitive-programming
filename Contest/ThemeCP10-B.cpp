#include <bits/stdc++.h>

using namespace std;

#define ll long long

const double eps = 1e-7;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int cnt[26][s.length()][26];
	fill(*cnt[0], *cnt[26], 0);
	
	for(int x=0;x<s.length();x++){
		for(int y=0;y<s.length();y++){
			cnt[(s[x] - 'a')][y][s[(x+y)%s.length()] - 'a']++;
		}
	}
	
	int sum = 0;
	
	for(int x=0;x<26;x++){
		if(cnt[x][0][x] > 0){
			int mx = 0;
			for(int y=1;y<s.length();y++){
				int cur = 0;
				
				for(int z=0;z<26;z++){
					if(cnt[x][y][z] == 1){
						cur++;
					}
				}
				
				mx = max(mx, cur);
			}
			sum += mx;
		}
	}
	
	double ans = sum * 1.0 / s.length();
	cout << fixed << setprecision(9) << ans << "\n";
    return 0;
}

