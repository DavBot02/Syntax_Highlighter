//funcion main de scanner.cpp. Se separó con el propósito de visualizarlo de forma más sencilla.

#include "FlexLexer.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {

    //abre el archivo a analizar
	ifstream toAnalyze("test.txt");

    //crea un objeto yyFlexLexer e indica su lectura con yylex().
    yyFlexLexer* lexer = new yyFlexLexer(&toAnalyze);
    while (lexer->yylex() != 0) {
        ;
    }

    return 0;

}