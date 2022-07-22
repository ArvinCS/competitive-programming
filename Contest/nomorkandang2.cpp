#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool priority(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first){
		return a.second > b.second;
	}	
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<unsigned long long,int>> data;
	
	for(int x=0;x<=n;x++){
		pair<unsigned long, int> tmp;
		cin >> tmp.first;
		tmp.second = x;
		data.push_back(tmp);
	}
	
	unsigned long long m;
	cin >> m;
	
	for(int x=0;x<=data.size();x++){
		if(data[x].first > m){
			data.erase(data.begin() + x);
		}
	}
	
	sort(data.begin(), data.end(), priority);
	
	for(int x=1;x<=data.size();x++){
		data[x].first -= data[0].first;
	}
	
	char baseChar = data[0].second + '0';
	unsigned long long baseSize = floor(m / data[0].first);

	unsigned long long result[10] = { 0 };
	
	result[data[0].second] = baseSize;
	m -= baseSize * data[0].first;
	
	if(data[0].second == 0 && data.size() >= 1){
		int i = 1;
		while(i < 10){
			if(data[i].first > data[0].first && data[i].second > data[0].second){
				break;
			}
			i++;
		}
		if(data[i].first > m){
			unsigned long long eraseLength = ceil((data[i].first - m) / data[0].first);
			if(eraseLength <= baseSize && m + data[0].first * eraseLength >= data[i].first + (baseSize - eraseLength > 0 ? 0 : 1)){
				result[data[0].second] -= eraseLength;
				baseSize -= eraseLength;
				m += data[0].first * eraseLength;
			}
		}
	}
	
	if(m > 0 && baseSize > 0){
		for(unsigned long long x=n;x>0 && m>0;x--){
			if(data[x].first <= m && data[x].second > data[0].second){
				int amount = m / data[x].first;
				result[data[0].second] -= amount;
				result[data[x].second] += amount;
				m -= data[x].first * amount;
			}
		}
	}
	
	if(baseSize > 0 && result[0] == baseSize){
		unsigned long long tmp[10] = { 0 };
		tmp[0] = 1;
		copy(tmp, tmp+10, result);
		baseSize = 1;
	};
	
	cout << baseSize << "\n";

	if(baseSize > 0){
		int x = 50;
		int i = 9;
		while(i >= 0 && x > 0){
			if(result[i] > 0){
				for(int x=0;x<result[i];x++) cout << i;
				x -= result[i];
			}
			i--;
		}
		cout << "\n";
		
		x = 50;
		i = 0;
		
		string reverse = "";
		while(i <= 9 && x > 0){
			if(result[i] > 0){
				for(int x=0;x<result[i];x++) reverse.append(to_string(i));
				x -= result[i];
			}
			i++;
		}
		
		for(int x=reverse.length()-1;x>=0;x--) cout << reverse[x];
		cout << "\n";
	}
	
    return 0;
}
