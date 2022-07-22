#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

struct Person {
	int height, width;
	int index;
};

bool customSort(Person a, Person b){
	if(a.height == b.height) return a.width < b.width;
	return a.height < b.height;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		Person data[n];
		for(int x=0;x<n;x++){
			Person person;
			cin >> person.height >> person.width;
			person.index = x;
			
			data[x] = person;
		}
		
		sort(data, data+n, customSort);
		
		pair<int, int> h[n], w[n];
		h[0] = {data[0].height, 0};
		w[0] = {data[0].width, 0};
		
		for(int x=1;x<n;x++){
			h[x] = h[x-1];
			w[x] = w[x-1];
			if(h[x].first != data[x].height){
				h[x].first = data[x].height;
				h[x].second = x;
			}
			if(w[x].first > data[x].width){
				w[x].first = data[x].width;
				w[x].second = x;
			}
		}
		
		int ans[n];
		fill(ans, ans+n, -1);
		
		for(int x=1;x<n;x++){
			int best = -1;
			for(int y=x-1;y>=0;y--){
				if(data[y].height >= data[x].height) continue;
				if(w[y].first < data[x].width){
//					cout << w[y].first << "\n";
					best = w[y].second+1;
				}
			}
			if(best == -1 && x > 0){
//				cout << x << " - " << h[x].second-1 << "\n";
				if(h[x].second-1 >= 0 && h[h[x].second-1].first < data[x].width){
					if(w[h[x].second-1].first < data[x].height){
						best = w[h[x].second-1].second+1;
					}
				}
			}
			ans[data[x].index] = best;
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

