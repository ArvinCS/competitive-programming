#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void lg(long long n, long long k){
	int capacity = n-1;
	bool stop = false;
	for(long long x=n-2;x>=0;x--){
		long long now = capacity - x;
		long long lnow = now * (now + 1) / 2;
		long long previous = now - 1;
		long long lprevious = previous * (previous + 1) / 2;
		if(lprevious < k && k <= lnow){
			for(long long y=n-1;y>x && lprevious<k;y--){
				if(lprevious==k-1) {
					string ans(n, 'a');
					ans[x] = 'b';
					ans[y] = 'b';
					cout << ans << "\n";
					stop = true;
					break;
				}
				lprevious++;
			}
		}
		if(stop) break;
	}
	/*int a = 0;
	for(int x=n-2;x>=0 && a<k;x--){
		bool stop = false;
		for(long long y=n-1;y>x && a<k;y--){
			if(a==k-1) {
				string ans(n, 'a');
				ans[x] = 'b';
				ans[y] = 'b';
				cout << ans << "\n";
				stop = true;
				break;
			}
			a++;
		}
		if(stop) break;
	}*/
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t = 0;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		
		lg(n,k);
	}
    return 0;
}
