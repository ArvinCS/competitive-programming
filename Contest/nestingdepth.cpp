#include <iostream>
#include <cmath>
using namespace std;

string recur(int n, string ans, int add, int data[], int depth, int depthMax){
	if(depth > depthMax) return ans;
	int previous = -1;
	string tmp = ans;
	for(int x=0;x<n;x++){
		cout << previous << " - " << data[x] << "\n";
		if(previous < data[x]){
		//	if(data[x] < depth) continue;
			previous = data[x];
			tmp.insert(x+add, "(");
			add++;
		} else if(previous > data[x]){
			if(data[x] < depth) continue;
			tmp.insert(x+add, ")");
			add++;
			previous = data[x];
			if(data[x] > 0){
				tmp.insert(0, "(");
				add++;
			}
		}
	}
	return recur(n, tmp, add, data, depth+1, depthMax);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		string line;
		cin >> line;
		
		//cout << line.length() << "\n";
		
		int maxDepth = 0;
		int data[line.length()];
		for(int x=0;x<line.length();x++){
			data[x] = line[x] - '0';
			maxDepth = max(maxDepth, data[x]);
		}
		
		int previous = 0;
		string ans = line;
		int add = 0;
			for(int x=0;x<line.length();x++){
				if(data[x] == previous) continue;
				//cout << x << ": " << ans << " -> ";
				if(data[x] > previous){
					for(int i=0;i<data[x]-previous;i++) {
						ans.insert(x+add, "(");
						add++;
					}
				}
				if(data[x] < previous) {
					for(int i=0;i<abs(previous-data[x]);i++) {
						ans.insert(x+add, ")");
						add++;
					}
				}
				//cout << ans << "\n";
				previous = data[x];
				if(x+1 == line.length()){
					for(int i=0;i<previous;i++){
						ans.insert(x+add+1, ")");
						add++;
					}
				}
			}
		//cout << ans << "\n";
		/*int depthList[line.length()];
		string ans = line;
		int add = 0;
		for(int x=0;x<line.length();x++){
			int value = line[x] - '0';
			if(depthList[x] == value) continue;
			depthList[x] += value;
			for(int depth=value;depth>0;depth--){
				ans.insert(x+add, "(");
				add++;
				for(int y=x+1;y<line.length();y++){
					if(ans[y+add] - '0' >= depth) continue;
					cout << y+add << " -> "<< ans[y+add] - '0' << " d: " << depth << "\n";
					cout << ans << "\n";
					ans.insert(y+add,")");
					add++;
					depthList[y]++;
				}
				if(x == line.length() - 1) ans.insert(x+1+add, ")");
			}
		}*/
		
		cout << "Case #" << c << ": " << ans <<"\n";
	}
    return 0;
}
