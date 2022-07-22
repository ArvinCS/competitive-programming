#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string row[2];
		cin >> row[0] >> row[1];
		
		bool possible = true;
		
		int pos = 0;
		for(int x=0;x<n;x++){
			if(row[pos][x] >= '3'){
				if(row[abs(pos-1)][x] <= '2'){
					possible = false;
					break;
				} else {
					pos = abs(pos-1);	
				}
			}
		}
		if(possible && pos == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}
