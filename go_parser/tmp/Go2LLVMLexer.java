// Generated from Go2LLVMLexer.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class Go2LLVMLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		STRING_TOK=1, INT_TOK=2, FLOAT_TOK=3, IMAG_TOK=4, UNARY_OP_TOK=5, BINARY_OP_TOK=6, 
		PACKAGE_TOK=7, TYPE_TOK=8, VAR_TOK=9, FUNC_TOK=10, FOR_TOK=11, BREAK_TOK=12, 
		CONTINUE_TOK=13, RETURN_TOK=14, IF_TOK=15, ELSE_TOK=16, IDENT_TOK=17, 
		BO=18, BC=19, PO=20, PC=21, SEMICOLON=22, EQ=23, COMMA=24, WS=25, COMMENT=26, 
		LINE_COMMENT=27, TERMINATOR=28;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"STRING_TOK", "LETTER", "BYTE_VALUE", "OCTAL_BYTE_VALUE", "HEX_BYTE_VALUE", 
		"INT_TOK", "DECIMAL_LIT", "OCTAL_LIT", "HEX_LIT", "DECIMAL_DIGIT", "DECIMALS", 
		"OCTAL_DIGIT", "HEX_DIGIT", "FLOAT_TOK", "EXPONENT", "IMAG_TOK", "UNARY_OP_TOK", 
		"BINARY_OP_TOK", "REL_OP", "ADD_OP", "MUL_OP", "PACKAGE_TOK", "TYPE_TOK", 
		"VAR_TOK", "FUNC_TOK", "FOR_TOK", "BREAK_TOK", "CONTINUE_TOK", "RETURN_TOK", 
		"IF_TOK", "ELSE_TOK", "IDENT_TOK", "BO", "BC", "PO", "PC", "SEMICOLON", 
		"EQ", "COMMA", "WS", "COMMENT", "LINE_COMMENT", "TERMINATOR"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, null, null, null, null, null, "'package'", "'type'", "'var'", 
		"'func'", "'for'", "'break'", "'continue'", "'return'", "'if'", "'else'", 
		null, "'{'", "'}'", "'('", "')'", "';'", "'='", "','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "STRING_TOK", "INT_TOK", "FLOAT_TOK", "IMAG_TOK", "UNARY_OP_TOK", 
		"BINARY_OP_TOK", "PACKAGE_TOK", "TYPE_TOK", "VAR_TOK", "FUNC_TOK", "FOR_TOK", 
		"BREAK_TOK", "CONTINUE_TOK", "RETURN_TOK", "IF_TOK", "ELSE_TOK", "IDENT_TOK", 
		"BO", "BC", "PO", "PC", "SEMICOLON", "EQ", "COMMA", "WS", "COMMENT", "LINE_COMMENT", 
		"TERMINATOR"
	};
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


	public Go2LLVMLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Go2LLVMLexer.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\36\u0151\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\3\2\3\2\3\2\3\2\3\2\7\2_\n\2\f\2\16\2b\13\2\3\2\3\2\3\3\5\3g\n"+
		"\3\3\4\3\4\5\4k\n\4\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3"+
		"\7\5\7z\n\7\3\b\3\b\7\b~\n\b\f\b\16\b\u0081\13\b\3\t\3\t\7\t\u0085\n\t"+
		"\f\t\16\t\u0088\13\t\3\n\3\n\3\n\6\n\u008d\n\n\r\n\16\n\u008e\3\13\3\13"+
		"\3\f\6\f\u0094\n\f\r\f\16\f\u0095\3\r\3\r\3\16\3\16\3\17\3\17\3\17\5\17"+
		"\u009f\n\17\3\17\5\17\u00a2\n\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00aa"+
		"\n\17\5\17\u00ac\n\17\3\20\3\20\5\20\u00b0\n\20\3\20\3\20\3\21\3\21\5"+
		"\21\u00b6\n\21\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\5\23\u00c3\n\23\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\5\24"+
		"\u00cf\n\24\3\25\3\25\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\5\26\u00db"+
		"\n\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30"+
		"\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\34"+
		"\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35"+
		"\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3"+
		"!\3!\7!\u0118\n!\f!\16!\u011b\13!\3\"\3\"\3#\3#\3$\3$\3%\3%\3&\3&\3\'"+
		"\3\'\3(\3(\3)\6)\u012c\n)\r)\16)\u012d\3)\3)\3*\3*\3*\3*\7*\u0136\n*\f"+
		"*\16*\u0139\13*\3*\3*\3*\3*\3*\3+\3+\3+\3+\7+\u0144\n+\f+\16+\u0147\13"+
		"+\3+\3+\3,\6,\u014c\n,\r,\16,\u014d\3,\3,\3\u0137\2-\3\3\5\2\7\2\t\2\13"+
		"\2\r\4\17\2\21\2\23\2\25\2\27\2\31\2\33\2\35\5\37\2!\6#\7%\b\'\2)\2+\2"+
		"-\t/\n\61\13\63\f\65\r\67\169\17;\20=\21?\22A\23C\24E\25G\26I\27K\30M"+
		"\31O\32Q\33S\34U\35W\36\3\2\20\4\2$$^^\5\2C\\aac|\3\2\63;\4\2ZZzz\3\2"+
		"\62;\3\2\629\5\2\62;CHch\4\2GGgg\4\2--//\7\2##((,-//``\6\2--//``~~\5\2"+
		"\'\',,\61\61\4\2\13\13\"\"\4\2\f\f\17\17\2\u0165\2\3\3\2\2\2\2\r\3\2\2"+
		"\2\2\35\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2"+
		"\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2"+
		"\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2"+
		"\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U"+
		"\3\2\2\2\2W\3\2\2\2\3Y\3\2\2\2\5f\3\2\2\2\7j\3\2\2\2\tl\3\2\2\2\13q\3"+
		"\2\2\2\ry\3\2\2\2\17{\3\2\2\2\21\u0082\3\2\2\2\23\u0089\3\2\2\2\25\u0090"+
		"\3\2\2\2\27\u0093\3\2\2\2\31\u0097\3\2\2\2\33\u0099\3\2\2\2\35\u00ab\3"+
		"\2\2\2\37\u00ad\3\2\2\2!\u00b5\3\2\2\2#\u00b9\3\2\2\2%\u00c2\3\2\2\2\'"+
		"\u00ce\3\2\2\2)\u00d0\3\2\2\2+\u00da\3\2\2\2-\u00dc\3\2\2\2/\u00e4\3\2"+
		"\2\2\61\u00e9\3\2\2\2\63\u00ed\3\2\2\2\65\u00f2\3\2\2\2\67\u00f6\3\2\2"+
		"\29\u00fc\3\2\2\2;\u0105\3\2\2\2=\u010c\3\2\2\2?\u010f\3\2\2\2A\u0114"+
		"\3\2\2\2C\u011c\3\2\2\2E\u011e\3\2\2\2G\u0120\3\2\2\2I\u0122\3\2\2\2K"+
		"\u0124\3\2\2\2M\u0126\3\2\2\2O\u0128\3\2\2\2Q\u012b\3\2\2\2S\u0131\3\2"+
		"\2\2U\u013f\3\2\2\2W\u014b\3\2\2\2Y`\7$\2\2Z[\7^\2\2[_\t\2\2\2\\_\5\7"+
		"\4\2]_\n\2\2\2^Z\3\2\2\2^\\\3\2\2\2^]\3\2\2\2_b\3\2\2\2`^\3\2\2\2`a\3"+
		"\2\2\2ac\3\2\2\2b`\3\2\2\2cd\7$\2\2d\4\3\2\2\2eg\t\3\2\2fe\3\2\2\2g\6"+
		"\3\2\2\2hk\5\t\5\2ik\5\13\6\2jh\3\2\2\2ji\3\2\2\2k\b\3\2\2\2lm\7^\2\2"+
		"mn\5\31\r\2no\5\31\r\2op\5\31\r\2p\n\3\2\2\2qr\7^\2\2rs\7z\2\2st\5\33"+
		"\16\2tu\5\33\16\2u\f\3\2\2\2vz\5\17\b\2wz\5\21\t\2xz\5\23\n\2yv\3\2\2"+
		"\2yw\3\2\2\2yx\3\2\2\2z\16\3\2\2\2{\177\t\4\2\2|~\5\25\13\2}|\3\2\2\2"+
		"~\u0081\3\2\2\2\177}\3\2\2\2\177\u0080\3\2\2\2\u0080\20\3\2\2\2\u0081"+
		"\177\3\2\2\2\u0082\u0086\7\62\2\2\u0083\u0085\5\31\r\2\u0084\u0083\3\2"+
		"\2\2\u0085\u0088\3\2\2\2\u0086\u0084\3\2\2\2\u0086\u0087\3\2\2\2\u0087"+
		"\22\3\2\2\2\u0088\u0086\3\2\2\2\u0089\u008a\7\62\2\2\u008a\u008c\t\5\2"+
		"\2\u008b\u008d\5\33\16\2\u008c\u008b\3\2\2\2\u008d\u008e\3\2\2\2\u008e"+
		"\u008c\3\2\2\2\u008e\u008f\3\2\2\2\u008f\24\3\2\2\2\u0090\u0091\t\6\2"+
		"\2\u0091\26\3\2\2\2\u0092\u0094\5\25\13\2\u0093\u0092\3\2\2\2\u0094\u0095"+
		"\3\2\2\2\u0095\u0093\3\2\2\2\u0095\u0096\3\2\2\2\u0096\30\3\2\2\2\u0097"+
		"\u0098\t\7\2\2\u0098\32\3\2\2\2\u0099\u009a\t\b\2\2\u009a\34\3\2\2\2\u009b"+
		"\u009c\5\27\f\2\u009c\u009e\7\60\2\2\u009d\u009f\5\27\f\2\u009e\u009d"+
		"\3\2\2\2\u009e\u009f\3\2\2\2\u009f\u00a1\3\2\2\2\u00a0\u00a2\5\37\20\2"+
		"\u00a1\u00a0\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2\u00ac\3\2\2\2\u00a3\u00a4"+
		"\5\27\f\2\u00a4\u00a5\5\37\20\2\u00a5\u00ac\3\2\2\2\u00a6\u00a7\7\60\2"+
		"\2\u00a7\u00a9\5\27\f\2\u00a8\u00aa\5\37\20\2\u00a9\u00a8\3\2\2\2\u00a9"+
		"\u00aa\3\2\2\2\u00aa\u00ac\3\2\2\2\u00ab\u009b\3\2\2\2\u00ab\u00a3\3\2"+
		"\2\2\u00ab\u00a6\3\2\2\2\u00ac\36\3\2\2\2\u00ad\u00af\t\t\2\2\u00ae\u00b0"+
		"\t\n\2\2\u00af\u00ae\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00b1\3\2\2\2\u00b1"+
		"\u00b2\5\27\f\2\u00b2 \3\2\2\2\u00b3\u00b6\5\27\f\2\u00b4\u00b6\5\35\17"+
		"\2\u00b5\u00b3\3\2\2\2\u00b5\u00b4\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7\u00b8"+
		"\7k\2\2\u00b8\"\3\2\2\2\u00b9\u00ba\t\13\2\2\u00ba$\3\2\2\2\u00bb\u00bc"+
		"\7~\2\2\u00bc\u00c3\7~\2\2\u00bd\u00be\7(\2\2\u00be\u00c3\7(\2\2\u00bf"+
		"\u00c3\5\'\24\2\u00c0\u00c3\5)\25\2\u00c1\u00c3\5+\26\2\u00c2\u00bb\3"+
		"\2\2\2\u00c2\u00bd\3\2\2\2\u00c2\u00bf\3\2\2\2\u00c2\u00c0\3\2\2\2\u00c2"+
		"\u00c1\3\2\2\2\u00c3&\3\2\2\2\u00c4\u00c5\7?\2\2\u00c5\u00cf\7?\2\2\u00c6"+
		"\u00c7\7#\2\2\u00c7\u00cf\7?\2\2\u00c8\u00cf\7>\2\2\u00c9\u00ca\7>\2\2"+
		"\u00ca\u00cf\7?\2\2\u00cb\u00cf\7@\2\2\u00cc\u00cd\7@\2\2\u00cd\u00cf"+
		"\7?\2\2\u00ce\u00c4\3\2\2\2\u00ce\u00c6\3\2\2\2\u00ce\u00c8\3\2\2\2\u00ce"+
		"\u00c9\3\2\2\2\u00ce\u00cb\3\2\2\2\u00ce\u00cc\3\2\2\2\u00cf(\3\2\2\2"+
		"\u00d0\u00d1\t\f\2\2\u00d1*\3\2\2\2\u00d2\u00db\t\r\2\2\u00d3\u00d4\7"+
		">\2\2\u00d4\u00db\7>\2\2\u00d5\u00d6\7@\2\2\u00d6\u00db\7@\2\2\u00d7\u00db"+
		"\7(\2\2\u00d8\u00d9\7(\2\2\u00d9\u00db\7`\2\2\u00da\u00d2\3\2\2\2\u00da"+
		"\u00d3\3\2\2\2\u00da\u00d5\3\2\2\2\u00da\u00d7\3\2\2\2\u00da\u00d8\3\2"+
		"\2\2\u00db,\3\2\2\2\u00dc\u00dd\7r\2\2\u00dd\u00de\7c\2\2\u00de\u00df"+
		"\7e\2\2\u00df\u00e0\7m\2\2\u00e0\u00e1\7c\2\2\u00e1\u00e2\7i\2\2\u00e2"+
		"\u00e3\7g\2\2\u00e3.\3\2\2\2\u00e4\u00e5\7v\2\2\u00e5\u00e6\7{\2\2\u00e6"+
		"\u00e7\7r\2\2\u00e7\u00e8\7g\2\2\u00e8\60\3\2\2\2\u00e9\u00ea\7x\2\2\u00ea"+
		"\u00eb\7c\2\2\u00eb\u00ec\7t\2\2\u00ec\62\3\2\2\2\u00ed\u00ee\7h\2\2\u00ee"+
		"\u00ef\7w\2\2\u00ef\u00f0\7p\2\2\u00f0\u00f1\7e\2\2\u00f1\64\3\2\2\2\u00f2"+
		"\u00f3\7h\2\2\u00f3\u00f4\7q\2\2\u00f4\u00f5\7t\2\2\u00f5\66\3\2\2\2\u00f6"+
		"\u00f7\7d\2\2\u00f7\u00f8\7t\2\2\u00f8\u00f9\7g\2\2\u00f9\u00fa\7c\2\2"+
		"\u00fa\u00fb\7m\2\2\u00fb8\3\2\2\2\u00fc\u00fd\7e\2\2\u00fd\u00fe\7q\2"+
		"\2\u00fe\u00ff\7p\2\2\u00ff\u0100\7v\2\2\u0100\u0101\7k\2\2\u0101\u0102"+
		"\7p\2\2\u0102\u0103\7w\2\2\u0103\u0104\7g\2\2\u0104:\3\2\2\2\u0105\u0106"+
		"\7t\2\2\u0106\u0107\7g\2\2\u0107\u0108\7v\2\2\u0108\u0109\7w\2\2\u0109"+
		"\u010a\7t\2\2\u010a\u010b\7p\2\2\u010b<\3\2\2\2\u010c\u010d\7k\2\2\u010d"+
		"\u010e\7h\2\2\u010e>\3\2\2\2\u010f\u0110\7g\2\2\u0110\u0111\7n\2\2\u0111"+
		"\u0112\7u\2\2\u0112\u0113\7g\2\2\u0113@\3\2\2\2\u0114\u0119\5\5\3\2\u0115"+
		"\u0118\5\5\3\2\u0116\u0118\5\25\13\2\u0117\u0115\3\2\2\2\u0117\u0116\3"+
		"\2\2\2\u0118\u011b\3\2\2\2\u0119\u0117\3\2\2\2\u0119\u011a\3\2\2\2\u011a"+
		"B\3\2\2\2\u011b\u0119\3\2\2\2\u011c\u011d\7}\2\2\u011dD\3\2\2\2\u011e"+
		"\u011f\7\177\2\2\u011fF\3\2\2\2\u0120\u0121\7*\2\2\u0121H\3\2\2\2\u0122"+
		"\u0123\7+\2\2\u0123J\3\2\2\2\u0124\u0125\7=\2\2\u0125L\3\2\2\2\u0126\u0127"+
		"\7?\2\2\u0127N\3\2\2\2\u0128\u0129\7.\2\2\u0129P\3\2\2\2\u012a\u012c\t"+
		"\16\2\2\u012b\u012a\3\2\2\2\u012c\u012d\3\2\2\2\u012d\u012b\3\2\2\2\u012d"+
		"\u012e\3\2\2\2\u012e\u012f\3\2\2\2\u012f\u0130\b)\2\2\u0130R\3\2\2\2\u0131"+
		"\u0132\7\61\2\2\u0132\u0133\7,\2\2\u0133\u0137\3\2\2\2\u0134\u0136\13"+
		"\2\2\2\u0135\u0134\3\2\2\2\u0136\u0139\3\2\2\2\u0137\u0138\3\2\2\2\u0137"+
		"\u0135\3\2\2\2\u0138\u013a\3\2\2\2\u0139\u0137\3\2\2\2\u013a\u013b\7,"+
		"\2\2\u013b\u013c\7\61\2\2\u013c\u013d\3\2\2\2\u013d\u013e\b*\2\2\u013e"+
		"T\3\2\2\2\u013f\u0140\7\61\2\2\u0140\u0141\7\61\2\2\u0141\u0145\3\2\2"+
		"\2\u0142\u0144\n\17\2\2\u0143\u0142\3\2\2\2\u0144\u0147\3\2\2\2\u0145"+
		"\u0143\3\2\2\2\u0145\u0146\3\2\2\2\u0146\u0148\3\2\2\2\u0147\u0145\3\2"+
		"\2\2\u0148\u0149\b+\2\2\u0149V\3\2\2\2\u014a\u014c\t\17\2\2\u014b\u014a"+
		"\3\2\2\2\u014c\u014d\3\2\2\2\u014d\u014b\3\2\2\2\u014d\u014e\3\2\2\2\u014e"+
		"\u014f\3\2\2\2\u014f\u0150\b,\2\2\u0150X\3\2\2\2\33\2^`fjy\177\u0086\u008e"+
		"\u0095\u009e\u00a1\u00a9\u00ab\u00af\u00b5\u00c2\u00ce\u00da\u0117\u0119"+
		"\u012d\u0137\u0145\u014d\3\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}