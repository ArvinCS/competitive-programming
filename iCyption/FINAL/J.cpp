#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n;
	
	short tmp;
	int digits[10] = {};
	int data[n][10] = {};
	for(int x=0;x<n;x++){
		cin >> tmp;
		digits[tmp]++;
		for(int i=0;i<=9;i++) data[x][i] = digits[i];
	}
	
	cin >> q;
	
	char t;
	int i;
	while(q--){
		cin >> t >> i;
		
		short max = 0;
		for(int x=1; x<=9; x++){
			if(t == 'L'){
				if(data[i-1][x] > data[i-1][max]){
					max = x;
				}
			} else {
				if(data[n-1][x] - (n-i-1 >= 0 ? data[n-i-1][x] : 0) > data[n-1][max] - (n-i-1 >= 0 ? data[n-i-1][max] : 0)){
					max = x;
				}
			}
		}
		cout << max << "\n";
	}
    return 0;
}
