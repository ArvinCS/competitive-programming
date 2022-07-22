#include <iostream>
#include <vector>

using namespace std;

int getParent(int x){
	return (x-1)/2;
}

int getLeftChild(int x){
	return 2*x+1;
}

int getRightChild(int x){
	return 2*x+2;
}

vector<int> fight;

void push(int x){
	fight.push_back(x);
	int i = fight.size() - 1;
	while(i > 0 && fight[i] < fight[getParent(i)]){
		int tmp = fight[i];
		fight[i] = fight[getParent(i)];
		fight[getParent(i)] = tmp;
		i = getParent(i);
	}
//	for(int x=0;x<fight.size();x++) cout << fight[x] << " ";
//	cout << "\n";
}

void pop(){
	fight[0] = fight.back();
	fight.pop_back();
	
	int i = 0;
	bool swapped = true;
	while(swapped){
		int maxIndex = i;
		if(getLeftChild(i) < fight.size() && fight[maxIndex] > fight[getLeftChild(i)]){
			maxIndex = getLeftChild(i);
		}
		if(getRightChild(i) < fight.size() && fight[maxIndex] > fight[getRightChild(i)]){
			maxIndex = getRightChild(i);
		}
		int tmp = fight[i];
		fight[i] = fight[maxIndex];
		fight[maxIndex] = tmp;
		
		swapped = maxIndex != i;
		i = maxIndex;
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string t;
	cin >> t;
	
	int n, sd, sm;
	cin >> n >> sd >> sm;
	
	int p[n+1], k[n+1], l[n+1];
	for(int x=1;x<=n-1;x++){
		cin >> p[x] >> k[x] >> l[x];
	}
	
	int floor = 1;
	unsigned long long time = 0;
	while(floor < n){
		if(sd >= p[floor]){
			if(k[floor] < l[floor]){
				push(l[floor]-k[floor]);
				time += k[floor];
			} else {
				time += l[floor];
				sd++;
			}
			floor++;
		} else {
			while(sd < p[floor] && !fight.empty()){
				time += fight.front();
				sd++;
				pop();
			}
			if(sd < p[floor]) break;
		}
	}
	
	while(sd < sm && !fight.empty()){
		time += fight.front();
		sd++;
		pop();
	}
	
	if(floor == n && sd >= sm){
		cout << time << "\n";
	} else {
		cout << "-1\n";
	}
    return 0;
}
