#include <iostream>
#include <set>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void solve(){
	us n;
	cin >> n;
	
	short values[205];
	fill(values, values+205, 0);
	
	us data[n];
	for(us x=0;x<n;x++){
		cin >> data[x];
		if(x > 0){
			values[data[x] + data[x-1]]++;
		}
	}
	
	for(us x=0;x<n;x++){
		for(us y=x+1;y<n;y++){
			us tmp = data[x], tmp2 = data[y];
			data[x] = tmp2;
			data[y] = tmp;
			
			short tmpVal[205];
			copy(begin(values), end(values), begin(tmpVal));
			
			bool pass = true;
			for(us z=1;z<n;z++){
				tmpVal[data[z-1] + data[z]]--;
				if(tmpVal[data[z-1] + data[z]] < 0){
					pass = false;
					break;
				}
			}
			
			if(!pass) continue;
			cout << data[0];
			for(us z=1;z<n;z++){
				cout << " " << data[z];
			}
			cout << "\n";
			return;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		solve();
	}
	
    return 0;
}

