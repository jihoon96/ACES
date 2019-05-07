ANTLR4=java -jar /usr/local/lib/antlr-4.7.2-complete.jar
GRUN=java org.antlr.v4.gui.TestRig
ROOT=json
INPUT=input.txt

all:
	$(ANTLR4) MyLexer.g4
	$(ANTLR4) MyParser.g4
	javac MyLexer.java MyParser.java

run: all
	$(GRUN) My $(ROOT) -gui < $(INPUT)

tree: all
	$(GRUN) My $(ROOT) -tree < $(INPUT) > out.txt

clean:
	rm *.class *.java *.interp *.tokens
