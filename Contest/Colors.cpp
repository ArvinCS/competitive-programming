#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void fetch(int &response){
	cin >> response;
}

long long lastQuery;
void query(long long x){
	cout << "? " << x << endl;
	lastQuery = x;
}

int main(){
	short t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		
		int response;
		query(1);
		fetch(response);
		
		long long l = 1, r = n, ans = inf_ll;
		while(l <= r){
			long long mid = l + (r-l)/2;
			query(mid);
			fetch(response);
			
			if(response == 1){
				r = mid-1;
				ans = min(ans, abs(mid-1));
			} else {
				l = mid+1;
			}
			
			query(max(1, mid+ans <= n ? mid+ans : mid-ans));
			fetch(response);
		}
		
		cout << "= " << ans << endl;
	}
	
    return 0;
}
