#include <bits/stdc++.h>

using namespace std;

const int maxC = 105;

int grid[maxC][maxC][maxC];
int d, h, l;

int calc(int x, int y, int a, int b){
	int best = 0, cnt = 0;
	for(int i=0;i<d;i++){
		int sum = grid[i][y][b] - (x > 0 ? grid[i][x-1][b] : 0) - (a > 0 ? grid[i][y][a-1] : 0) + ((x > 0 && a > 0) ? grid[i][x-1][a-1] : 0);
		
		if(sum != (y-x+1)*(b-a+1)){
			cnt = 0;
		} else {
			cnt += sum;
		}
		best = max(best, cnt);
	}
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> d >> h >> l;
	
	for(int i=0;i<d;i++){
		for(int x=0;x<h;x++){
			int sum = 0;
			for(int y=0;y<l;y++){
				int val;
				cin >> val;
				
				sum += val;
				grid[i][x][y] = sum + (x > 0 ? grid[i][x-1][y] : 0);
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<h;x++){ // O(N^3 x logN x N)
		for(int a=0;a<l;a++){
			for(int y=x;y<h;y++){
				int left = a+1, right = l-1;
				while(left <= right){
					int b = (left+right) >> 1;
					
					int sum = calc(x, y, a, b);
					int sum2 = calc(x, y, a, b-1);
					
					if(sum > sum2){
						ans = max(ans, sum);
						left = b+1;
					} else {
						ans = max(ans, sum2);
						right = b-1;
					}
				}
			}
		}
	}
	
	for(int i=0;i<d;i++){
		for(int )
	}
	cout << ans << "\n";
    return 0;
}

