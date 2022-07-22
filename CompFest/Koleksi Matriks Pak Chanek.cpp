#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	ll data[n+1];
	for(us x=0;x<=n;x++){
		cin >> data[x];
	}
	
	ll table[n+1][n+1];
	ll cnt[n+1][n+1];
	fill(cnt[0], cnt[n+1], 1);
	
	for(us x=0;x<=n;x++){
		table[x][x] = 0;
	}
	
	for(us l=2;l<=n;l++){
		for(us x=1;x<=n-l+1;x++){
			us y = x+l-1;
			table[x][y] = inf_ll;
			for(us z=x;z<y;z++){
				ull tmp = table[x][z] + table[z+1][y] + data[x-1] * data[z] * data[y];
				if(tmp < table[x][y]){
					table[x][y] = tmp;
					cnt[x][y] = cnt[x][z] * cnt[z+1][y];
				} else if(tmp == table[x][y]) cnt[x][y] += cnt[x][z] * cnt[z+1][y];
				cnt[x][y] %= mod;
//				cout << x << "-" << y << " = " << tmp << " (" << cnt[x][y]<< ")\n";
			}
		}
	}
	
	cout << table[1][n] << " " << cnt[1][n] << "\n";
    return 0;
}

