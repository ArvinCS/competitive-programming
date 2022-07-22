#include <iostream>
#include <vector>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

vector<short> jalan[501], tol[501];
short from, to, n;

struct State {
	short node, dist, pred;
	bool ticket;
};

int search(){
	int visitTime[n+1];
	bool tickets[n+1];
	for(int x=1;x<=n;x++){
		tickets[x] = true;
		visitTime[x] = -1;
	}
	
	visitTime[from] = -1;
	
	vector<State> queue;
	State initial;
	initial.ticket = true;
	initial.node = from;
	initial.dist = 0;
	initial.pred = from;
	queue.push_back(initial);
	
	while(!queue.empty()){
		short currentIndex = queue.front().node, dist = queue.front().dist, pred = queue.front().pred;
		bool ticket = queue.front().ticket;
		queue.erase(queue.begin());
		
		// ketika sudah lebih dari shortest path sebelumnya, langsung stop untuk hemat waktu
		if(visitTime[to] != -1 && dist > visitTime[to]) continue;
		
		bool explorable = currentIndex == to;
		if(ticket){
			for(int x=0;x<tol[currentIndex].size();x++){
				// 1. ketika belum ada yang pernah visit
				// 2. ketika shortest path sebelumnya lebih dari path sekarang
				if(visitTime[tol[currentIndex][x]] == -1 || visitTime[tol[currentIndex][x]] > dist + 1){
//					if(currentIndex == 6) cout << "visit " << tol[currentIndex][x] << " expected " << dist + 1 << "\n";
					State tmp;
					tmp.ticket = false;
					tmp.node = tol[currentIndex][x];
					tmp.pred = currentIndex;
					tmp.dist = dist + 1;
					// tol kurang penting bisa taruh dibelakangan
					queue.push_back(tmp);
					explorable = true;
				}
			}
		}
		
		for(int x=0;x<jalan[currentIndex].size();x++){
			// 1. ketika belum ada yang pernah visit
			// 2. ketika shortest path sebelumnya lebih dari path sekarang
			// 3. ketika shortest path sama dengan path sekarang, namun shortest path sebelumnya sudah menggunakan tiket.
			if(visitTime[jalan[currentIndex][x]] == -1 || visitTime[jalan[currentIndex][x]] > dist + 1 || (ticket && !tickets[jalan[currentIndex][x]] && visitTime[jalan[currentIndex][x]] == dist + 1)){
//				if(currentIndex == 6) cout << "visit " << jalan[currentIndex][x] << " expected " << dist + 1<< "\n";
				State tmp;
				tmp.ticket = ticket;
				tmp.node = jalan[currentIndex][x];
				tmp.pred = currentIndex;
				tmp.dist = dist + 1;
				// jalan lebih penting daripada tol, dahulukan bagian jalan
				queue.insert(queue.begin(), tmp);
				explorable = true;
			}
		}
		
		// jika masih bisa diexplore lagi, maka node ini valid.
		if(explorable){
			visitTime[currentIndex] = dist;
			tickets[currentIndex] = ticket;
		}
//		cout << currentIndex << "-> \n";
//		for(int x=1;x<=n;x++) cout << visitTime[x] << "(" << ticket << ")" << " ";
//		cout << "\n";
	}
	return visitTime[to];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		
	int l, t;
	cin >> n >> l >> t >> from >> to;
	
	short tmp, tmp2;
	for(int x=0;x<l;x++){
		cin >> tmp >> tmp2;
		jalan[tmp].push_back(tmp2);
		jalan[tmp2].push_back(tmp);
	}
	
	for(int x=0;x<t;x++){
		cin >> tmp >> tmp2;
		tol[tmp].push_back(tmp2);
		tol[tmp2].push_back(tmp);
	}
	
	cout << search() << "\n";
    return 0;
}
