/* -- eval.l --       
   Evaluation d'une expression       
   Partie analyseur lexical.    

   Utilisation : flex eval.l */

%{
#define YYSTYPE double
#include "eval.tab.h" /* Généré par bison grâce à l'option %defines */
%}

%option noinput
%option nounput
%option noyywrap

BLANC [ \n\t]

%%

[0-9]+\.?[0-9]*     yylval = atof(yytext); return nombre; /* atoi = ascii to integer; yylval est la 
                                                     valeur sémantique (par défaut un int) 
                                                     associée au token */
[-+()=*/^]     return yytext[0];   /* caracteres unites lexicales */
{BLANC}+    ;
.           fprintf(stderr, "Caractere (%c) non reconnu\n", yytext[0]); /* tout le reste (les règles sont évaluées de haut en bas */

