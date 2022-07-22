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
		int n;
		cin >> n;
		
		int tmp, cnt = 0;
		bool stop = false;
		for(int x=0;x<n;x++){
			cin >> tmp;
			if(!stop){
				if(tmp == 1) cnt++;
				else stop = true;
			}
		}
		
		if(cnt == 0 || (cnt == n && n % 2 == 1) || (cnt != n && cnt % 2 == 0)){
			cout << "First\n";
		} else {
			cout << "Second\n";
		}
	}
	
    return 0;
}
