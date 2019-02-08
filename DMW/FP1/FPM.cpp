#include<bits/stdc++.h>
#include<regex>
#define ll long long
using namespace std;
int maxnod=120;
map<string,int> first;
map<string,int> idx;
vector< pair<vector<int >,int > > fp[120];
vector< vector<pair<int,int > > > fp1[120];
// vector<map<int,int> > m2(6);
int sup=150;
struct node{
    struct node *child[120];
    int val;
};

struct node *getnode(){
    struct node *p=new node;
    for(int i=1;i<maxnod;i++){
        p->child[i]=NULL;
    }
    p->val=1;
    return p;
}
bool cmp(pair<int,string> &a,pair<int,string> &b){
    return a.first>b.first;
}
bool cmp1(string &a,string &b){
    return first[a]>first[b];
}
void dfs(struct node *root,vector<int> &dup){

    struct node *p=root;
    for(int i=1;i<maxnod;i++){
        if(p->child[i]){
            dup.push_back(i);
            dfs(p->child[i],dup);
            dup.erase(dup.end()-1);
            // dup.push_back(p->child[i]->val);
            if(dup.size()>0)
                fp[i].push_back(make_pair(dup,p->child[i]->val));
        }
    }

}
void dfs1(struct node *root,vector< pair<int,int > > &dup,int ind){
    struct node *p=root;
    int count=0;
    for(int i=1;i<maxnod;i++){
        if(p->child[i]){
            count++;
        }
    }
    if(count==0){
        fp1[ind].push_back(dup);
    }
    for(int i=1;i<maxnod;i++){
        if(p->child[i]){
            int dval=p->child[i]->val;
            dup.push_back(make_pair(i,dval));
            dfs1(p->child[i],dup,ind);
            // if(dup[dup.size()-1].second >= sup)
            //     fp1[ind].push_back(dup);
            dup.erase(dup.end()-1);
        }
        
    }
}
struct node *create(struct node *root,vector<int > &v,int value,map<int,int> m2){
    struct node *p=root;
    for(int j=0;j<v.size();j++){
        // cout<<m2[v[j]]<<endl;
        if(m2[v[j]]<sup){
            break;
        }
        if(!p->child[v[j]]){
            p->child[v[j]]=getnode();
            p->child[v[j]]->val=value;
        }
        else{
            p->child[v[j]]->val+=value;
        }
        p=p->child[v[j]];
    }
    return p;
}
int main(){
    string line;
    
    map<string,int> ::iterator it;
    vector<vector<string> > input2;
    while(getline(cin,line)){
        regex r("[0-9]+");
        smatch m;
        vector<string> tmp;
        while (regex_search (line,m,r)) {
            // cout<<m.size();
            for (auto x:m) {
                first[x]++;
                tmp.push_back(x);
            }
            
            line = m.suffix().str();
        }
        input2.push_back(tmp);
    }
    int vv=1;
    for(it=first.begin();it!=first.end();it++){
        idx[it->first]=vv++;
    }
    vector<pair<int,string> > v;
    for(it=first.begin();it!=first.end();it++){
        // cout<<it->first<<" "<<it->second<<endl;
        v.push_back(make_pair(it->second,it->first));
    }
    sort(v.begin(),v.end(),cmp);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    struct node *root=getnode();
    for(int i=0;i<input2.size();i++){
        sort(input2[i].begin(),input2[i].end(),cmp1);
    }
    for(int i=0;i<input2.size();i++){
        struct node *p=root;
        for(int j=0;j<input2[i].size();j++){
            if(!p->child[idx[input2[i][j]]]){
                p->child[idx[input2[i][j]]]=getnode();
            }
            else{
                p->child[idx[input2[i][j]]]->val++;
            }
            p=p->child[idx[input2[i][j]]];
        }
    }
    cout<<"Conditional Pattern Base"<<endl;
    vector<int> dup; 
    dfs(root,dup);
    for(int i=1;i<maxnod;i++){
        if(fp[i].size()<=0)
            continue;
        cout<<i<<"=>";
        for(int j=0;j<fp[i].size();j++){
            cout<<"{";
            for(int k=0;k<fp[i][j].first.size();k++){
                cout<<fp[i][j].first[k]<<" ";
            }
            cout<<":"<<fp[i][j].second<<"}  ";
        }
        cout<<endl;
    }
    for(int i=1;i<maxnod;i++){
        struct node *root=getnode();
        if(fp[i].size()>0){
            map<int,int> m2;
            for(int j=0;j<fp[i].size();j++){        
                for(int k=0;k<fp[i][j].first.size();k++){
                    // cout<<fp[i][j].first[k]<<endl;
                    m2[fp[i][j].first[k]]+=fp[i][j].second;
                }
                
            }
            for(int j=0;j<fp[i].size();j++){        
                create(root,fp[i][j].first,fp[i][j].second,m2);
            }
            vector<pair<int,int > > dupl;
            dfs1(root,dupl,i);
        }
    }
    cout<<"conditional FP-tree"<<endl;
    for(int i=1;i<maxnod;i++){
        if(fp1[i].size()<=0)
            continue;
        cout<<i<<"=>";
        for(int j=0;j<fp1[i].size();j++){
            cout<<"{";
            for(int k=0;k<fp1[i][j].size();k++){
                cout<<fp1[i][j][k].first<<":"<<fp1[i][j][k].second<<" ";
            }
            cout<<"}";
        }
        cout<<endl;
    }
    cout<<"Frequent Patterns Generated"<<endl;
    for(int i=1;i<maxnod;i++){
        map<vector<int >,int > l;
        map<vector<int >,int > ::iterator it; 
        for(int j=0;j<fp1[i].size();j++){
            
            for(int h=0;h<pow(2,fp1[i][j].size());h++){
                vector<int> ld;
                int min=100;
                for(int hh=0;hh<fp1[i][j].size();hh++){
                    if(h & (1<<hh)){
                        ld.push_back(fp1[i][j][hh].first);
                        if(fp1[i][j][hh].second<min){
                            min=fp1[i][j][hh].second;
                        }
                    }
                }
                if(ld.size()>0){
                    ld.push_back(i);
                    l[ld]+=min;
                }
            }
            
        }
        
        for(it=l.begin();it!=l.end();it++){
            for(int nn=0;nn<it->first.size();nn++){
                cout<<it->first[nn]<<" ";
            }
            cout<<":"<<it->second<<" ";
            cout<<endl;
        }
        // cout<<endl;
    }
}