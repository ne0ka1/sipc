// Generated from /Users/wesleylewis/Documents/sipc-lewis_zhang/tipg4/TIP.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class TIPLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, MUL=16, DIV=17, 
		MOD=18, PLUSPLUS=19, ADD=20, MINUSMINUS=21, SUB=22, GE=23, GT=24, LE=25, 
		LT=26, EQ=27, NE=28, NUMBER=29, KALLOC=30, KINPUT=31, KWHILE=32, KIF=33, 
		KFOR=34, KELSE=35, KVAR=36, KRETURN=37, KNULL=38, KOUTPUT=39, KERROR=40, 
		KOF=41, KBY=42, TRUE=43, FALSE=44, AND=45, OR=46, NOT=47, KPOLY=48, IDENTIFIER=49, 
		WS=50, BLOCKCOMMENT=51, COMMENT=52;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "MUL", "DIV", "MOD", 
			"PLUSPLUS", "ADD", "MINUSMINUS", "SUB", "GE", "GT", "LE", "LT", "EQ", 
			"NE", "NUMBER", "KALLOC", "KINPUT", "KWHILE", "KIF", "KFOR", "KELSE", 
			"KVAR", "KRETURN", "KNULL", "KOUTPUT", "KERROR", "KOF", "KBY", "TRUE", 
			"FALSE", "AND", "OR", "NOT", "KPOLY", "IDENTIFIER", "WS", "BLOCKCOMMENT", 
			"COMMENT"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'{'", "'}'", "';'", "'['", "']'", "'.'", 
			"'#'", "'&'", "'?'", "':'", "'='", "'..'", "'*'", "'/'", "'%'", "'++'", 
			"'+'", "'--'", "'-'", "'>='", "'>'", "'<='", "'<'", "'=='", "'!='", null, 
			"'alloc'", "'input'", "'while'", "'if'", "'for'", "'else'", "'var'", 
			"'return'", "'null'", "'output'", "'error'", "'of'", "'by'", "'true'", 
			"'false'", "'and'", "'or'", "'not'", "'poly'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "MUL", "DIV", "MOD", "PLUSPLUS", "ADD", "MINUSMINUS", 
			"SUB", "GE", "GT", "LE", "LT", "EQ", "NE", "NUMBER", "KALLOC", "KINPUT", 
			"KWHILE", "KIF", "KFOR", "KELSE", "KVAR", "KRETURN", "KNULL", "KOUTPUT", 
			"KERROR", "KOF", "KBY", "TRUE", "FALSE", "AND", "OR", "NOT", "KPOLY", 
			"IDENTIFIER", "WS", "BLOCKCOMMENT", "COMMENT"
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


	public TIPLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "TIP.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\66\u0132\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64"+
		"\t\64\4\65\t\65\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3"+
		"\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20"+
		"\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\26"+
		"\3\26\3\26\3\27\3\27\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\32\3\33\3\33"+
		"\3\34\3\34\3\34\3\35\3\35\3\35\3\36\6\36\u00ac\n\36\r\36\16\36\u00ad\3"+
		"\37\3\37\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3"+
		"\"\3\"\3#\3#\3#\3#\3$\3$\3$\3$\3$\3%\3%\3%\3%\3&\3&\3&\3&\3&\3&\3&\3\'"+
		"\3\'\3\'\3\'\3\'\3(\3(\3(\3(\3(\3(\3(\3)\3)\3)\3)\3)\3)\3*\3*\3*\3+\3"+
		"+\3+\3,\3,\3,\3,\3,\3-\3-\3-\3-\3-\3-\3.\3.\3.\3.\3/\3/\3/\3\60\3\60\3"+
		"\60\3\60\3\61\3\61\3\61\3\61\3\61\3\62\3\62\7\62\u010e\n\62\f\62\16\62"+
		"\u0111\13\62\3\63\6\63\u0114\n\63\r\63\16\63\u0115\3\63\3\63\3\64\3\64"+
		"\3\64\3\64\7\64\u011e\n\64\f\64\16\64\u0121\13\64\3\64\3\64\3\64\3\64"+
		"\3\64\3\65\3\65\3\65\3\65\7\65\u012c\n\65\f\65\16\65\u012f\13\65\3\65"+
		"\3\65\3\u011f\2\66\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r"+
		"\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33"+
		"\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63"+
		"e\64g\65i\66\3\2\7\3\2\62;\5\2C\\aac|\6\2\62;C\\aac|\5\2\13\f\17\17\""+
		"\"\4\2\f\f\17\17\2\u0136\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2"+
		"\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2"+
		"\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3"+
		"\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2"+
		"\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2"+
		"Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3"+
		"\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2"+
		"\2\3k\3\2\2\2\5m\3\2\2\2\7o\3\2\2\2\tq\3\2\2\2\13s\3\2\2\2\ru\3\2\2\2"+
		"\17w\3\2\2\2\21y\3\2\2\2\23{\3\2\2\2\25}\3\2\2\2\27\177\3\2\2\2\31\u0081"+
		"\3\2\2\2\33\u0083\3\2\2\2\35\u0085\3\2\2\2\37\u0087\3\2\2\2!\u008a\3\2"+
		"\2\2#\u008c\3\2\2\2%\u008e\3\2\2\2\'\u0090\3\2\2\2)\u0093\3\2\2\2+\u0095"+
		"\3\2\2\2-\u0098\3\2\2\2/\u009a\3\2\2\2\61\u009d\3\2\2\2\63\u009f\3\2\2"+
		"\2\65\u00a2\3\2\2\2\67\u00a4\3\2\2\29\u00a7\3\2\2\2;\u00ab\3\2\2\2=\u00af"+
		"\3\2\2\2?\u00b5\3\2\2\2A\u00bb\3\2\2\2C\u00c1\3\2\2\2E\u00c4\3\2\2\2G"+
		"\u00c8\3\2\2\2I\u00cd\3\2\2\2K\u00d1\3\2\2\2M\u00d8\3\2\2\2O\u00dd\3\2"+
		"\2\2Q\u00e4\3\2\2\2S\u00ea\3\2\2\2U\u00ed\3\2\2\2W\u00f0\3\2\2\2Y\u00f5"+
		"\3\2\2\2[\u00fb\3\2\2\2]\u00ff\3\2\2\2_\u0102\3\2\2\2a\u0106\3\2\2\2c"+
		"\u010b\3\2\2\2e\u0113\3\2\2\2g\u0119\3\2\2\2i\u0127\3\2\2\2kl\7*\2\2l"+
		"\4\3\2\2\2mn\7.\2\2n\6\3\2\2\2op\7+\2\2p\b\3\2\2\2qr\7}\2\2r\n\3\2\2\2"+
		"st\7\177\2\2t\f\3\2\2\2uv\7=\2\2v\16\3\2\2\2wx\7]\2\2x\20\3\2\2\2yz\7"+
		"_\2\2z\22\3\2\2\2{|\7\60\2\2|\24\3\2\2\2}~\7%\2\2~\26\3\2\2\2\177\u0080"+
		"\7(\2\2\u0080\30\3\2\2\2\u0081\u0082\7A\2\2\u0082\32\3\2\2\2\u0083\u0084"+
		"\7<\2\2\u0084\34\3\2\2\2\u0085\u0086\7?\2\2\u0086\36\3\2\2\2\u0087\u0088"+
		"\7\60\2\2\u0088\u0089\7\60\2\2\u0089 \3\2\2\2\u008a\u008b\7,\2\2\u008b"+
		"\"\3\2\2\2\u008c\u008d\7\61\2\2\u008d$\3\2\2\2\u008e\u008f\7\'\2\2\u008f"+
		"&\3\2\2\2\u0090\u0091\7-\2\2\u0091\u0092\7-\2\2\u0092(\3\2\2\2\u0093\u0094"+
		"\7-\2\2\u0094*\3\2\2\2\u0095\u0096\7/\2\2\u0096\u0097\7/\2\2\u0097,\3"+
		"\2\2\2\u0098\u0099\7/\2\2\u0099.\3\2\2\2\u009a\u009b\7@\2\2\u009b\u009c"+
		"\7?\2\2\u009c\60\3\2\2\2\u009d\u009e\7@\2\2\u009e\62\3\2\2\2\u009f\u00a0"+
		"\7>\2\2\u00a0\u00a1\7?\2\2\u00a1\64\3\2\2\2\u00a2\u00a3\7>\2\2\u00a3\66"+
		"\3\2\2\2\u00a4\u00a5\7?\2\2\u00a5\u00a6\7?\2\2\u00a68\3\2\2\2\u00a7\u00a8"+
		"\7#\2\2\u00a8\u00a9\7?\2\2\u00a9:\3\2\2\2\u00aa\u00ac\t\2\2\2\u00ab\u00aa"+
		"\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"<\3\2\2\2\u00af\u00b0\7c\2\2\u00b0\u00b1\7n\2\2\u00b1\u00b2\7n\2\2\u00b2"+
		"\u00b3\7q\2\2\u00b3\u00b4\7e\2\2\u00b4>\3\2\2\2\u00b5\u00b6\7k\2\2\u00b6"+
		"\u00b7\7p\2\2\u00b7\u00b8\7r\2\2\u00b8\u00b9\7w\2\2\u00b9\u00ba\7v\2\2"+
		"\u00ba@\3\2\2\2\u00bb\u00bc\7y\2\2\u00bc\u00bd\7j\2\2\u00bd\u00be\7k\2"+
		"\2\u00be\u00bf\7n\2\2\u00bf\u00c0\7g\2\2\u00c0B\3\2\2\2\u00c1\u00c2\7"+
		"k\2\2\u00c2\u00c3\7h\2\2\u00c3D\3\2\2\2\u00c4\u00c5\7h\2\2\u00c5\u00c6"+
		"\7q\2\2\u00c6\u00c7\7t\2\2\u00c7F\3\2\2\2\u00c8\u00c9\7g\2\2\u00c9\u00ca"+
		"\7n\2\2\u00ca\u00cb\7u\2\2\u00cb\u00cc\7g\2\2\u00ccH\3\2\2\2\u00cd\u00ce"+
		"\7x\2\2\u00ce\u00cf\7c\2\2\u00cf\u00d0\7t\2\2\u00d0J\3\2\2\2\u00d1\u00d2"+
		"\7t\2\2\u00d2\u00d3\7g\2\2\u00d3\u00d4\7v\2\2\u00d4\u00d5\7w\2\2\u00d5"+
		"\u00d6\7t\2\2\u00d6\u00d7\7p\2\2\u00d7L\3\2\2\2\u00d8\u00d9\7p\2\2\u00d9"+
		"\u00da\7w\2\2\u00da\u00db\7n\2\2\u00db\u00dc\7n\2\2\u00dcN\3\2\2\2\u00dd"+
		"\u00de\7q\2\2\u00de\u00df\7w\2\2\u00df\u00e0\7v\2\2\u00e0\u00e1\7r\2\2"+
		"\u00e1\u00e2\7w\2\2\u00e2\u00e3\7v\2\2\u00e3P\3\2\2\2\u00e4\u00e5\7g\2"+
		"\2\u00e5\u00e6\7t\2\2\u00e6\u00e7\7t\2\2\u00e7\u00e8\7q\2\2\u00e8\u00e9"+
		"\7t\2\2\u00e9R\3\2\2\2\u00ea\u00eb\7q\2\2\u00eb\u00ec\7h\2\2\u00ecT\3"+
		"\2\2\2\u00ed\u00ee\7d\2\2\u00ee\u00ef\7{\2\2\u00efV\3\2\2\2\u00f0\u00f1"+
		"\7v\2\2\u00f1\u00f2\7t\2\2\u00f2\u00f3\7w\2\2\u00f3\u00f4\7g\2\2\u00f4"+
		"X\3\2\2\2\u00f5\u00f6\7h\2\2\u00f6\u00f7\7c\2\2\u00f7\u00f8\7n\2\2\u00f8"+
		"\u00f9\7u\2\2\u00f9\u00fa\7g\2\2\u00faZ\3\2\2\2\u00fb\u00fc\7c\2\2\u00fc"+
		"\u00fd\7p\2\2\u00fd\u00fe\7f\2\2\u00fe\\\3\2\2\2\u00ff\u0100\7q\2\2\u0100"+
		"\u0101\7t\2\2\u0101^\3\2\2\2\u0102\u0103\7p\2\2\u0103\u0104\7q\2\2\u0104"+
		"\u0105\7v\2\2\u0105`\3\2\2\2\u0106\u0107\7r\2\2\u0107\u0108\7q\2\2\u0108"+
		"\u0109\7n\2\2\u0109\u010a\7{\2\2\u010ab\3\2\2\2\u010b\u010f\t\3\2\2\u010c"+
		"\u010e\t\4\2\2\u010d\u010c\3\2\2\2\u010e\u0111\3\2\2\2\u010f\u010d\3\2"+
		"\2\2\u010f\u0110\3\2\2\2\u0110d\3\2\2\2\u0111\u010f\3\2\2\2\u0112\u0114"+
		"\t\5\2\2\u0113\u0112\3\2\2\2\u0114\u0115\3\2\2\2\u0115\u0113\3\2\2\2\u0115"+
		"\u0116\3\2\2\2\u0116\u0117\3\2\2\2\u0117\u0118\b\63\2\2\u0118f\3\2\2\2"+
		"\u0119\u011a\7\61\2\2\u011a\u011b\7,\2\2\u011b\u011f\3\2\2\2\u011c\u011e"+
		"\13\2\2\2\u011d\u011c\3\2\2\2\u011e\u0121\3\2\2\2\u011f\u0120\3\2\2\2"+
		"\u011f\u011d\3\2\2\2\u0120\u0122\3\2\2\2\u0121\u011f\3\2\2\2\u0122\u0123"+
		"\7,\2\2\u0123\u0124\7\61\2\2\u0124\u0125\3\2\2\2\u0125\u0126\b\64\2\2"+
		"\u0126h\3\2\2\2\u0127\u0128\7\61\2\2\u0128\u0129\7\61\2\2\u0129\u012d"+
		"\3\2\2\2\u012a\u012c\n\6\2\2\u012b\u012a\3\2\2\2\u012c\u012f\3\2\2\2\u012d"+
		"\u012b\3\2\2\2\u012d\u012e\3\2\2\2\u012e\u0130\3\2\2\2\u012f\u012d\3\2"+
		"\2\2\u0130\u0131\b\65\2\2\u0131j\3\2\2\2\b\2\u00ad\u010f\u0115\u011f\u012d"+
		"\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}