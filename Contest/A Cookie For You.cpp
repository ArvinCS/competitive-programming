#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	while(t--){
		unsigned long long a,b,n,m;
		cin >> a >> b >> n >> m;
		
		if(n+m <= a+b && m < min(a,b) - (a == b ? 1 : 0)){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
    return 0;
}
