#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int > > clos;
	int n,sup=2,kk=1,confidence=49;
	cin>>n;
	n=n+1;
	string bb[n];
	for(int i=0;i<n;i++){
		cin>>bb[i];
	}
	vector<vector<int> > v;
	while(1){
		int aa;
		cin>>aa;
		if(aa==-1){
			break;
		}
		vector<int> a;
		a.push_back(aa);
		for(int i=1;i<n;i++){
			cin>>aa;
			a.push_back(aa);
		}
		v.push_back(a);
	}
	vector<pair<int,int> > at;
	for(int i=1;i<=n;i++){
		at.push_back(make_pair(i,0));
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]==1){
				at[j].second+=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(at[i].second<sup){
			at[i].second=0;
		}
	}
	for(int i=0;i<n;i++){
		cout<<at[i].first<<" "<<at[i].second<<endl;
	}
	vector<vector<int> > v2;
	// int k=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int> vd;
			vd.push_back(i);
			vd.push_back(j);
			vd.push_back(0);
			v2.push_back(vd);
		}
	}
	int are[8][8]={ 0 };
	for(int k=0;k<v.size();k++){
		for(int i=0;i<v2.size();i++){
			int flag=1;
			for(int j=0;j<v2[i].size()-1;j++){
				if(v[k][v2[i][j]-1]!=1){
					flag=0;
				}
			}
			if(flag==1)
				v2[i][v2[i].size()-1]++;
		}
	}
	for(int i=0;i<v2.size();i++){
		if(v2[i][v2[i].size()-1]<sup){
			v2.erase(v2.begin()+i);
			i--;
		}
	}
	for(int i=0;i<v2.size();i++){
		for(int j=0;j<v2[i].size();j++)
			cout<<v2[i][j]<<" ";
		are[v2[i][0]][v2[i][1]]=v2[i][2];
		cout<<endl;
	}
	// for(int i=1;i<8;i++){
	// 	for(int j=1;j<8;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<v2.size();i++){
		vector<int > s;
		for(int j=0;j<v2[i].size()-1;j++)
			s.push_back(v2[i][j]);
	    for(int counter = 1; counter < 3; counter++) 
	    { 
	    	int a=0;
	      for(int j = 0; j < 2; j++) 
	       { 
	          
	          if(counter & (1<<j)) 
	           	a=s[j]; 
	       } 
	       string out;
	       for(int j=0;j<v2[i].size()-1;j++){
	       		ostringstream stt;
	       		stt<<v2[i][j];
	       		out+=stt.str()+" ";
	       }
	       // cout<<v2[i][v2[i].size()-1]<<at[a-1].second;
	       float fff=v2[i][v2[i].size()-1]/float(at[a-1].second);
	       fff=fff*100;
		   if(fff>confidence)
	    		cout<<"confidence of "<<(a)<<"=>"<<out<<"is "<<(fff)<<endl;
    	}

	}
	vector< vector<int> > v3;
	// int k=0;
	for(int i=0;i<v2.size();i++){
		for(int j=i+1;j<v2.size();j++){
			int flag=1;
			for(int h=0;h<kk;h++){
				if(v2[i][h]!=v2[j][h]){
					flag=0;
				}
			}
			if(flag==1){
				vector<int> hh;
				for(int h=0;h<v2[i].size()-1;h++){
					hh.push_back(v2[i][h]);
				}
				for(int h=kk;h<v2[j].size()-1;h++){
					hh.push_back(v2[j][h]);
				}
				
				// for(int jj=0;jj<kk;jj++){
				vector<int> gg;
				// gg.push_back(hh[jj]);
				for(int ii=kk;ii<hh.size();ii++){
					gg.push_back(hh[ii]);
				}
				
				for(int ii=0;ii<v2.size();ii++){
					int fl=1;
					if(v2[ii][0]==gg[0]){
						for(int hh=0;hh<v2[ii].size()-1;hh++){
							// cout<<gg[hh]<<v2[ii][hh]<<endl;
							if(gg[hh]!=v2[ii][hh]){
								fl=0;
							}
						}
						if(fl==1){
							hh.push_back(0);
							v3.push_back(hh);
							break;
						}
					}
				}
				// }
				// hh.push_back(0);
				// v3.push_back(hh);
			}
		}
	}
	int a3[8][8][8]={0};
	for(int k=0;k<v.size();k++){
		for(int i=0;i<v3.size();i++){
			int flag=1;
			for(int j=0;j<v3[i].size()-1;j++){
				if(v[k][v3[i][j]-1]!=1){
					flag=0;
				}
			}
			if(flag==1)
				v3[i][v3[i].size()-1]++;
		}
	}
	for(int i=0;i<v3.size();i++){
		if(v3[i][v3[i].size()-1]<sup){
			v3.erase(v3.begin()+i);
			i--;
		}
	}
	for(int i=0;i<v3.size();i++){
		for(int j=0;j<v3[i].size();j++)
			cout<<v3[i][j]<<" ";
		a3[v3[i][0]][v3[i][1]][v3[i][2]]=v3[i][3];
		cout<<endl;
	}
	for(int i=0;i<v3.size();i++){
		vector<int > s;
		for(int j=0;j<v3[i].size()-1;j++)
			s.push_back(v3[i][j]);
	    for(int counter = 1; counter < 7; counter++) 
	    { 
	    	int a=0;
	    	vector<int> dupl;
	      for(int j = 0; j < 3; j++) 
	       { 
	          
	          if(counter & (1<<j)) 
	           	dupl.push_back(s[j]); 
	       } 
	       string out;
	       for(int j=0;j<v3[i].size()-1;j++){
	       		ostringstream stt;
	       		stt<<v3[i][j];
	       		out+=stt.str()+" ";
	       }
	       // cout<<v2[i][v2[i].size()-1]<<at[a-1].second;
	       if(dupl.size()==1){
		       float fff=v3[i][v3[i].size()-1]/float(at[dupl[0]-1].second);
		       fff=fff*100;
			   if(fff>confidence)
		       	cout<<"confidence of "<<dupl[0]<<"=>"<<out<<"is "<<(fff)<<endl;
	   		}
	   		else if(dupl.size()==2){
				   if(are[dupl[0]][dupl[1]]>v3[i][v3[i].size()-1]){
					   clos.push_back(dupl);
				   }
	   			float fff=v3[i][v3[i].size()-1]/float(are[dupl[0]][dupl[1]]);
		       fff=fff*100;
			   if(fff>confidence)
		       	cout<<"confidence of"<<dupl[0]<<" "<<dupl[1]<<"=>"<<out<<"is "<<(fff)<<endl;
	   		}
    	}

	}
	cout<<"Closed frequent set"<<endl;
	map<vector<int>,int> closure;
	for(int i=0;i<clos.size();i++){
		closure[clos[i]]++;
	}
	for(int i=0;i<clos.size();i++){
		if(closure[clos[i]]>0){
			for(int j=0;j<clos[i].size();j++){
				cout<<clos[i][j]<<" ";
			}
			cout<<endl;
			closure[clos[i]]=0;
		}
	}
	vector< vector<int> > v4;
	// int k=0;
	kk++;
	for(int i=0;i<v3.size();i++){
		for(int j=i+1;j<v3.size();j++){
			int flag=1;
			for(int h=0;h<kk;h++){
				if(v3[i][h]!=v3[j][h]){
					flag=0;
				}
			}
			if(flag==1){
				vector<int> hh;
				for(int h=0;h<v3[i].size()-1;h++){
					hh.push_back(v3[i][h]);
				}
				for(int h=kk;h<v3[j].size()-1;h++){
					hh.push_back(v3[j][h]);
				}
				int cc=0;
				for(int jj=0;jj<kk;jj++){
					vector<int> gg;
					gg.push_back(hh[jj]);
					for(int ii=kk;ii<hh.size();ii++){
						gg.push_back(hh[ii]);
					}
					
					for(int ii=0;ii<v3.size();ii++){
						int fl=1;
						if(v3[ii][0]==gg[0]){
							for(int hh=0;hh<v3[ii].size()-1;hh++){
								// cout<<gg[hh]<<v3[ii][hh]<<endl;
								if(gg[hh]!=v3[ii][hh]){
									fl=0;
								}
							}
							if(fl==1){
								cc++;
								// hh.push_back(0);
								// v4.push_back(hh);
								break;
							}
						}
					}
				}
				if(cc==kk){
					hh.push_back(0);
					v4.push_back(hh);
				}
			}
		}
	}
	for(int k=0;k<v.size();k++){
		for(int i=0;i<v4.size();i++){
			int flag=1;
			for(int j=0;j<v4[i].size()-1;j++){
				if(v[k][v4[i][j]-1]!=1){
					flag=0;
				}
			}
			if(flag==1)
				v4[i][v4[i].size()-1]++;
		}
	}
	for(int i=0;i<v4.size();i++){
		if(v4[i][v4[i].size()-1]<sup){
			v4.erase(v4.begin()+i);
			i--;
		}
	}
	for(int i=0;i<v4.size();i++){
		for(int j=0;j<v4[i].size();j++)
			cout<<v4[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<v4.size();i++){
		vector<int > s;
		for(int j=0;j<v4[i].size()-1;j++)
			s.push_back(v4[i][j]);
	    for(int counter = 1; counter < 15; counter++) 
	    { 
	    	int a=0;
	    	vector<int> dupl;
	      for(int j = 0; j < 4; j++) 
	       { 
	          
	          if(counter & (1<<j)) 
	           	dupl.push_back(s[j]); 
	       } 
	       string out;
	       for(int j=0;j<v4[i].size()-1;j++){
	       		ostringstream stt;
	       		stt<<v4[i][j];
	       		out+=stt.str()+" ";
	       }
	       // cout<<v2[i][v2[i].size()-1]<<at[a-1].second;
	       if(dupl.size()==1){
		       float fff=v4[i][v4[i].size()-1]/float(at[dupl[0]-1].second);
		       fff=fff*100;
			   if(fff>confidence)
		       	cout<<"confidence of "<<dupl[0]<<"=>"<<out<<"is "<<(fff)<<endl;
	   		}
	   		else if(dupl.size()==2){
	   			float fff=v4[i][v4[i].size()-1]/float(are[dupl[0]][dupl[1]]);
		       fff=fff*100;
			   if(fff>confidence)
		       	cout<<"confidence of "<<dupl[0]<<" "<<dupl[1]<<"=>"<<out<<"is "<<(fff)<<endl;
	   		}
	   		else if(dupl.size()==3){
				   if(a3[dupl[0]][dupl[1]][dupl[2]]>v4[i][v4[i].size()-1]){
					   clos.push_back(dupl);
				   }
	   			float fff=v4[i][v4[i].size()-1]/float(a3[dupl[0]][dupl[1]][dupl[2]]);
		       fff=fff*100;
			   if(fff>confidence)
		       	cout<<"confidence of "<<dupl[0]<<" "<<dupl[1]<<" "<<dupl[2]<<"=>"<<out<<"is "<<(fff)<<endl;
	   		}
    	}

	}
	cout<<"Closed frequent set"<<endl;
	// map<vector<int>,int> closure;
	for(int i=0;i<clos.size();i++){
		closure[clos[i]]++;
	}
	for(int i=0;i<clos.size();i++){
		if(closure[clos[i]]>0){
			for(int j=0;j<clos[i].size();j++){
				cout<<clos[i][j]<<" ";
			}
			cout<<endl;
			closure[clos[i]]=0;
		}
	}
}
