#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t, n;
	cin >> t;
	while(t--){
		cin >> n;	
		
		char matrix[n][n];
		for(short x=0;x<n;x++){
			for(short y=0;y<n;y++) cin >> matrix[x][y];
		}
		
		bool possible = true;
		for(short x=0;x<n-1 && possible;x++){
			for(short y=0;y<n-1;y++){
				if(matrix[x][y] - '0' == 1){
					if(matrix[x+1][y] - '0' == 0 && matrix[x][y+1] - '0' == 0){
						possible = false;
						break;
					}
				}
			}
		}
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}
