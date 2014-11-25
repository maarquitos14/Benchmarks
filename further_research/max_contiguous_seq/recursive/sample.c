#include <iostream>
#include <vector>
using namespace std;

void escribe(const vector<int>& v,int n) {
  cout << "(";
  for (int i = 0; i < n; ++i) {
    cout << v[i];
    if (i+1 < n) cout << ",";
  }
  cout << ")" << endl;
}

void unaena(int j, vector<int>& v, vector<bool>& vb, int n) {
	if(j==n) escribe(v,n);
	else {
		for(int i=0;i<n;++i) {
			if(not vb[i]) {
				vb[i]=true;
				v[j]=i+1;
				unaena(j+1,v,vb,n);
				vb[i]=false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<bool> vb(n,false);
	unaena(0,v,vb,n);
}
