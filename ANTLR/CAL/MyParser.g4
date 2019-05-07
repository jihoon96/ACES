parser grammar MyParser;

options { tokenVocab=MyLexer; }

expression
   : multiplyingExpression ((PLUS | MINUS) multiplyingExpression)*
   ;

multiplyingExpression
   : powExpression ((TIMES | DIV) powExpression)*
   ;

powExpression
   : signedAtom (POW signedAtom)*
   ;

signedAtom
   : PLUS signedAtom
   | MINUS signedAtom
   | func
   | atom
   ;

atom
   : scientific
   | variable
   | constant
   | LPAREN expression RPAREN
   ;

scientific
   : SCIENTIFIC_NUMBER
   ;

constant
   : PI
   | EULER
   | I
   ;

variable
   : VARIABLE
   ;

func
   : funcname LPAREN expression (COMMA expression)* RPAREN
   ;

funcname
   : COS
   | TAN
   | SIN
   | ACOS
   | ATAN
   | ASIN
   | LOG
   | LN
   | SQRT
   ;

relop
   : EQ
   | GT
   | LT
   ;

