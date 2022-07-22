#include <iostream>

using namespace std;

bool valid(int n, int m, bool grid[100][100]){
	bool search = false;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(!grid[x][y]){
				int bakteri = 0;
				if(grid[x+1][y]) bakteri++;
				if(grid[x-1][y]) bakteri++;
				if(grid[x][y+1]) bakteri++;
				if(grid[x][y-1]) bakteri++;
				if(bakteri >= 2){
					grid[x][y] = true;
					search = true;
				} 
			}
		}
	}	
	if(search){
		return valid(n,m,grid);
	} else {
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(!grid[x][y]){
					return false;
				}
			}
		}
		return true;
	}
}

bool brute(int n, int m, int k, int i, bool grid[100][100]){
	if(i >= k){
		bool temp[100][100];
		copy(&grid[0][0], &grid[0][0]+n*m, &temp[0][0]);
		if(valid(n,m,grid)){
			cout << "YA\n";
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					if(temp[x][y]) cout << "X";
					else cout << ".";
				}
				cout << "\n";
			}
			return true;
		}
		return false;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(!grid[x][y]){
				grid[x][y] = true;
				bool result = brute(n,m,k,i+1,grid);
				grid[x][y] = false;
				if(result){
					return true;
				}
			}
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,m,k;
	
	cin >> n >> m >> k;
	
	bool grid[100][100] = { false };
	if(!brute(n,m,k,0,grid)){
		cout << "TIDAK\n";
	}
    return 0;
}
