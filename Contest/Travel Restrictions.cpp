#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void solve(us n, bool getIn[], bool getOut[]){
	unordered_set<us> edges[n];

	for(us x=0;x<n;x++){	
		unordered_set<us> cnt;
		queue<us> queue;
		queue.push(x);
		
		while(!queue.empty()){
			short curNode = queue.front();
			queue.pop();
			
			if(cnt.count(curNode) == 0){
				cnt.insert(curNode);
				if(getOut[curNode]){
					if(curNode + 1 < n && cnt.count(curNode+1) == 0 && getIn[curNode+1]){
						queue.push(curNode+1);
					}
					if(curNode >= 1 && cnt.count(curNode-1) == 0 && getIn[curNode-1]){
						queue.push(curNode-1);
					}
				}
			}
		}
		
		for(auto o : cnt){
			edges[x].insert(o);
		}
	}
	
	for(us x=0;x<n;x++){
		for(us y=0;y<n;y++){
			if(edges[x].count(y)) cout << "Y";
			else cout << "N";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	for(us i=1;i<=t;i++){
		us n;
		cin >> n;
		
		char tmp;
		bool getIn[n], getOut[n];
		for(us x=0;x<n;x++){
			cin >> tmp;
			getIn[x] = (tmp == 'Y');
		}
		for(us x=0;x<n;x++){
			cin >> tmp;
			getOut[x] = (tmp == 'Y');
		}
		
		cout << "Case #" << i << ":\n";
		solve(n, getIn, getOut);
	}
	
    return 0;
}

