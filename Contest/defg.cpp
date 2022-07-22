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
		ui n;
		cin >> n;
		
		ll sum[n];
		for(ui x=0;x<n;x++){
			cin >> sum[x];
			if(x > 0) sum[x] += sum[x-1];
		}	
		
		ll smallest = 0, smallestCnt = 1, best = -100000, ways = 1;
		for(ui x=0;x<n;x++){
			int total = sum[x] - smallest;			
			if(total == best){
				ways += smallestCnt;
			} else if(total > best){
				best = total;
				ways = smallestCnt;
			}
			
			if(sum[x] < smallest){
				smallest = sum[x];
				smallestCnt = 1;
			} else if(sum[x] == smallest) smallestCnt++;
		}
		
		cout << best << " " << ways << "\n";
	}
	
    return 0;
}

