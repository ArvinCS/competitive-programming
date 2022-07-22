#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int maxM = 10000;
int data[maxM];

/*int findRange(int size, int start, int end){
	int count = 0;
	for(int x=0;x<size;x++){
		if(start <= data[x] && data[x] < end) {
			count++;
		}
		
	}	
	return count;
}*/

struct Group {
	int start = 0,end = 0;
};

string findLimit(int size, int amount, int max, int i, Group group[]){
	string ans = "";
	if(i == amount){
		//cout << "end: " << group[amount-1].end << " -> " << size-1 << "\n";
		if(group[amount-1].end == size-1){
			for(int x=1;x<amount;x++){
				//cout << "x " << x << " : " << group[x].start << " " << group[x].end << "\n";
				//cout << data[group[x-1].start] << " start " << data[group[x-1].start-1] << "\n";
				if(data[group[x-1].start] == data[group[x-1].start-1]){
					ans = "";
					break;
				}
				ans.append(to_string(data[group[x].start]));
				if(x != amount-1) ans.append(" ");
			}
		}	
		return ans;
	}
	//cout << "i: "<< i << "\n";
	if(i == 0){
		group[i].start = 0;
	} else {
		group[i].start=group[i-1].end+1;
	}
	group[i].end = group[i].start+max-1;
	//cout << "i " << i << " end become " << group[i].start+max-1 <<  " from start " << group[i].start << "\n";
	ans = findLimit(size, amount, max, i+1, group);
	if(ans == "" && max > 1){
		group[i].end -= 1;
		ans = findLimit(size, amount, max, i+1, group);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int m;
	int n;
	cin >> m;
	
	for(int x=0;x<m;x++){
		cin >> data[x];
	}
	
	cin >> n;
	
	sort(data, data+m);
	
	double divide = m/(double)n;
	int max = ceil(divide);
	Group group[n];
	//cout << "MAX: " << max << "\n";
	cout << findLimit(m, n, max, 0, group) << "\n";
    return 0;
}
