/* -- eval.y --       
   Evaluation d'une expression       
   Partie analyseur grammatical.    

   Utilisation : bison eval.y */

%{
#include <stdio.h>
#include <math.h>
#define YYSTYPE double

/* Pré-déclarations */
int yylex (void);
void yyerror (const char *);

/* Variable définie dans un autre fichier */
extern char* yytext;

%}

%defines /* Génère le fichier en-tête eval.tab.h */
%token  nombre

%start  EXPR_CALCS /* Axiome de la grammaire */

%%

EXPR_CALCS : EXPR_CALC              
           | EXPR_CALCS EXPR_CALC   
           ;

EXPR_CALC : EXPR '='               { printf("%f\n", $1); }
          ;

EXPR     : EXPR '+' TERM        {$$ = $1 + $3;}
         | EXPR '-' TERM        {$$ = $1 - $3;}
         | '-' TERM             {$$ = - $2;}
         | TERM                 {$$ = $1;}
         ;

TERM     : TERM '*' PUIS        {$$ = $1 * $3;}
         | TERM '/' PUIS        {$$ = $1 / $3;}
         | PUIS                 {$$ = $1;}
         ;

PUIS     : PUIS '^' FACTEUR        {$$ = pow ($1,$3);}
         | FACTEUR                 {$$ = $1;}
         ;

FACTEUR  : nombre                  {$$ = $1;}
         | '(' EXPR ')'            {$$ = $2;}
         ;

%%
#include <stdio.h>
#include "eval.tab.h"


void yyerror (const char * error) 
{
    fprintf (stderr, "Erreur: %s sur l'expression %s\n", error, yytext);
}

int main() {
    if ( yyparse() != 0 ) {
        fprintf(stderr,"Syntaxe incorrecte\n"); return 1; }
    else
        return 0;
}
