// BJO no. 12886 µ¹ ±×·ì, mike2ox(2020)
#include<iostream>
using namespace std;

int a, b, c;
bool visitA[501];
bool visitB[501];
bool visitC[501];

bool go(int x, int y, int z) {
	if (x == y == z)
		return true;
	else if(visitA[x]&&visitB[y]&&visitC[z]){
		return false;
	}
	else {

		visitA[x] = visitB[y] = visitC[z] = true;
		
		if (x < y) {
			//visitA[x * 2]=visitB[y - x] = true;
			go(x*2, y-x, z);
			visitA[x * 2] = visitB[y - x] = false;
		}
		else if (x > y) {
			//visitA[x -y] = visitB[y *2] = true;
			go(x - y, y*2 , z);
			visitA[x - y] = visitB[y * 2] = false;
		}
		else if(y<z){
			//visitC[z-y] = visitB[y * 2] = true;
			go(x, y*2, z-y);
			visitC[z-y] = visitB[y * 2] = false;
		}
		else if(y>z){
			//visitC[z *2] = visitB[y -z] = true;
			go(x, y -z, z *2);
			visitC[z *2] = visitB[y -z] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;

	if ((a + b + c) % 3 == 0)
		cout << 0 << '\n';
	else if (go(a, b, c))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}