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
	
	us t;
	cin >> t;
	
	while(t--){
		us n, x, y;
		cin >> n >> x >> y;
		us mx = y-x;
		
		us gap = mx;
		for(us i=1;i<=mx;i++){
			if(mx % i == 0 && mx/i-1 <= n-2){
				gap = i;
				break;	
			}
		}
		
//		cout << "gap: " << gap << "\n";
		vector<us> data {x, y};
		us slot = n-2;
		
		for(short i=y-gap;i>=1 && slot > 0;i-=gap){
			if(i != x){
				data.push_back(i);
				slot--;
			}
		}
		
		if(slot > 0){
			for(us i=y+gap;slot>0;i+=gap){
				data.push_back(i);
				slot--;
			}
		}
		
		cout << data[0];
		for(us x=1;x<data.size();x++){
			cout << " " << data[x];
		}
		cout << "\n";
	}
	
    return 0;
}

