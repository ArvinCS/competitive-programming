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
	
	us t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int n = s.length();
		pair<int, int> prefix[n];
		for(int x=0;x<n;x++){
			if(s[x] == 'U'){
				prefix[x].first = 0;
				prefix[x].second = 1;
			} else if(s[x] == 'D'){
				prefix[x].first = 0;
				prefix[x].second = -1;
			} else if(s[x] == 'L'){
				prefix[x].first = -1;
				prefix[x].second = 0;
			} else {
				prefix[x].first = 1;
				prefix[x].second = 0;
			}
			
			if(x > 0){
				prefix[x].first += prefix[x-1].first;
				prefix[x].second += prefix[x-1].second;	
			}
		}
		
		int index = -1;
		for(int x=0;x<n;x++){
			int obsX = prefix[x].first, obsY = prefix[x].second;
			int curX = 0, curY = 0;
			for(int y=0;y<n;y++){
				if(s[y] == 'U' && !(curX == obsX && curY+1 == obsY)){
					curY++;
				} else if(s[y] == 'D' && !(curX == obsX && curY-1 == obsY)){
					curY--;
				} else if(s[y] == 'R' && !(curX+1 == obsX && curY == obsY)){
					curX++;
				} else if(s[y] == 'L' && !(curX-1 == obsX && curY == obsY)){
					curX--;
				}
//				cout << curX << " - " << curY << "\n";
			}
			
			if(curX == 0 && curY == 0){
//				cout << x << "\n";
				index = x;
				break;
			}
		}
		
		if(index >= 0) cout << prefix[index].first << " " << prefix[index].second << "\n";
		else cout << "0 0\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

