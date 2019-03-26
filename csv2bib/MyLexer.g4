lexer grammar MyLexer	;

ARTICLE		: '@INPROCEEDINGS'	;
BRACE		: ('{' | '}')		;
NL			: ('\r')?'\n'		;
COMMA		: ','				;
SECTION		: ('author'|'booktitle'|'title'|'year'|'pages'|'keywords'|'doi'|'month')	;
EQ			: '='				;
CONTENTS	: (~[=,\r\n{}])+	;
WS			: [ \t\r\n]+	-> skip	;
