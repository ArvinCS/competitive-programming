#include <iostream>

using namespace std;

short solve(short n, short m[3]){
	short pieces[n+1] = { 0 };
	
	for(short x=0;x<3;x++){
		if(n >= m[x]) pieces[m[x]] = 1;
	}
	
	for(short x=1;x<=n;x++){
		short best = pieces[x];
		for(short i=0;i<3;i++){
			if(m[i] < x && pieces[x-m[i]] > 0){
				best = (best > pieces[x-m[i]] + 1) ? best : pieces[x-m[i]] + 1;	
			}
		}
		//cout << x << ": " << best << "\n";
		pieces[x] = best;
	}
	
	return pieces[n];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n,m[3];
	cin >> n >> m[0] >> m[1] >> m[2];
	
	cout << solve(n,m) << "\n";
	
    return 0;
}
