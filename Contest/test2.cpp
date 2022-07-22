#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3;
const int maxBit = (1 << maxN);

int table[maxBit];
bool exist[maxBit];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	while(q--){
		int n;
		cin >> n;
		
		string s, t;
		cin >> s >> t;
		
		int ans = 1e9;
		for(int x=0;x<n;x++){
			int pos = x;
			for(int y=0;y<n;y++){
				if(pos >= n) break;
				if(s[y] == t[pos]){
					pos++;
				}
			}
			
			if(pos-x > 0){
				int step = s.length()-(pos-x);
				ans = min(ans, step);
			} else {
				ans = 1e9;
				break;
			}
		}
		
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		
		if(s != t){
			ans = 1e9;
		}
		
		cout << (ans != 1e9 ? ans : -1) << "\n";
	}
    return 0;
}

