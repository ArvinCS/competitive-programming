#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n;
		cin >> n;
		int sumDiagonal = 0;
		int matrix[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> matrix[x][y];
				if(x==y) sumDiagonal += matrix[x][y];
			}
		}
		
		int repRows = 0, repCols = 0;
		for(int x=0;x<n;x++){
			int temp1[n];
			int temp2[n];
			fill_n(temp1, n, 1);
			fill_n(temp2, n, 1);
			bool repeatRow = false;
			bool repeatCols = false;
			for(int y=0;y<n;y++){
				if(!repeatRow){
					int row = matrix[x][y]-1;
					if(temp1[row] >= 0){
						temp1[row] = -temp1[row];
					} else {
						repRows++;
						repeatRow = true;
					}
				}
				if(!repeatCols){
					int col = matrix[y][x]-1;
					if(temp2[col] >= 0){
						temp2[col] = -temp2[col];
					} else {
						repCols++;
						repeatCols = true;
					}
				}
			}
		}
		
		cout << "Case #" << c << ": " << sumDiagonal << " " << repRows << " " << repCols << "\n";
	}
    return 0;
}
