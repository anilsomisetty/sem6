
%{ 
int i = 0; 
float a,b;
%} 

%% 
[-][0-9]+|[0-9]+ {printf("Integer");return yytext;}
[-][0-9]+[.][0-9]+|[0-9]+[.][0-9]+ {printf("Float");}

%% 
int mul(int a,int b){
	return a*b;
}
int yywrap(void){} 

int main() 
{ 
	a=atoi(yylex());
	b=atoi(yylex());
	printf("Ans:%d",mul(a,b));
	yylex();

	return 0; 
} 
