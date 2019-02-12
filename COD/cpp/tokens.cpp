#include<bits/stdc++.h>
#include <regex> 
#include<string.h> 
#include <fstream>
#include "dfa1.cpp"
using namespace std; 

int main() 
{  
	ifstream in("hello.c");
	string t;
	while(in>>t){
		// regex text("[:alnum:]+");
		regex text("[a-zA-Z]+");
		regex comm("[/][*](.*\n*)*[*][/]|[/][/](.*\n*)") ;
		regex header(".*[<].*[>]");
		regex delim("[{]|[}]|[(]|[)]");
		regex int1("[-][0-9]+|[0-9]+");
		regex float1("[-][0-9]+[.][0-9]+|[0-9]+[.][0-9]+");
		regex punc("[+]|[-]|[*]|[/]|[=]");
		smatch m; 
		string s=t;
		while(regex_search(s, m, text)){
			for (auto x : m){ 
				cout << x << " ";
				if(searcher(foo(),x))
					cout<<"Keyword";
				else
					cout<<"Not a Keyword"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, comm)){ 
		
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"comments"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, header)){
		
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"header"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, delim) ){
			
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"delim"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, int1)){
			
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"int"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, float1)){
			
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"float"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
		s=t;
		while(regex_search(s, m, punc)){
			
			for (auto x : m) 
				cout << x << " ";
			if(m.size()>=1){
				cout<<"punc"<<"    ";
				cout<<endl;
			}
			s = m.suffix().str();
		}
	}
	return 0; 
} 
