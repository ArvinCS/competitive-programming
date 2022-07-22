#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

unsigned int data[300][300];

void solve(us n, us m){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			unsigned int neighbours = data[x][y], cnt = 0;
			if(x > 0) cnt++;
			if(y > 0) cnt++;
			if(x+1 < n) cnt++;
			if(y+1 < m) cnt++;
			if(cnt < neighbours){
				cout << "NO\n";
				return;
			}
			data[x][y] = cnt;
		}
	}
	
	cout << "YES\n";
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cout << data[x][y];
			if(y != m-1) cout << " ";
		}
		cout << "\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> data[x][y];
			}
		}
		
		solve(n, m);
	}
    return 0;
}
