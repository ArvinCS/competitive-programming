#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		long long n, o, m, k = 0;
		cin >> n >> o >> m;
		
		pair<long long, long long> operations[m];
		for(int x=0;x<m;x++){
			cin >> operations[x].first >> operations[x].second;
		}
		
		//sort(operations, operations+m, sortPair);
		
		bool identified[n]{}, connected = false;
		
		for(int x=0;x<m;x++){
			if(!connected){
				connected = (operations[x].first <= o) && (o <= operations[x].second);
			} else {
				connected = operations[x].first <= operations[x-1].first || operations[x-1].second <= operations[x].second;
			}
			if(connected){
				for(long long c=0;c<=operations[x].second - operations[x].first;c++){
					if(!identified[c+operations[x].first]){
						identified[c+operations[x].first] = true;
						k++;
					}
				}
			}
		}
		cout << k << "\n";
	}
	
    return 0;
}
