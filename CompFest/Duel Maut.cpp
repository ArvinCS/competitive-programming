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
	
	ui n, q;
	cin >> n >> q;
	
	pair<ui, ui> cards[n];
	
	for(ui x=0;x<n;x++) cin >> cards[x].first;
	for(ui x=0;x<n;x++) cin >> cards[x].second;
	sort(cards, cards+n);
	
	pair<ui, ui> quests[q];
	pair<pair<ui, ui>, ui> data[q];
	for(ui x=0;x<q;x++){
		cin >> quests[x].first >> quests[x].second;
		data[x].first = quests[x];
		data[x].second = x;
	}
	sort(data, data+q);
	
	ui ans[q], currentIndex = 0;
	for(ui x=0;x<q;x++){
		pair<ui, ui> quest = data[x].first;
		ui tmp = 0;
		while(currentIndex < n && quest.first <)
	}
	
	for(ui x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

