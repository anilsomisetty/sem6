
%{ 
int i = 0; 
%} 

%% 
[\t]{30} {i=i+1;printf("%d",i);}
[/][*](.*\n*)*[*][/]|[/][/](.*\n*) {;}
.*[<].*[>] {printf("Header   %s\n",yytext);}
[a-zA-Z]+ {printf("text    %s\n",yytext);}
[{]|[}] {printf("Braces   %s\n",yytext);}
[(]|[)] {printf("Brackets %s\n",yytext);}
[;] {printf("End      %s\n",yytext);}
[-][0-9]+|[0-9]+ {printf("Integer    %s\n",yytext);}
[-][0-9]+[.][0-9]+|[0-9]+[.][0-9]+ {printf("Float    %s\n",yytext);}
[+]|[-]|[*]|[/] {printf("punct  %s\n",yytext);}
["].*["] {printf("text    %s\n",yytext);}

%% 

int yywrap(void){} 

int main() 
{ 
	extern FILE *yyin;
	yyin=fopen("hello.c","r");
	yylex();

	return 0; 
} 
