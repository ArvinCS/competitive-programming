#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	long long ans = 0;
	for(int l=1;l<=n;l++){
		for(int left=0;left+l<=n;left++){
			ans++;
		}
	}
	cout << ans << "\n";
}
