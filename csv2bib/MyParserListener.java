// Generated from MyParser.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MyParser}.
 */
public interface MyParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MyParser#document}.
	 * @param ctx the parse tree
	 */
	void enterDocument(MyParser.DocumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParser#document}.
	 * @param ctx the parse tree
	 */
	void exitDocument(MyParser.DocumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParser#title}.
	 * @param ctx the parse tree
	 */
	void enterTitle(MyParser.TitleContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParser#title}.
	 * @param ctx the parse tree
	 */
	void exitTitle(MyParser.TitleContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParser#infos}.
	 * @param ctx the parse tree
	 */
	void enterInfos(MyParser.InfosContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParser#infos}.
	 * @param ctx the parse tree
	 */
	void exitInfos(MyParser.InfosContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParser#info}.
	 * @param ctx the parse tree
	 */
	void enterInfo(MyParser.InfoContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParser#info}.
	 * @param ctx the parse tree
	 */
	void exitInfo(MyParser.InfoContext ctx);
}