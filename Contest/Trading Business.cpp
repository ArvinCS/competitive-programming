#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Item {
	int buy, sell, stock;	
};

bool sortProfit(pair<Item,Item> item1, pair<Item,Item> item2){
	return (item1.second.sell - item1.first.buy) > (item2.second.sell - item2.first.buy);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	Item items[n][m];
	for(int p=0;p<n;p++){
		string name;
		cin >> name;
		
		for(int x=0;x<m;x++){
			cin >> items[p][x].buy >> items[p][x].sell >> items[p][x].stock;
		}
	}	
	
	pair<Item, Item> worthest[m];
	for(int i=0;i<m;i++){
		Item from = items[0][i];
		Item to = items[0][i];
		for(int j=1;j<n;j++){
			if(items[j][i].stock > 0 && from.buy > items[j][i].buy){
				from = items[j][i];
			}
			if(to.sell < items[j][i].sell){
				to = items[j][i];
			}
		}
		worthest[i].first = from;
		worthest[i].second = to;
	}
	
	sort(worthest, worthest + m, sortProfit);
	
	int profit = 0;
	for(int x=0;x<m && k > 0;x++){
		int temp = min(worthest[x].first.stock, k); // how many stock we can buy
		int revenue = (worthest[x].second.sell - worthest[x].first.buy) * temp;
		if(revenue > 0){
			profit += revenue;
			k -= temp;
		}
		cout << k << " ";
		cout << worthest[x].first.buy << "[" << worthest[x].first.stock << "]" << "-" << worthest[x].second.sell << "\n";
	}
	cout << "\n";
	cout << profit << "\n";
    return 0;
}
