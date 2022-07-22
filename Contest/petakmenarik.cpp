#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,m,k;
	cin >> n >> m >> k;
	int data[n][m];
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> data[x][y];
		}
	}
	
	bool found = false;
	for(int y=0;y<m && !found;y++){
		for(int x=0;x<n && !found;x++){
			int total = 1;
			
			int kiri = y-1;
			int kanan = y+1;
			int atas = x-1;
			int bawah = x+1;
			
			if(kiri >= 0) total = total * data[x][kiri];
			if(kanan <= m-1) total = total * data[x][kanan];
			if(atas >= 0) total = total * data[atas][y];
			if(bawah <= n-1) total = total * data[bawah][y];
			
			if(total == k){
				cout << (x+1) << " " << (y+1) << "\n";
				found = true;
			}
		}
	}
	
	if(!found){
		cout << "0 0\n";
	}
    return 0;
}
