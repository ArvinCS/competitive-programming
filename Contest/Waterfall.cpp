#include <iostream>

using namespace std;

short v,h,n;

struct Point {
	int x1,y1,x2,y2;
};

unsigned long long solve(Point batu[]){
	bool matrix[v+1][h+1] = { false };
	unsigned long long table[v+1][h+1] = {};
	fill(&matrix[0][0], &matrix[0][0] + (v+1)*(h+1), false);
	
	for(int i=0;i<n;i++){
		for(int x=batu[i].x1;x<=batu[i].x2;x++){
			for(int y=batu[i].y1;y<=batu[i].y2;y++) matrix[x][y] = true;
		}
	}
	
	for(int x=v-1;x>=0;x--){
		for(int y=1;y<=h;y++){
			if(matrix[x][y]) continue;
			if(matrix[x+1][y]){
				int y1 = y, y2 = y;
				while(y1-- && y >= 1){
					if(!matrix[x+1][y1]){
						break;
					}
				}
				while(y2++ && y2 <= h){
					if(!matrix[x+1][y2]){
						break;
					}
				}
				table[x][y] = 1 + table[x+1][y1] + table[x+1][y2]; 
				//cout << "crup " << x << " - " << y << "\n";
			} else {
				table[x][y] = table[x+1][y];
			}
		}
	}
	
	/*for(int x=0;x<=v;x++){
		for(int y=1;y<=h;y++){
			cout << table[x][y];
		}
		cout << "\n";
	}*/
	unsigned long long best = 0;
	for(int x=1;x<=h;x++){
		best = max(best, table[0][x]);
	}
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> v >> h >> n;
	
	Point batu[n];
	for(int x=0;x<n;x++){
		cin >> batu[x].x1 >> batu[x].y1 >> batu[x].x2 >> batu[x].y2;
	}
	
	cout << solve(batu) << "\n";
    return 0;
}
