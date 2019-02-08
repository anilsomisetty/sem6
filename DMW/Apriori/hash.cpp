#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,sup=2,kk=1;
	cin>>n;
	n=n+1;
	string bb[n];
	for(int i=0;i<n;i++){
		cin>>bb[i];
	}
	vector<vector<int> > v;
	map<vector<int>,int> m;
	while(1){

		int aa;
		cin>>aa;
		if(aa==-1){
			break;
		}
		vector<int> a,bb;
		a.push_back(aa);
		if(aa==1){
			bb.push_back(1);
		}
		for(int i=1;i<n;i++){
			cin>>aa;
			if(aa==1){
				bb.push_back(i+1);
			}
			a.push_back(aa);
		}
		// for(int i=0;i<bb.size();i++){
		// 	cout<<bb[i]<<" ";
		// }
		// cout<<endl;
		v.push_back(a);
		for(int counter = 1; counter < pow(2,bb.size()); counter++) 
	    { 
	    	int a=0;
	    	vector<int> dupl;
	      for(int j = 0; j < bb.size(); j++) 
	       { 
	          
	          if(counter & (1<<j)) 
	           	dupl.push_back(bb[j]); 
	       } 
	       m[dupl]++;
	    }
	}
	for(int i=1;i<8;i++){
		vector<int> g;
		g.push_back(i);
		cout<<i<<" "<<m[g]<<endl;
	}
	for(int i=1;i<8;i++){
		for(int j=1;j<8;j++){
			vector<int>	bb;
			bb.push_back(i);
			bb.push_back(j);
			if(m[bb]>=2){
				cout<<i<<" "<<j<<" "<<m[bb]<<endl;
			}
		}
	}
	for(int i=1;i<8;i++){
		for(int j=1;j<8;j++){
			for(int k=1;k<8;k++){
				vector<int>	bb;
				bb.push_back(i);
				bb.push_back(j);
				bb.push_back(k);
				if(m[bb]>=2){
					cout<<i<<" "<<j<<" "<<k<<" "<<m[bb]<<endl;
				}
			}
		}
	}
	for(int i=1;i<8;i++){
		for(int j=1;j<8;j++){
			for(int k=1;k<8;k++){
				for(int kk=1;kk<8;kk++){
					vector<int>	bb;
					bb.push_back(i);
					bb.push_back(j);
					bb.push_back(k);
					bb.push_back(kk);
					if(m[bb]>=2){
						cout<<i<<" "<<j<<" "<<k<<" "<<kk<<" "<<m[bb]<<endl;
					}
				}
			}
		}
	}
}