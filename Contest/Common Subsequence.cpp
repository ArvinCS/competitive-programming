#include <iostream>
#include <set>

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
	
	short t;
	cin >> t;
	
	while(t--){
		int n, m, tmp;
		cin >> n >> m;
		
		set<int> cnt;
		for(int x=0;x<n;x++){
			cin >> tmp;
			cnt.insert(tmp);
		}
		
		int ans = 0;
		bool found = false;
		for(int y=0;y<m;y++){
			cin >> tmp;
			if(cnt.count(tmp)){
				found = true;
				ans = tmp;
			}
		}
		if(found){
			cout << "YES\n";
			cout << "1 " << ans << "\n";
		} else cout << "NO\n";
	}
	
    return 0;
}
