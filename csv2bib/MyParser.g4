parser grammar MyParser;

options { tokenVocab=MyLexer; }

document	: ARTICLE BRACE title COMMA infos BRACE	NL EOF;
title		: CONTENTS ;
infos		: (info)*;
info		: SECTION EQ BRACE CONTENTS (COMMA CONTENTS)* BRACE COMMA	;


