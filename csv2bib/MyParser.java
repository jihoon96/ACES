// Generated from MyParser.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MyParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ARTICLE=1, BRACE=2, NL=3, COMMA=4, SECTION=5, EQ=6, CONTENTS=7, WS=8;
	public static final int
		RULE_document = 0, RULE_title = 1, RULE_infos = 2, RULE_info = 3;
	private static String[] makeRuleNames() {
		return new String[] {
			"document", "title", "infos", "info"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'@INPROCEEDINGS'", null, null, "','", null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ARTICLE", "BRACE", "NL", "COMMA", "SECTION", "EQ", "CONTENTS", 
			"WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MyParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MyParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class DocumentContext extends ParserRuleContext {
		public TerminalNode ARTICLE() { return getToken(MyParser.ARTICLE, 0); }
		public List<TerminalNode> BRACE() { return getTokens(MyParser.BRACE); }
		public TerminalNode BRACE(int i) {
			return getToken(MyParser.BRACE, i);
		}
		public TitleContext title() {
			return getRuleContext(TitleContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(MyParser.COMMA, 0); }
		public InfosContext infos() {
			return getRuleContext(InfosContext.class,0);
		}
		public TerminalNode NL() { return getToken(MyParser.NL, 0); }
		public TerminalNode EOF() { return getToken(MyParser.EOF, 0); }
		public DocumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_document; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterDocument(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitDocument(this);
		}
	}

	public final DocumentContext document() throws RecognitionException {
		DocumentContext _localctx = new DocumentContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_document);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(8);
			match(ARTICLE);
			setState(9);
			match(BRACE);
			setState(10);
			title();
			setState(11);
			match(COMMA);
			setState(12);
			infos();
			setState(13);
			match(BRACE);
			setState(14);
			match(NL);
			setState(15);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TitleContext extends ParserRuleContext {
		public TerminalNode CONTENTS() { return getToken(MyParser.CONTENTS, 0); }
		public TitleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_title; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterTitle(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitTitle(this);
		}
	}

	public final TitleContext title() throws RecognitionException {
		TitleContext _localctx = new TitleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_title);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(17);
			match(CONTENTS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InfosContext extends ParserRuleContext {
		public List<InfoContext> info() {
			return getRuleContexts(InfoContext.class);
		}
		public InfoContext info(int i) {
			return getRuleContext(InfoContext.class,i);
		}
		public InfosContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_infos; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterInfos(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitInfos(this);
		}
	}

	public final InfosContext infos() throws RecognitionException {
		InfosContext _localctx = new InfosContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_infos);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SECTION) {
				{
				{
				setState(19);
				info();
				}
				}
				setState(24);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InfoContext extends ParserRuleContext {
		public TerminalNode SECTION() { return getToken(MyParser.SECTION, 0); }
		public TerminalNode EQ() { return getToken(MyParser.EQ, 0); }
		public List<TerminalNode> BRACE() { return getTokens(MyParser.BRACE); }
		public TerminalNode BRACE(int i) {
			return getToken(MyParser.BRACE, i);
		}
		public List<TerminalNode> CONTENTS() { return getTokens(MyParser.CONTENTS); }
		public TerminalNode CONTENTS(int i) {
			return getToken(MyParser.CONTENTS, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(MyParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MyParser.COMMA, i);
		}
		public InfoContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_info; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterInfo(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitInfo(this);
		}
	}

	public final InfoContext info() throws RecognitionException {
		InfoContext _localctx = new InfoContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_info);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			match(SECTION);
			setState(26);
			match(EQ);
			setState(27);
			match(BRACE);
			setState(28);
			match(CONTENTS);
			setState(33);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(29);
				match(COMMA);
				setState(30);
				match(CONTENTS);
				}
				}
				setState(35);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(36);
			match(BRACE);
			setState(37);
			match(COMMA);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\n*\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\4\7\4"+
		"\27\n\4\f\4\16\4\32\13\4\3\5\3\5\3\5\3\5\3\5\3\5\7\5\"\n\5\f\5\16\5%\13"+
		"\5\3\5\3\5\3\5\3\5\2\2\6\2\4\6\b\2\2\2\'\2\n\3\2\2\2\4\23\3\2\2\2\6\30"+
		"\3\2\2\2\b\33\3\2\2\2\n\13\7\3\2\2\13\f\7\4\2\2\f\r\5\4\3\2\r\16\7\6\2"+
		"\2\16\17\5\6\4\2\17\20\7\4\2\2\20\21\7\5\2\2\21\22\7\2\2\3\22\3\3\2\2"+
		"\2\23\24\7\t\2\2\24\5\3\2\2\2\25\27\5\b\5\2\26\25\3\2\2\2\27\32\3\2\2"+
		"\2\30\26\3\2\2\2\30\31\3\2\2\2\31\7\3\2\2\2\32\30\3\2\2\2\33\34\7\7\2"+
		"\2\34\35\7\b\2\2\35\36\7\4\2\2\36#\7\t\2\2\37 \7\6\2\2 \"\7\t\2\2!\37"+
		"\3\2\2\2\"%\3\2\2\2#!\3\2\2\2#$\3\2\2\2$&\3\2\2\2%#\3\2\2\2&\'\7\4\2\2"+
		"\'(\7\6\2\2(\t\3\2\2\2\4\30#";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}