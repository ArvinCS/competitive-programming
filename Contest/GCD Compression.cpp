#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		short data[2*n+1];
		vector<int> even, odd;
		for(int x=1;x<=2*n;x++){
			cin >> data[x];
			if(data[x] % 2){
				odd.push_back(x);
			} else {
				even.push_back(x);
			}
		}
		
		int ans = n-1;
		for(int x=0;x+1<odd.size() && ans > 0;x+=2){
			cout << odd[x] << " " << odd[x+1] << "\n";
			ans--;
		}
		for(int x=0;x+1<even.size() && ans > 0;x+=2){
			cout << even[x] << " " << even[x+1] << "\n";
			ans--;
		}
	}
	
    return 0;
}
