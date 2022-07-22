#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n,m,x,y;
		cin >> n >> m >> x >> y;
		
		string data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		y = min(y, (2 * x));
		int ans = 0;
		for(int i=0;i<n;i++){
			int j = 0;
			while(j<m){
				if(data[i][j] == '*'){
					j++;
					continue;
				}
				
				if(j+1 < m && data[i][j+1] == '.'){
					ans += y;
					j += 2;
				} else {
					ans += x;
					j++;
				}
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}
