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
		ui n;
		cin >> n;
		
		pair<short, ui> data[n];
		for(ui x=0;x<n;x++){
			cin >> data[x].first;
			data[x].second = x;
		}
		
		sort(data, data+n);
		deque<pair<short, ui>> deq;
		deq.push_front(data[n-1]);
		
		for(int x=n-2;x>=0;x--){
			if(data[x].second < deq.front().second){
				deq.push_front(data[x]);
			} else if(data[x].second < deq.back().second){
				pair<short, ui> tmp;
				tmp = deq.back();
				deq.pop_back();
				deq.push_back(data[x]);
				deq.push_back(tmp);
			} else {
				deq.push_back(data[x]);
			}
			if(deq.size() == 5) break;
		} 
		
		ll ans = 1;
		for(ui x=0;x<5;x++){
			ans *= data[x].first;
		}
		cout << ans << "\n";
	}
	
    return 0;
}

