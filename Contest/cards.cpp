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

int n, k;

void init_assistant(int a, int b){
	n = a; k = b;
}

void init_magician(int a, int b){
	n = a; k = b;
}

vector<int> choose_cards(vector<int> cards){
	int chooseIndex = -1;

	if(k == 2){
		if(cards.front() == 1 && cards.back() == 3){
			chooseIndex = 1;
		} else if(cards.front() == 1 && cards.back() == 2){
			chooseIndex = 0;
		} else {
			chooseIndex = 0;
		}
	} else if(k == 3){
		bool picked = false;
		for(int x=0;x<cards.size();x++){
			if(cards[x] % 2 == 0){
				picked = true;
				chooseIndex = x;
				break;
			}
		}
		
		if(!picked){
			chooseIndex = 2;
		}
	} else if(k == 6){
		
	} else if(k == 8){
		
	}
	
	vector<int> stay;
	for(int x=0;x<cards.size();x++){
		if(x == chooseIndex) continue;
		stay.push_back(cards[x]);
	}
	return stay;
}

int find_discarded_card(vector<int> cards){
	if(k == 2){
		if(cards.front() == 1){
			return 3;
		} else if(cards.front() == 2){
			return 1;
		} else {
			return 2;
		}
	} else if(k == 3){
		int even = -1;
		for(int x=0;x<n;x++){
			if(cards[x] % 2 == 0){
				even = cards[x];
				break;
			}
		}
		
		if(even != -1){
			return even-2;
		} else {
			if(cards[0] == 3 && cards[1] == 5){
				return 4;
			} else if(cards[0] == 1 && cards[1] == 3){
				return 5;
			}
		}
	}
	
	return 1;
}
// Santai
// Pikirin dengan benar-benar

