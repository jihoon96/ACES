// Generated from MyLexer.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MyLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ARTICLE=1, BRACE=2, NL=3, COMMA=4, SECTION=5, EQ=6, CONTENTS=7, WS=8;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"ARTICLE", "BRACE", "NL", "COMMA", "SECTION", "EQ", "CONTENTS", "WS"
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


	public MyLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MyLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\nh\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\4\5\4&\n\4\3\4"+
		"\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6Y\n\6\3\7\3\7"+
		"\3\b\6\b^\n\b\r\b\16\b_\3\t\6\tc\n\t\r\t\16\td\3\t\3\t\2\2\n\3\3\5\4\7"+
		"\5\t\6\13\7\r\b\17\t\21\n\3\2\5\4\2}}\177\177\b\2\f\f\17\17..??}}\177"+
		"\177\5\2\13\f\17\17\"\"\2q\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2"+
		"\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\3\23\3\2\2\2\5"+
		"\"\3\2\2\2\7%\3\2\2\2\t)\3\2\2\2\13X\3\2\2\2\rZ\3\2\2\2\17]\3\2\2\2\21"+
		"b\3\2\2\2\23\24\7B\2\2\24\25\7K\2\2\25\26\7P\2\2\26\27\7R\2\2\27\30\7"+
		"T\2\2\30\31\7Q\2\2\31\32\7E\2\2\32\33\7G\2\2\33\34\7G\2\2\34\35\7F\2\2"+
		"\35\36\7K\2\2\36\37\7P\2\2\37 \7I\2\2 !\7U\2\2!\4\3\2\2\2\"#\t\2\2\2#"+
		"\6\3\2\2\2$&\7\17\2\2%$\3\2\2\2%&\3\2\2\2&\'\3\2\2\2\'(\7\f\2\2(\b\3\2"+
		"\2\2)*\7.\2\2*\n\3\2\2\2+,\7c\2\2,-\7w\2\2-.\7v\2\2./\7j\2\2/\60\7q\2"+
		"\2\60Y\7t\2\2\61\62\7d\2\2\62\63\7q\2\2\63\64\7q\2\2\64\65\7m\2\2\65\66"+
		"\7v\2\2\66\67\7k\2\2\678\7v\2\289\7n\2\29Y\7g\2\2:;\7v\2\2;<\7k\2\2<="+
		"\7v\2\2=>\7n\2\2>Y\7g\2\2?@\7{\2\2@A\7g\2\2AB\7c\2\2BY\7t\2\2CD\7r\2\2"+
		"DE\7c\2\2EF\7i\2\2FG\7g\2\2GY\7u\2\2HI\7m\2\2IJ\7g\2\2JK\7{\2\2KL\7y\2"+
		"\2LM\7q\2\2MN\7t\2\2NO\7f\2\2OY\7u\2\2PQ\7f\2\2QR\7q\2\2RY\7k\2\2ST\7"+
		"o\2\2TU\7q\2\2UV\7p\2\2VW\7v\2\2WY\7j\2\2X+\3\2\2\2X\61\3\2\2\2X:\3\2"+
		"\2\2X?\3\2\2\2XC\3\2\2\2XH\3\2\2\2XP\3\2\2\2XS\3\2\2\2Y\f\3\2\2\2Z[\7"+
		"?\2\2[\16\3\2\2\2\\^\n\3\2\2]\\\3\2\2\2^_\3\2\2\2_]\3\2\2\2_`\3\2\2\2"+
		"`\20\3\2\2\2ac\t\4\2\2ba\3\2\2\2cd\3\2\2\2db\3\2\2\2de\3\2\2\2ef\3\2\2"+
		"\2fg\b\t\2\2g\22\3\2\2\2\7\2%X_d\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}