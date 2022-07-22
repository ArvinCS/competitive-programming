#include <bits/stdc++.h>

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
		int n, m;
		cin >> n >> m;
		
		pair<int, bool> data[n];
		int infected = 0;
		for(int x=0;x<n;x++){
			cin >> data[x].first;
			data[x].second = (data[x].first == m);
			infected += data[x].second;
		}
		
		sort(data, data+n);
		
		ui ans = 0;
		while(infected < n){
			for(int x=0;x<n;x++){
				if(data[x].second) continue;
				int best = m-best, index = -1;
				for(int y=0;y<n;y++){
					if(x == y) continue;
					if(abs(best) > data[x].first-data[y].first && data[y].second){
						best = data[x].first-data[y].first;
						index = y;
					}
				}
				if(index == -1){
					data[x].first = m;
				} else {
					data[x].first = data[index].first;
				}
				data[x].second = true;
				for(int y=x+1;y<n;y++){
					int predict = data[y].first - best;
					if(predict >= -4000 && predict <= 4000){
						data[y].first = predict;
						best = 0;
					} else {
						int old = data[y].first;
						data[y].first = (predict < -4000 ? -4000 : min(predict, 4000));
						best -= old-data[y].first;
					}
					if(data[y])
					if(best == 0) break;
				}
			}
			ans++;
		}
		cout << ans << "\n";
	}

    return 0;
}

