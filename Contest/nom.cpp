#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool priorityPrice(pair<int, unsigned long long> a, pair<int, unsigned long long> b){
	if(a.second < b.second) return true;
	else if(a.second == b.second){
		return a.first > b.first;
	}	
	return false;
}

bool priorityDigit(pair<int, unsigned long long> a, pair<int, unsigned long long> b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	unsigned long long m;
	cin >> n;
	
	vector<pair<int, unsigned long long>> cost;
	for(int x=0;x<=n;x++){
		pair<int, unsigned long long> temp;
		cin >> temp.second;
		temp.first = x;
		
		cost.push_back(temp);
	}
	cin >> m;

	sort(cost.begin(), cost.end(), priorityPrice); // sort dari termurah
	
	int erased = 0;
	for(int x=0;x<=n;x++){
		if(cost[x-erased].second > m){
			cost.erase(cost.begin() + x-erased); // hapus digit yang lebih mahal dari duit yang kita punya
			erased++;
		} else if(x-erased > 0){
			cost[x-erased].second -= cost[0].second;
		}
	}
	
	unsigned long long strata[n+1] = { 0 }, size = m/cost[0].second;
	m -= (size) * cost[0].second; // kita kurangin duit dari hasil beli digit termurah
	strata[cost[0].first] = size;
	
	if(size > 0 && cost[0].first == 0 && cost.size() > 1){ // jika digit termurah adalah 0, maka bisa jadi 000000. kita harus hindari
		if(cost[1].second > m){
			double tmp = (cost[1].second + cost[0].second - m) / cost[0].second;
			unsigned long long range = (cost[1].second + 2 * cost[0].second - 1 - m) / cost[0].second;
			if(range <= size){
				strata[cost[0].first] -= range;
				strata[cost[1].first]++;
				size -= (range - 1);
			} else{
				size = 1;
			}
		}
	}
	
	if(m > 0 && size > 0){
		//int basedSize = 
		sort(cost.begin(), cost.end(), priorityDigit);
		for(int x=n;x>=0;x--){
			if(strata[x] > 0){
				for(int i=cost.size()-1;i>0 && strata[x] > 0;i--){
					if(cost[i].second <= m && cost[i].first > x){
						unsigned long long tmp = floor(m / cost[i].second);
						unsigned long long bought = min(strata[x], tmp);
						strata[x] -= bought;
						strata[cost[i].first] += bought;
						m -= cost[i].second * bought;
					}
				}
			}
		}
	}
	
	//for(int x=0;x<cost.size();x++){
	//	cout << cost[x].first << "|" << cost[x].second << " ";
	//}
	
	//	cout << "\n";
	if(size == 0){
		cout << "0\n";
	} else {
		if(size > 0 && strata[0] == size){
			for(int x=0;x<=9;x++) strata[x] = 0;
			strata[0] = 1;
			size = 1;
		}
	
		cout << size << "\n";
	
		int count = 50;
		for(int x=n;x>=0 && count>0;x--){
			if(strata[x] > 0){
				for(unsigned long long i=strata[x];i>0 && count>0;i--){
					cout << x;
					count--;
				}
			}
		}
		cout << "\n";
		
		count = 50;
		int temp[10] = { 0 };
		for(int x=0;x<=n && count>0;x++){
			if(strata[x] > 0){
				for(unsigned long long i=strata[x];i>0 && count>0;i--){
					temp[x]++;
					count--;
				}
			}
		}
		
		for(int x=9;x>=0;x--){
			if(temp[x] > 0){
				for(int i=0;i<temp[x];i++) cout << x;
			};
		}
		cout << "\n";
	}
	
    return 0;
}
