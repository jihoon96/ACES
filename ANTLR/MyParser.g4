parser grammar MyParser;

options { tokenVocab=MyLexer; }

message : GREETING ID;
