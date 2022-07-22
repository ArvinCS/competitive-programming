#include <bits/stdc++.h>

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
	
	int n;
	cin >> n;
	
	int batu[2], gunting[2], kertas[2];
	cin >> batu[0] >> gunting[0] >> kertas[0];
	cin >> batu[1] >> gunting[1] >> kertas[1];
	
	int aKB = min(kertas[0], batu[1]), aGK = min(gunting[0], kertas[1]), aBG = min(batu[0], gunting[1]);
	int maxWin = aKB + aGK + aBG;
	
	int drawB = max(batu[0]-batu[1], 0), drawG = max(gunting[0]-gunting[1], 0), drawK = max(kertas[0]-kertas[1], 0);
	batu[1] -= batu[0]-drawB;
	gunting[1] -= gunting[0]-drawG;
	kertas[1] -= kertas[0]-drawK;
//	
//	cout << batu[0] << "," << drawB << " | " << gunting[0] << "," << drawG << " | " << kertas[0] << "," << drawK << "\n";
//	cout << batu[1] << " | " << gunting[1] << " | " << kertas[1] << "\n";
	int loseB = max(drawB-kertas[1], 0), loseG = max(drawG-batu[1], 0), loseK = max(drawK-gunting[1], 0);
//	kertas[1] -= drawB-loseB;
//	batu[1] -= drawG-loseG;
//	gunting[1] -= drawK-loseK;
	cout << max(kertas[1]-batu[0], 0) + max(batu[1]-gunting[0],0) + max(gunting[1]-kertas[0],0) << " " << maxWin << "\n";
	
    return 0;
}

