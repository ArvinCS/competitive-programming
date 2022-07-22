#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int size;

set<int> s;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int, vector<int>> maxHeap;
//int output;

int chanek(int l, int r){
	cout << "Chanek " << l << " " << r << endl;
	int output;
	cin >> output;
	
	--output;
	minHeap.push(output);
	maxHeap.push(output);
	s.insert(output);
	
	return output;
}

void askChanek(int l, int r){
	int length = r-l+1;
	if(length <= 1) return;
	
	if(length == 2){
		askChanek(l,l);
		askChanek(r,r);
	}
	
	if(chanek(l,r-(length)/2) >= chanek(l+(length+1)/2, r)){
		askChanek(l+(length+1)/2, r);
	} else {
		askChanek(l, r-(length)/2);
	}
}

int dengklek(int l, int r){
	cout << "Dengklek " << l << " " << r << endl;
	int output;
	cin >> output;
	
	++output;
	minHeap.push(output);
	maxHeap.push(output);
	s.insert(output);
	
	return output;
}

void askDengklek(int l, int r){
	int length = r-l+1;
	if(length <= 1) return;
	
	if(length == 2){
		askDengklek(l,l);
		askDengklek(r,r);
	}
	if(dengklek(l,r-(length)/2) <= dengklek(l+(length+1)/2, r)){
		askDengklek(l+(length+1)/2, r);
	} else {
		askDengklek(l, r-(length)/2);
	}
}

//
//void ask(int l, int r, int prevA, int prevB, bool askA, bool askB){
//	if(l > r) return;
//	
//	int a = askA ? chanek(l, r) : inf_int, b = askB ? dengklek(l, r) : -inf_int;
//	if(maxHeap.top() - minHeap.top() + 1 == size) return;
////	if(s.size() >= size) return;
//	
//	int length = r-l+1;
//	if(length <= 2) return;
//	
//	ask(l, r-length/2,min(a,prevA),max(b,prevB), a != inf_int && prevA >= a, b != -inf_int && prevB <= b);
//	ask(l+(length+1)/2, r,min(a,prevA),max(b,prevB), a != inf_int && prevA >= a, b != -inf_int && prevB <= b);
//}

int main(){
//	ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

	cin >> size;
	
	chanek(1, size);
	askChanek(1, size);
	
	dengklek(1, size);
	askDengklek(1, size);
	
	ll ans = max(maxHeap.top() - minHeap.top() + 1 - size, 0);
	cout << "Jawab " << ans << endl;
	
    return 0;
}

