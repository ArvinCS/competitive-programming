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
		int n;
		cin >> n;
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
			p[x]--;
		}
		
		vector<int> ans;
		for(int x=n-1;x>=4;x--){
			int pos = -1;
			for(int y=0;y<n;y++){
				if(p[y] == x){
					pos = y;
					break;
				}
			}
			
			if(pos % 2 == (ans.size()+1) % 2){
				for(int y=ans.size()%2;y<x;y+=2){
					if(y != pos && y+1 != pos){
						ans.push_back(y);
						swap(p[y], p[y+1]);
						break;
					}
				}
			}
			
			for(int y=pos;y<x;y++){
				ans.push_back(y);
				swap(p[y], p[y+1]);
			}
		}
		
		if(n == 2){
			if(!is_sorted(p, p+n)){
				ans.push_back(0);
				swap(p[0], p[1]);
			}
		}
		if(n >= 4){
			int pos = -1;
			for(int y=0;y<n;y++){
				if(p[y] == 3){
					pos = y;
					break;
				}
			}
			
			if(pos != 3){
				if(ans.size() % 2 == 1 && pos == 2){
					ans.push_back(1);
					swap(p[1], p[2]);
					ans.push_back(2);
					swap(p[2], p[3]);
					ans.push_back(1);
					swap(p[1], p[2]);
					ans.push_back(2);
					swap(p[2], p[3]);
				} else {
					if(pos % 2 == (ans.size()+1) % 2){
						for(int y=ans.size()%2;y<3;y+=2){
							if(y != pos && y+1 != pos){
								ans.push_back(y);
								swap(p[y], p[y+1]);
								break;
							}
						}
					}
					
					for(int y=pos;y<3;y++){
						ans.push_back(y);
						swap(p[y], p[y+1]);
					}
				}
			}
		}
		if(n >= 3){
			int turn = ans.size()%2;
			while(!is_sorted(p, p+n)){
				ans.push_back(turn);
				swap(p[turn], p[turn+1]);
				turn ^= 1;
			}
		}
		
//		cout << is_sorted(p, p+n) << "\n";
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

