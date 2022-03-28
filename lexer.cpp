#include "FlexLexer.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {

	ifstream toAnalyze("test.txt");

    yyFlexLexer* lexer = new yyFlexLexer(&toAnalyze);
    while (lexer->yylex() != 0) {
        ;
    }

    return 0;

}