#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 50;
int matrix[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n,k;
		cin >> n >> k;
		
		int diagonal = ceil(k/2);
		
		for(int x=0;x<n;x++){
			int value = (x == n-1 && n%2==1 ? diagonal-1 : diagonal);
			int sum = (value == 1 ? 2 : 1);
			for(int y=0;y<n;y++){
				if(x == y){
					matrix[x][y] = value;
					if(sum == value) sum++;
				} else {
					matrix[x][y] = sum;
					sum++;
				}
				cout << matrix[x][y] << " ";
			}
			cout << "\n";
		}
		
		//cout << "Case #" << c << ": " << ans << "\n";
	}	
	
    return 0;
}
