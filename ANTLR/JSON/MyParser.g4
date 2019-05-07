parser grammar MyParser;

options { tokenVocab=MyLexer; }

json : value;

obj : LB pair (COMMA pair)* RB
	| LB RB
	;

pair
	: STRING COLON value
	;

array
	: LSB value (COMMA value)* RSB
	| LSB RSB
	;

value
	: STRING
	| NUMBER
	| obj
	| array
	| TRUE 
	| FALSE
	| NULL
	;

