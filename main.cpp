#include "FlexLexer.h"
#include <bits/stdc++.h>

using namespace std;

void htmlBuilder() {
    ofstream myfile;
    myfile.open("final.html");

    if (myfile.is_open()) {
        myfile << "<!DOCTYPE html>" << endl;
        myfile << "<html lang=\"en\">" << endl;
        myfile << "<head>" << endl;
        myfile << "\t<meta charset=\"UTF-8\">" << endl;
        myfile << "\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" << endl;
        myfile << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
        myfile << "\t<title>Document</title>" << endl;
        myfile << "</head>" << endl;
        myfile << "<body>" << endl;
    }

    myfile.close();
    
    system("./lexer.out");

    myfile.open("final.html", ios_base::app);
    if (myfile.is_open()) {
        myfile << "\n</body>" << endl;
    }

}

int main() {

    system("g++ regExpProcessor.cpp -o regExpProcessor.out");
    system("./regExpProcessor.out");
    system("lex lexico.l");
    system("g++ scanner.cpp lexer.cpp -o lexer.out");

    htmlBuilder();
    return 0;
}