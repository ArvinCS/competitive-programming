#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t, num;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> list[n+1];
		bool princess[n+1] = { false };
		bool prince[n+1] = { false };
		
		for(int x=1;x<=n;x++){
			int k;
			cin >> k;
			for(int y=0;y<k;y++){
				cin >> num;
				list[x].push_back(num);
			}
		}
		
		// solve
		for(int x=1;x<=n;x++){
			for(int y=0;y<list[x].size();y++){
				if(!prince[list[x][y]]){
					princess[x] = true;
					prince[list[x][y]] = true;
					break;
				}
			}
		}
		
		bool optimal = true;
		pair<int, int> improve;
		for(int x=1;x<=n;x++){
			if(!princess[x]){
				for(int y=1;y<=n;y++){
					if(!prince[y]){
						optimal = false;
						improve.first = x;
						improve.second = y;
						break;
					}
				}
			}
		}
		
		if(optimal) cout << "OPTIMAL\n";
		else {
			cout << "IMPROVE\n";
			cout << improve.first << " " << improve.second << "\n";
		}
	}
	
    return 0;
}
