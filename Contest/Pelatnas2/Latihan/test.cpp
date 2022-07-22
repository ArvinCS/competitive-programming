#include <bits/stdc++.h>



using namespace std;



#define ll long long



int main(){

	ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

	

	int r, n;

	ll m;

	cin >> r >> n >> m;

	

	ll ways[n+1][n+1];

	fill(ways[0], ways[n+1], 0);

	

	ways[1][0] = 1;

	for(int x=1;x<n;x++){

		for(int y=0;y<=x;y++){

			if(y+1 <= n){

//				if(x == 3) cout << x+1 << "," << y+1 << " " <<  ways[x][y] * (x-y+1)/2 % m << " -\n";

				ways[x+1][y+1] += ways[x][y] * (x-y+1)/2 % m;

				if(ways[x+1][y+1] >= m) ways[x+1][y+1] -= m;

			}

			if(y > 0){

//				if(x == 3) cout << x+1 << "," << y-1 << " " <<  ways[x][y] * y % m << " =\n";

				ways[x+1][y-1] += ways[x][y] * y % m;

				if(ways[x+1][y-1] >= m) ways[x+1][y-1] -= m;

			}

		}

	}

	

//	ll pick[r+1][n+1];

//	fill(pick[0], pick[r+1], 0);

//	

//	for(int y=0;y<=n;y++) pick[y][0] = ways[n-r-1][y];

//	for(int i=0;i<2;i++){

//		for(int x=r;x>=0;x--){

//			ll cnt = 0;

//			for(int y=0;y<r;y++){

//				if(x > 0){

//					pick[x-1][y] += cnt;

//					if(pick[x-1][y] >= m) pick[x-1][y] -= m;

//				}

//				if(x+1 <= r){

//					pick[x+1][y] += cnt;

//					if(pick[x+1][y] >= m) pick[x+1][y] -= m;

//				}

//			}

//		}

//	}

	

	

	ll sum[n+1];

	for(int x=1;x<=n;x++){

		sum[x] = 0;

		for(int y=0;y<=x;y++){

			sum[x] += ways[x][y];

			if(sum[x] >= m) sum[x] -= m;

		}

	}

	

//	int leaves = n-r+1;

//	ll table[leaves+1][leaves+1];

//	fill(table[0], table[leaves+1], 0);

//	

//	for(int y=0;y<=n;y++){

//		table[x][y] = ways[n-r-1][y];

//	}

//	for(int x=0;x<n;x++){

//		for(int y=0;y<=leaves;y++){

//			if(y > 0){

//				table[x+1][y-1] += 

//			}

//		}

//	}

	

	cout << sum[n] << "\n";

    return 0;

}



