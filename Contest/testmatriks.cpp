#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	cout << "Matrix A:\n";
	int matrixA[a][b];
	for(int x=0;x<a;x++){
		for(int y=0;y<b;y++) cin >> matrixA[x][y];
	}
	
	cout << "Matrix B:\n";
	int matrixB[c][d];
	for(int x=0;x<c;x++){
		for(int y=0;y<d;y++) cin >> matrixB[x][y];
	}
	
	cout << "Hasil:\n";
	for(int x=0;x<a;x++){
		for(int y=0;y<d;y++){
			int ans = 0;
			for(int i=0;i<c;i++){
				ans += matrixA[x][i] + matrixB[i][y];
				cout << matrixA[x][i] << " " << matrixB[i][y] << "\n";
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
    return 0;
}

