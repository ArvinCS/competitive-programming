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
	
	us n, m, q, k;
	cin >> n >> m >> k >> q;
	
	vector<pair<us, us>> ikan;
	char tmp;
	for(us x=1;x<=n;x++){
		for(us y=1;y<=m;y++){
			cin >> tmp;
			if(tmp == 'X'){
				ikan.push_back({x, y});
			}
		}
	}
	
	while(q--){
		us a, b;
		cin >> a >> b;
		
		int ans = 10000;
		for(us x=0;x<ikan.size();x++){
			ans = min(abs(a-ikan[x].first) + abs(b-ikan[x].second), ans);
		}
		cout << ans << "\n";
	}
    return 0;
}

