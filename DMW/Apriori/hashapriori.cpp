#include<bits/stdc++.h>
using namespace std;

void printbuckets(map<int,vector<set<int> > > hash){
	for(int i=0;i<8;i++){
		cout<<"hash bucket :"<<i<<endl;
		for(int j=0;j<hash[i].size();j++){
			set<int>::iterator it;
			if(hash[i][j].size()==2){
				cout<<"{";
				for(it=hash[i][j].begin();it!=hash[i][j].end();it++){
					cout<<*it<<",";
				}
				cout<<"}";
				cout<<endl;
			}
		}
	}
}

int main(){
	map<int,vector<set<int> > > hash;
	map<int,vector<set<int> > >::iterator hashit;
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
	    	set<int> dupl;
	    	set<int> ::iterator i;
	      	for(int j = 0; j < bb.size(); j++) 
	       	{ 
	          
	          	if(counter & (1<<j)) 
	           		dupl.insert(bb[j]); 
	       	} 
	       	int h=0;
	       	for(i=dupl.begin();i!=dupl.end();i++){
	       		h=h*12+*i;
	       	}
	       	h=h%8;
	       	if(dupl.size()>=2)
	       		hash[h].push_back(dupl);
	       	// m[dupl]++;
	    }
	}
	map<set<int>,int > f;
	printbuckets(hash);
	for(int i=0;i<8;i++){
		if(hash[i].size()>4){
			for(int j=0;j<hash[i].size();j++){
				f[hash[i][j]]++;
			}
			set<int>::iterator it;
			for(int j=0;j<hash[i].size();j++){
				if(f[hash[i][j]]>=2){
					for(it=hash[i][j].begin();it!=hash[i][j].end();it++){
						cout<<*it<<" ";
					}
					cout<<"->"<<f[hash[i][j]]<<endl;
					f[hash[i][j]]=0;
				}
			}	
		}
	}
}