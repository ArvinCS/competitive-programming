#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int x1,x2,y1,y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	int jarak = abs(x1 - x2) + abs(y1 - y2);
	printf("%d\n", jarak);

    return 0;
}
