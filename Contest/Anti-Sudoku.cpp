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
	
	us t;
	cin >> t;
	
	while(t--){
		string row[9];
		for(int x=0;x<9;x++){
			cin >> row[x];
		}	
		
		for(int x=0;x<9;x++){
			string r = row[x];
			for(int y=0;y<r.length();y++){
				if(r[y] == '1'){
					r[y] = '2';
				}
			}
			cout << r << "\n";
		}
	}
	
    return 0;
}
