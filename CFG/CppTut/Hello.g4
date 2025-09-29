// Define a grammar called Hello
// IMPORTANT: COMPILE WITH javac -cp "/usr/local/lib/antlr-4.13.2-complete.jar:." *.java
// OR ADD THIS LINE TO BASHRC: alias antlr4-compile='javac -cp "/usr/local/lib/antlr-4.13.2-complete.jar:."'
grammar Hello;
r  : 'hello' ID ;         // match keyword hello followed by an identifier
ID : [a-z]+ ;             // match lower-case identifiers
WS : [ \t\r\n]+ -> skip ; // skip spaces, tabs, newlines