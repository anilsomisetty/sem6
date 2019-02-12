#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node *a[26];
    bool end;
};

struct node *getnode(){
    struct node *p=new node;
    for(int i=0;i<26;i++){
        p->a[i]=NULL;
    }
    p->end=false;
    return p;
}

void insert(struct node *root,string k){
    struct node *p=root;
    for(int i=0;i<k.size();i++){
        int aa=k[i]-'a';
        if(!p->a[aa]){
            p->a[aa]=getnode();
        }
        p=p->a[aa];
    }
    p->end=true;
}
int search(struct node *root,string k){
    struct node *p=root;
    for(int i=0;i<k.size();i++){
        int aa=k[i]-'a';
        if(p->a[aa]){
            p=p->a[aa];
        }
        else{
            return 0;
        }
    }
    if(p->end==true)
        return 1;
    else
        return 0;
    
}

struct node *foo(){
//    int n=5;
    struct node *root=getnode();
    insert(root,"int");
    insert(root,"float");
    insert(root,"printf");
    insert(root,"if");
    insert(root,"do");
    insert(root,"else");
    insert(root,"switch");
    insert(root,"main");
    return root;
}
int searcher(struct node *root,string s){
    return search(root,s);
}

