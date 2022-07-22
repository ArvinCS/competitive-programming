#include <iostream>
#include <vector>

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
	
	short t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		string a, b;
		cin >> a >> b;
		
		int turn = 0;
		vector<int> swaps;
		for(int x=n-1;x>=0;x--){
			if(a[x] != b[x]){
				swaps.push_back(x+1);
				swaps.push_back(1);
				swaps.push_back(x+1);
				turn += 3;
			}
		}
		
		cout << turn << " ";
		for(int x=0;x<turn;x++){
			cout << swaps[x];
			if(x < turn-1) cout << " ";
		}
		cout << "\n";
	}
	
    return 0;
}
