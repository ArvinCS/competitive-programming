#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	// 10 4
	// 4 3 4 3 2 3 2 1 0 1
	// 0 0 1 0 0 1 0 0 0 0
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int height[n];
		for(int x=0;x<n;x++) cin >> height[x];
		
		//cout << "0 ";
		int total = 0;
		for(int x=1;x<k-1;x++){
			if(height[x-1] < height[x] && height[x] > height[x+1]){
				total++;
			}
			//cout << height[x] << " ";
		}
		//cout << "\n";
		int ans = total+1, l = 0;
		for(int x=k;x<n;x++){ // linear
			if(height[x-k] < height[x-k+1] && height[x-k+1] > height[x-k+2]) total--;
			if(height[x-2] < height[x-1] && height[x-1] > height[x]) total++;
			if(total + 1 > ans){
				ans = total + 1;
				l = x-k+1;
			}
		}
		
		cout << ans << " " << l + 1 << "\n";
	}
	
    return 0;
}
