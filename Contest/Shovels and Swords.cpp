#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		long long a,b;
		cin >> a >> b;

		if(min(a,b)*2 >= max(a,b)){
			cout << (a+b)/3 << "\n";
		} else {
			cout << min(max(a,b)/2,min(a,b)) << "\n";
		}
	}
    return 0;
}
