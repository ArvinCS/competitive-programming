#include <iostream>
#include <vector>

using namespace std;

unsigned long long getParent(unsigned long long x){
	return (x-1)/2;
}

unsigned long long getLeftChild(unsigned long long x){
	return 2*x+1;
}

unsigned long long getRightChild(unsigned long long x){
	return 2*x+2;
}

vector<unsigned long long> arr;

void push(unsigned long long x){
	arr.push_back(x);
	
	int i = arr.size() - 1;
	unsigned long long tmp;
	while(i > 0 && arr[i] > arr[getParent(i)]){
		tmp = arr[i];
		arr[i] = arr[getParent(i)];
		arr[getParent(i)] = tmp;
		i = getParent(i);
	}
	
//	for(int x=0;x<arr.size();x++) cout << arr[x] << " ";
//	cout << "\n";
}

void pop(){
	arr[0] = arr.back();
	arr.pop_back();
	
	unsigned long long tmp, i = 0;
	bool swapped = true;
	while(swapped){
		unsigned long long maxIndex = i;
		if(getLeftChild(i) < arr.size() && arr[getLeftChild(i)] > arr[maxIndex]){
			maxIndex = getLeftChild(i);
		}
		if(getRightChild(i) < arr.size() && arr[getRightChild(i)] > arr[maxIndex]){
			maxIndex = getRightChild(i);
		}
		tmp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = tmp; 
		swapped = maxIndex != i;
		i = maxIndex;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;

	short a;
	unsigned long long b;
	while(n--){
		cin >> a;
		if(a == 1){
			cin >> b;
			push(b);
		} else if(a == 2){
			cout << arr.front() << "\n";
		} else if(a == 3){
			pop();
//			cout << "pop ! ";
//			for(int x=0;x<arr.size();x++) cout << arr[x] << " ";
//			cout << "\n";
		}
	}
    return 0;
}
