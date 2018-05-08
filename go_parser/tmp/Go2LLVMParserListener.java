// Generated from Go2LLVMParser.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link Go2LLVMParser}.
 */
public interface Go2LLVMParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#sourceFile}.
	 * @param ctx the parse tree
	 */
	void enterSourceFile(Go2LLVMParser.SourceFileContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#sourceFile}.
	 * @param ctx the parse tree
	 */
	void exitSourceFile(Go2LLVMParser.SourceFileContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#packageClause}.
	 * @param ctx the parse tree
	 */
	void enterPackageClause(Go2LLVMParser.PackageClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#packageClause}.
	 * @param ctx the parse tree
	 */
	void exitPackageClause(Go2LLVMParser.PackageClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#topLevelDecl}.
	 * @param ctx the parse tree
	 */
	void enterTopLevelDecl(Go2LLVMParser.TopLevelDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#topLevelDecl}.
	 * @param ctx the parse tree
	 */
	void exitTopLevelDecl(Go2LLVMParser.TopLevelDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(Go2LLVMParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(Go2LLVMParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#statementList}.
	 * @param ctx the parse tree
	 */
	void enterStatementList(Go2LLVMParser.StatementListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#statementList}.
	 * @param ctx the parse tree
	 */
	void exitStatementList(Go2LLVMParser.StatementListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(Go2LLVMParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(Go2LLVMParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#returnStmt}.
	 * @param ctx the parse tree
	 */
	void enterReturnStmt(Go2LLVMParser.ReturnStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#returnStmt}.
	 * @param ctx the parse tree
	 */
	void exitReturnStmt(Go2LLVMParser.ReturnStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#simpleStmt}.
	 * @param ctx the parse tree
	 */
	void enterSimpleStmt(Go2LLVMParser.SimpleStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#simpleStmt}.
	 * @param ctx the parse tree
	 */
	void exitSimpleStmt(Go2LLVMParser.SimpleStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(Go2LLVMParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(Go2LLVMParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#emptyStmt}.
	 * @param ctx the parse tree
	 */
	void enterEmptyStmt(Go2LLVMParser.EmptyStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#emptyStmt}.
	 * @param ctx the parse tree
	 */
	void exitEmptyStmt(Go2LLVMParser.EmptyStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(Go2LLVMParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(Go2LLVMParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#identifierList}.
	 * @param ctx the parse tree
	 */
	void enterIdentifierList(Go2LLVMParser.IdentifierListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#identifierList}.
	 * @param ctx the parse tree
	 */
	void exitIdentifierList(Go2LLVMParser.IdentifierListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(Go2LLVMParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(Go2LLVMParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(Go2LLVMParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(Go2LLVMParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(Go2LLVMParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(Go2LLVMParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#unaryExpr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryExpr(Go2LLVMParser.UnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#unaryExpr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryExpr(Go2LLVMParser.UnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#operand}.
	 * @param ctx the parse tree
	 */
	void enterOperand(Go2LLVMParser.OperandContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#operand}.
	 * @param ctx the parse tree
	 */
	void exitOperand(Go2LLVMParser.OperandContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#basicLit}.
	 * @param ctx the parse tree
	 */
	void enterBasicLit(Go2LLVMParser.BasicLitContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#basicLit}.
	 * @param ctx the parse tree
	 */
	void exitBasicLit(Go2LLVMParser.BasicLitContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(Go2LLVMParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(Go2LLVMParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#signature}.
	 * @param ctx the parse tree
	 */
	void enterSignature(Go2LLVMParser.SignatureContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#signature}.
	 * @param ctx the parse tree
	 */
	void exitSignature(Go2LLVMParser.SignatureContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#result}.
	 * @param ctx the parse tree
	 */
	void enterResult(Go2LLVMParser.ResultContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#result}.
	 * @param ctx the parse tree
	 */
	void exitResult(Go2LLVMParser.ResultContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#parameters}.
	 * @param ctx the parse tree
	 */
	void enterParameters(Go2LLVMParser.ParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#parameters}.
	 * @param ctx the parse tree
	 */
	void exitParameters(Go2LLVMParser.ParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void enterParameterList(Go2LLVMParser.ParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void exitParameterList(Go2LLVMParser.ParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#parameterDecl}.
	 * @param ctx the parse tree
	 */
	void enterParameterDecl(Go2LLVMParser.ParameterDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#parameterDecl}.
	 * @param ctx the parse tree
	 */
	void exitParameterDecl(Go2LLVMParser.ParameterDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link Go2LLVMParser#eos}.
	 * @param ctx the parse tree
	 */
	void enterEos(Go2LLVMParser.EosContext ctx);
	/**
	 * Exit a parse tree produced by {@link Go2LLVMParser#eos}.
	 * @param ctx the parse tree
	 */
	void exitEos(Go2LLVMParser.EosContext ctx);
}