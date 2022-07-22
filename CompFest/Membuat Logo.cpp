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
	
	int n, m, l;
	cin >> n >> m >> l;

	for(int x=0;x<l;x++){
		for(int y=0;y<m;y++){
			cout << "*";
		}
		cout << "\n";
	}
	
	for(int x=0;x<n-2*l;x++){
		for(int y=0;y<m;y++){
			if(y < l) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
	
	for(int x=0;x<l;x++){
		for(int y=0;y<m;y++){
			cout << "*";
		}
		cout << "\n";
	}
    return 0;
}

