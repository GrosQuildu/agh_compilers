// Generated from Go2LLVMParser.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class Go2LLVMParser extends Parser {
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
	public static final int
		RULE_sourceFile = 0, RULE_packageClause = 1, RULE_topLevelDecl = 2, RULE_block = 3, 
		RULE_statementList = 4, RULE_statement = 5, RULE_returnStmt = 6, RULE_simpleStmt = 7, 
		RULE_assignment = 8, RULE_emptyStmt = 9, RULE_declaration = 10, RULE_identifierList = 11, 
		RULE_expressionList = 12, RULE_type = 13, RULE_expression = 14, RULE_unaryExpr = 15, 
		RULE_operand = 16, RULE_basicLit = 17, RULE_function = 18, RULE_signature = 19, 
		RULE_result = 20, RULE_parameters = 21, RULE_parameterList = 22, RULE_parameterDecl = 23, 
		RULE_eos = 24;
	public static final String[] ruleNames = {
		"sourceFile", "packageClause", "topLevelDecl", "block", "statementList", 
		"statement", "returnStmt", "simpleStmt", "assignment", "emptyStmt", "declaration", 
		"identifierList", "expressionList", "type", "expression", "unaryExpr", 
		"operand", "basicLit", "function", "signature", "result", "parameters", 
		"parameterList", "parameterDecl", "eos"
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

	@Override
	public String getGrammarFileName() { return "Go2LLVMParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public Go2LLVMParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class SourceFileContext extends ParserRuleContext {
		public PackageClauseContext packageClause() {
			return getRuleContext(PackageClauseContext.class,0);
		}
		public List<EosContext> eos() {
			return getRuleContexts(EosContext.class);
		}
		public EosContext eos(int i) {
			return getRuleContext(EosContext.class,i);
		}
		public List<TopLevelDeclContext> topLevelDecl() {
			return getRuleContexts(TopLevelDeclContext.class);
		}
		public TopLevelDeclContext topLevelDecl(int i) {
			return getRuleContext(TopLevelDeclContext.class,i);
		}
		public SourceFileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sourceFile; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterSourceFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitSourceFile(this);
		}
	}

	public final SourceFileContext sourceFile() throws RecognitionException {
		SourceFileContext _localctx = new SourceFileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_sourceFile);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			packageClause();
			setState(51);
			eos();
			setState(57);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==VAR_TOK || _la==FUNC_TOK) {
				{
				{
				setState(52);
				topLevelDecl();
				setState(53);
				eos();
				}
				}
				setState(59);
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

	public static class PackageClauseContext extends ParserRuleContext {
		public TerminalNode PACKAGE_TOK() { return getToken(Go2LLVMParser.PACKAGE_TOK, 0); }
		public TerminalNode IDENT_TOK() { return getToken(Go2LLVMParser.IDENT_TOK, 0); }
		public PackageClauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_packageClause; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterPackageClause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitPackageClause(this);
		}
	}

	public final PackageClauseContext packageClause() throws RecognitionException {
		PackageClauseContext _localctx = new PackageClauseContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_packageClause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(PACKAGE_TOK);
			setState(61);
			match(IDENT_TOK);
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

	public static class TopLevelDeclContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public TopLevelDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_topLevelDecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterTopLevelDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitTopLevelDecl(this);
		}
	}

	public final TopLevelDeclContext topLevelDecl() throws RecognitionException {
		TopLevelDeclContext _localctx = new TopLevelDeclContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_topLevelDecl);
		try {
			setState(65);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR_TOK:
				enterOuterAlt(_localctx, 1);
				{
				setState(63);
				declaration();
				}
				break;
			case FUNC_TOK:
				enterOuterAlt(_localctx, 2);
				{
				setState(64);
				function();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode BO() { return getToken(Go2LLVMParser.BO, 0); }
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public TerminalNode BC() { return getToken(Go2LLVMParser.BC, 0); }
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(67);
			match(BO);
			setState(68);
			statementList();
			setState(69);
			match(BC);
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

	public static class StatementListContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<EosContext> eos() {
			return getRuleContexts(EosContext.class);
		}
		public EosContext eos(int i) {
			return getRuleContext(EosContext.class,i);
		}
		public StatementListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statementList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterStatementList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitStatementList(this);
		}
	}

	public final StatementListContext statementList() throws RecognitionException {
		StatementListContext _localctx = new StatementListContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_statementList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STRING_TOK) | (1L << INT_TOK) | (1L << FLOAT_TOK) | (1L << IMAG_TOK) | (1L << UNARY_OP_TOK) | (1L << VAR_TOK) | (1L << RETURN_TOK) | (1L << IDENT_TOK) | (1L << BO) | (1L << PO) | (1L << SEMICOLON))) != 0)) {
				{
				{
				setState(71);
				statement();
				setState(72);
				eos();
				}
				}
				setState(78);
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

	public static class StatementContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public SimpleStmtContext simpleStmt() {
			return getRuleContext(SimpleStmtContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ReturnStmtContext returnStmt() {
			return getRuleContext(ReturnStmtContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_statement);
		try {
			setState(83);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR_TOK:
				enterOuterAlt(_localctx, 1);
				{
				setState(79);
				declaration();
				}
				break;
			case STRING_TOK:
			case INT_TOK:
			case FLOAT_TOK:
			case IMAG_TOK:
			case UNARY_OP_TOK:
			case IDENT_TOK:
			case PO:
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				setState(80);
				simpleStmt();
				}
				break;
			case BO:
				enterOuterAlt(_localctx, 3);
				{
				setState(81);
				block();
				}
				break;
			case RETURN_TOK:
				enterOuterAlt(_localctx, 4);
				{
				setState(82);
				returnStmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class ReturnStmtContext extends ParserRuleContext {
		public TerminalNode RETURN_TOK() { return getToken(Go2LLVMParser.RETURN_TOK, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public ReturnStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnStmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterReturnStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitReturnStmt(this);
		}
	}

	public final ReturnStmtContext returnStmt() throws RecognitionException {
		ReturnStmtContext _localctx = new ReturnStmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_returnStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			match(RETURN_TOK);
			setState(87);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STRING_TOK) | (1L << INT_TOK) | (1L << FLOAT_TOK) | (1L << IMAG_TOK) | (1L << UNARY_OP_TOK) | (1L << IDENT_TOK) | (1L << PO))) != 0)) {
				{
				setState(86);
				expressionList();
				}
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

	public static class SimpleStmtContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public EmptyStmtContext emptyStmt() {
			return getRuleContext(EmptyStmtContext.class,0);
		}
		public SimpleStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleStmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterSimpleStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitSimpleStmt(this);
		}
	}

	public final SimpleStmtContext simpleStmt() throws RecognitionException {
		SimpleStmtContext _localctx = new SimpleStmtContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_simpleStmt);
		try {
			setState(92);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(89);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(90);
				assignment();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(91);
				emptyStmt();
				}
				break;
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

	public static class AssignmentContext extends ParserRuleContext {
		public List<ExpressionListContext> expressionList() {
			return getRuleContexts(ExpressionListContext.class);
		}
		public ExpressionListContext expressionList(int i) {
			return getRuleContext(ExpressionListContext.class,i);
		}
		public TerminalNode EQ() { return getToken(Go2LLVMParser.EQ, 0); }
		public TerminalNode BINARY_OP_TOK() { return getToken(Go2LLVMParser.BINARY_OP_TOK, 0); }
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitAssignment(this);
		}
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_assignment);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(94);
			expressionList();
			setState(96);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==BINARY_OP_TOK) {
				{
				setState(95);
				match(BINARY_OP_TOK);
				}
			}

			setState(98);
			match(EQ);
			setState(99);
			expressionList();
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

	public static class EmptyStmtContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(Go2LLVMParser.SEMICOLON, 0); }
		public EmptyStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emptyStmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterEmptyStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitEmptyStmt(this);
		}
	}

	public final EmptyStmtContext emptyStmt() throws RecognitionException {
		EmptyStmtContext _localctx = new EmptyStmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_emptyStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(101);
			match(SEMICOLON);
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

	public static class DeclarationContext extends ParserRuleContext {
		public TerminalNode VAR_TOK() { return getToken(Go2LLVMParser.VAR_TOK, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode EQ() { return getToken(Go2LLVMParser.EQ, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitDeclaration(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			match(VAR_TOK);
			setState(104);
			identifierList();
			setState(105);
			type();
			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EQ) {
				{
				setState(106);
				match(EQ);
				setState(107);
				expressionList();
				}
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

	public static class IdentifierListContext extends ParserRuleContext {
		public List<TerminalNode> IDENT_TOK() { return getTokens(Go2LLVMParser.IDENT_TOK); }
		public TerminalNode IDENT_TOK(int i) {
			return getToken(Go2LLVMParser.IDENT_TOK, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(Go2LLVMParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(Go2LLVMParser.COMMA, i);
		}
		public IdentifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifierList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterIdentifierList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitIdentifierList(this);
		}
	}

	public final IdentifierListContext identifierList() throws RecognitionException {
		IdentifierListContext _localctx = new IdentifierListContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_identifierList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			match(IDENT_TOK);
			setState(115);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(111);
				match(COMMA);
				setState(112);
				match(IDENT_TOK);
				}
				}
				setState(117);
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

	public static class ExpressionListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(Go2LLVMParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(Go2LLVMParser.COMMA, i);
		}
		public ExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitExpressionList(this);
		}
	}

	public final ExpressionListContext expressionList() throws RecognitionException {
		ExpressionListContext _localctx = new ExpressionListContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_expressionList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			expression(0);
			setState(123);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(119);
				match(COMMA);
				setState(120);
				expression(0);
				}
				}
				setState(125);
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

	public static class TypeContext extends ParserRuleContext {
		public TerminalNode IDENT_TOK() { return getToken(Go2LLVMParser.IDENT_TOK, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitType(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(126);
			match(IDENT_TOK);
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

	public static class ExpressionContext extends ParserRuleContext {
		public UnaryExprContext unaryExpr() {
			return getRuleContext(UnaryExprContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode BINARY_OP_TOK() { return getToken(Go2LLVMParser.BINARY_OP_TOK, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 28;
		enterRecursionRule(_localctx, 28, RULE_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(129);
			unaryExpr();
			}
			_ctx.stop = _input.LT(-1);
			setState(136);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expression);
					setState(131);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(132);
					match(BINARY_OP_TOK);
					setState(133);
					expression(2);
					}
					} 
				}
				setState(138);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class UnaryExprContext extends ParserRuleContext {
		public OperandContext operand() {
			return getRuleContext(OperandContext.class,0);
		}
		public TerminalNode UNARY_OP_TOK() { return getToken(Go2LLVMParser.UNARY_OP_TOK, 0); }
		public UnaryExprContext unaryExpr() {
			return getRuleContext(UnaryExprContext.class,0);
		}
		public UnaryExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryExpr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterUnaryExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitUnaryExpr(this);
		}
	}

	public final UnaryExprContext unaryExpr() throws RecognitionException {
		UnaryExprContext _localctx = new UnaryExprContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_unaryExpr);
		try {
			setState(142);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING_TOK:
			case INT_TOK:
			case FLOAT_TOK:
			case IMAG_TOK:
			case IDENT_TOK:
			case PO:
				enterOuterAlt(_localctx, 1);
				{
				setState(139);
				operand();
				}
				break;
			case UNARY_OP_TOK:
				enterOuterAlt(_localctx, 2);
				{
				setState(140);
				match(UNARY_OP_TOK);
				setState(141);
				unaryExpr();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class OperandContext extends ParserRuleContext {
		public BasicLitContext basicLit() {
			return getRuleContext(BasicLitContext.class,0);
		}
		public TerminalNode IDENT_TOK() { return getToken(Go2LLVMParser.IDENT_TOK, 0); }
		public TerminalNode PO() { return getToken(Go2LLVMParser.PO, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode PC() { return getToken(Go2LLVMParser.PC, 0); }
		public OperandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_operand; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterOperand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitOperand(this);
		}
	}

	public final OperandContext operand() throws RecognitionException {
		OperandContext _localctx = new OperandContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_operand);
		try {
			setState(150);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING_TOK:
			case INT_TOK:
			case FLOAT_TOK:
			case IMAG_TOK:
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				basicLit();
				}
				break;
			case IDENT_TOK:
				enterOuterAlt(_localctx, 2);
				{
				setState(145);
				match(IDENT_TOK);
				}
				break;
			case PO:
				enterOuterAlt(_localctx, 3);
				{
				setState(146);
				match(PO);
				setState(147);
				expression(0);
				setState(148);
				match(PC);
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class BasicLitContext extends ParserRuleContext {
		public TerminalNode INT_TOK() { return getToken(Go2LLVMParser.INT_TOK, 0); }
		public TerminalNode FLOAT_TOK() { return getToken(Go2LLVMParser.FLOAT_TOK, 0); }
		public TerminalNode IMAG_TOK() { return getToken(Go2LLVMParser.IMAG_TOK, 0); }
		public TerminalNode STRING_TOK() { return getToken(Go2LLVMParser.STRING_TOK, 0); }
		public BasicLitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basicLit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterBasicLit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitBasicLit(this);
		}
	}

	public final BasicLitContext basicLit() throws RecognitionException {
		BasicLitContext _localctx = new BasicLitContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_basicLit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(152);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STRING_TOK) | (1L << INT_TOK) | (1L << FLOAT_TOK) | (1L << IMAG_TOK))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
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

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode FUNC_TOK() { return getToken(Go2LLVMParser.FUNC_TOK, 0); }
		public SignatureContext signature() {
			return getRuleContext(SignatureContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterFunction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitFunction(this);
		}
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
			match(FUNC_TOK);
			setState(155);
			signature();
			setState(156);
			block();
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

	public static class SignatureContext extends ParserRuleContext {
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public ResultContext result() {
			return getRuleContext(ResultContext.class,0);
		}
		public SignatureContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signature; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterSignature(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitSignature(this);
		}
	}

	public final SignatureContext signature() throws RecognitionException {
		SignatureContext _localctx = new SignatureContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_signature);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			parameters();
			setState(160);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENT_TOK || _la==PO) {
				{
				setState(159);
				result();
				}
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

	public static class ResultContext extends ParserRuleContext {
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ResultContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_result; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterResult(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitResult(this);
		}
	}

	public final ResultContext result() throws RecognitionException {
		ResultContext _localctx = new ResultContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_result);
		try {
			setState(164);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PO:
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				parameters();
				}
				break;
			case IDENT_TOK:
				enterOuterAlt(_localctx, 2);
				{
				setState(163);
				type();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class ParametersContext extends ParserRuleContext {
		public TerminalNode PO() { return getToken(Go2LLVMParser.PO, 0); }
		public TerminalNode PC() { return getToken(Go2LLVMParser.PC, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(Go2LLVMParser.COMMA, 0); }
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterParameters(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitParameters(this);
		}
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_parameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(166);
			match(PO);
			setState(171);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENT_TOK) {
				{
				setState(167);
				parameterList();
				setState(169);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(168);
					match(COMMA);
					}
				}

				}
			}

			setState(173);
			match(PC);
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

	public static class ParameterListContext extends ParserRuleContext {
		public List<ParameterDeclContext> parameterDecl() {
			return getRuleContexts(ParameterDeclContext.class);
		}
		public ParameterDeclContext parameterDecl(int i) {
			return getRuleContext(ParameterDeclContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(Go2LLVMParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(Go2LLVMParser.COMMA, i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterParameterList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitParameterList(this);
		}
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_parameterList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(175);
			parameterDecl();
			setState(180);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(176);
					match(COMMA);
					setState(177);
					parameterDecl();
					}
					} 
				}
				setState(182);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
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

	public static class ParameterDeclContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public ParameterDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterDecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterParameterDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitParameterDecl(this);
		}
	}

	public final ParameterDeclContext parameterDecl() throws RecognitionException {
		ParameterDeclContext _localctx = new ParameterDeclContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_parameterDecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(184);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(183);
				identifierList();
				}
				break;
			}
			setState(186);
			type();
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

	public static class EosContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(Go2LLVMParser.SEMICOLON, 0); }
		public TerminalNode EOF() { return getToken(Go2LLVMParser.EOF, 0); }
		public EosContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_eos; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).enterEos(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof Go2LLVMParserListener ) ((Go2LLVMParserListener)listener).exitEos(this);
		}
	}

	public final EosContext eos() throws RecognitionException {
		EosContext _localctx = new EosContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_eos);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(188);
			_la = _input.LA(1);
			if ( !(_la==EOF || _la==SEMICOLON) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 14:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\36\u00c1\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\3\2\3\2\3\2\3\2\3\2\7\2:\n\2\f\2\16\2=\13\2\3\3\3\3\3\3\3\4"+
		"\3\4\5\4D\n\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\7\6M\n\6\f\6\16\6P\13\6\3\7"+
		"\3\7\3\7\3\7\5\7V\n\7\3\b\3\b\5\bZ\n\b\3\t\3\t\3\t\5\t_\n\t\3\n\3\n\5"+
		"\nc\n\n\3\n\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\f\3\f\5\fo\n\f\3\r\3\r\3\r"+
		"\7\rt\n\r\f\r\16\rw\13\r\3\16\3\16\3\16\7\16|\n\16\f\16\16\16\177\13\16"+
		"\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\7\20\u0089\n\20\f\20\16\20\u008c"+
		"\13\20\3\21\3\21\3\21\5\21\u0091\n\21\3\22\3\22\3\22\3\22\3\22\3\22\5"+
		"\22\u0099\n\22\3\23\3\23\3\24\3\24\3\24\3\24\3\25\3\25\5\25\u00a3\n\25"+
		"\3\26\3\26\5\26\u00a7\n\26\3\27\3\27\3\27\5\27\u00ac\n\27\5\27\u00ae\n"+
		"\27\3\27\3\27\3\30\3\30\3\30\7\30\u00b5\n\30\f\30\16\30\u00b8\13\30\3"+
		"\31\5\31\u00bb\n\31\3\31\3\31\3\32\3\32\3\32\2\3\36\33\2\4\6\b\n\f\16"+
		"\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\2\4\3\2\3\6\3\3\30\30\2\u00be"+
		"\2\64\3\2\2\2\4>\3\2\2\2\6C\3\2\2\2\bE\3\2\2\2\nN\3\2\2\2\fU\3\2\2\2\16"+
		"W\3\2\2\2\20^\3\2\2\2\22`\3\2\2\2\24g\3\2\2\2\26i\3\2\2\2\30p\3\2\2\2"+
		"\32x\3\2\2\2\34\u0080\3\2\2\2\36\u0082\3\2\2\2 \u0090\3\2\2\2\"\u0098"+
		"\3\2\2\2$\u009a\3\2\2\2&\u009c\3\2\2\2(\u00a0\3\2\2\2*\u00a6\3\2\2\2,"+
		"\u00a8\3\2\2\2.\u00b1\3\2\2\2\60\u00ba\3\2\2\2\62\u00be\3\2\2\2\64\65"+
		"\5\4\3\2\65;\5\62\32\2\66\67\5\6\4\2\678\5\62\32\28:\3\2\2\29\66\3\2\2"+
		"\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2<\3\3\2\2\2=;\3\2\2\2>?\7\t\2\2?@\7\23"+
		"\2\2@\5\3\2\2\2AD\5\26\f\2BD\5&\24\2CA\3\2\2\2CB\3\2\2\2D\7\3\2\2\2EF"+
		"\7\24\2\2FG\5\n\6\2GH\7\25\2\2H\t\3\2\2\2IJ\5\f\7\2JK\5\62\32\2KM\3\2"+
		"\2\2LI\3\2\2\2MP\3\2\2\2NL\3\2\2\2NO\3\2\2\2O\13\3\2\2\2PN\3\2\2\2QV\5"+
		"\26\f\2RV\5\20\t\2SV\5\b\5\2TV\5\16\b\2UQ\3\2\2\2UR\3\2\2\2US\3\2\2\2"+
		"UT\3\2\2\2V\r\3\2\2\2WY\7\20\2\2XZ\5\32\16\2YX\3\2\2\2YZ\3\2\2\2Z\17\3"+
		"\2\2\2[_\5\36\20\2\\_\5\22\n\2]_\5\24\13\2^[\3\2\2\2^\\\3\2\2\2^]\3\2"+
		"\2\2_\21\3\2\2\2`b\5\32\16\2ac\7\b\2\2ba\3\2\2\2bc\3\2\2\2cd\3\2\2\2d"+
		"e\7\31\2\2ef\5\32\16\2f\23\3\2\2\2gh\7\30\2\2h\25\3\2\2\2ij\7\13\2\2j"+
		"k\5\30\r\2kn\5\34\17\2lm\7\31\2\2mo\5\32\16\2nl\3\2\2\2no\3\2\2\2o\27"+
		"\3\2\2\2pu\7\23\2\2qr\7\32\2\2rt\7\23\2\2sq\3\2\2\2tw\3\2\2\2us\3\2\2"+
		"\2uv\3\2\2\2v\31\3\2\2\2wu\3\2\2\2x}\5\36\20\2yz\7\32\2\2z|\5\36\20\2"+
		"{y\3\2\2\2|\177\3\2\2\2}{\3\2\2\2}~\3\2\2\2~\33\3\2\2\2\177}\3\2\2\2\u0080"+
		"\u0081\7\23\2\2\u0081\35\3\2\2\2\u0082\u0083\b\20\1\2\u0083\u0084\5 \21"+
		"\2\u0084\u008a\3\2\2\2\u0085\u0086\f\3\2\2\u0086\u0087\7\b\2\2\u0087\u0089"+
		"\5\36\20\4\u0088\u0085\3\2\2\2\u0089\u008c\3\2\2\2\u008a\u0088\3\2\2\2"+
		"\u008a\u008b\3\2\2\2\u008b\37\3\2\2\2\u008c\u008a\3\2\2\2\u008d\u0091"+
		"\5\"\22\2\u008e\u008f\7\7\2\2\u008f\u0091\5 \21\2\u0090\u008d\3\2\2\2"+
		"\u0090\u008e\3\2\2\2\u0091!\3\2\2\2\u0092\u0099\5$\23\2\u0093\u0099\7"+
		"\23\2\2\u0094\u0095\7\26\2\2\u0095\u0096\5\36\20\2\u0096\u0097\7\27\2"+
		"\2\u0097\u0099\3\2\2\2\u0098\u0092\3\2\2\2\u0098\u0093\3\2\2\2\u0098\u0094"+
		"\3\2\2\2\u0099#\3\2\2\2\u009a\u009b\t\2\2\2\u009b%\3\2\2\2\u009c\u009d"+
		"\7\f\2\2\u009d\u009e\5(\25\2\u009e\u009f\5\b\5\2\u009f\'\3\2\2\2\u00a0"+
		"\u00a2\5,\27\2\u00a1\u00a3\5*\26\2\u00a2\u00a1\3\2\2\2\u00a2\u00a3\3\2"+
		"\2\2\u00a3)\3\2\2\2\u00a4\u00a7\5,\27\2\u00a5\u00a7\5\34\17\2\u00a6\u00a4"+
		"\3\2\2\2\u00a6\u00a5\3\2\2\2\u00a7+\3\2\2\2\u00a8\u00ad\7\26\2\2\u00a9"+
		"\u00ab\5.\30\2\u00aa\u00ac\7\32\2\2\u00ab\u00aa\3\2\2\2\u00ab\u00ac\3"+
		"\2\2\2\u00ac\u00ae\3\2\2\2\u00ad\u00a9\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"\u00af\3\2\2\2\u00af\u00b0\7\27\2\2\u00b0-\3\2\2\2\u00b1\u00b6\5\60\31"+
		"\2\u00b2\u00b3\7\32\2\2\u00b3\u00b5\5\60\31\2\u00b4\u00b2\3\2\2\2\u00b5"+
		"\u00b8\3\2\2\2\u00b6\u00b4\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7/\3\2\2\2"+
		"\u00b8\u00b6\3\2\2\2\u00b9\u00bb\5\30\r\2\u00ba\u00b9\3\2\2\2\u00ba\u00bb"+
		"\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\u00bd\5\34\17\2\u00bd\61\3\2\2\2\u00be"+
		"\u00bf\t\3\2\2\u00bf\63\3\2\2\2\25;CNUY^bnu}\u008a\u0090\u0098\u00a2\u00a6"+
		"\u00ab\u00ad\u00b6\u00ba";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}