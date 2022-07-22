#include <iostream>
#include <queue>

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
	
	priority_queue<ll> maxHeap;
	priority_queue<ll, vector<ll>, greater<ll>> minHeap;
	
	ui n;
	cin >> n;
	
	double median = 0;
	
	while(n--){
		ll tmp;
		cin >> tmp;
		
		if(maxHeap.size() > minHeap.size()){
			if(tmp >= median){
				minHeap.push(tmp);
			} else {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(tmp);
			}
			median = (minHeap.top() + maxHeap.top()) / 2.0;
		} else if(maxHeap.size() == minHeap.size()){
			if(tmp >= median){
				minHeap.push(tmp);
				median = (double) minHeap.top();
			} else {
				maxHeap.push(tmp);
				median = (double) maxHeap.top();
			}
		} else {
			if(tmp > median){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(tmp);
			} else {
				maxHeap.push(tmp);
			}
			median = (minHeap.top() + maxHeap.top()) / 2.0;
		}
		
		if(median == (ll) median){
			cout.precision(0);
		} else {
			cout.precision(1);
		}
		cout << fixed << median << "\n";
	}
	
    return 0;
}

