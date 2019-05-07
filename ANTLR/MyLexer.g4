lexer grammar MyLexer;

GREETING	: ('Hello' | 'Greetings');
ID			: [a-zA-Z]+;
WS			: [ \t\r\n]+ -> skip ;
