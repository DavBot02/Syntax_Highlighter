//Construcción del archivo HTML. Indica la ejecución del resto de archivos en el punto medio para 
//llenarlo con el texto proveido en test.txt.

#include "FlexLexer.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string> 
#include <typeinfo>

using namespace std;

void htmlBuilder(string inputFile) {
    ofstream myfile;
    myfile.open("final_" + inputFile + ".html");

    if (myfile.is_open()) {
        myfile << "<!DOCTYPE html>" << endl;
        myfile << "<html lang=\"en\">" << endl;
        myfile << "<head>" << endl;
        myfile << "\t<meta charset=\"UTF-8\">" << endl;
        myfile << "\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" << endl;
        myfile << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
        myfile << "\t<title>Highlighted Text</title>" << endl;
        myfile << "<link rel=\"icon\" href=\"https://upload.wikimedia.org/wikipedia/commons/b/b0/Light_green_check.svg\">" << endl;
        myfile << "</head>" << endl;
        myfile << "<body>" << endl; 
    }

    myfile.close();
    
    system((string("./scanner_") + inputFile + string(".out")).c_str());

    myfile.open("final_" + inputFile + ".html", ios_base::app);
    if (myfile.is_open()) {
        myfile << "\n</body>" << endl;
    }

}

int main(int argc, char *argv[]) {
    system((string("g++ regexProcessor.cpp -o regexProcessor_") + argv[1] + string(".out")).c_str());
	system((string("./regexProcessor_") + argv[1] + string(".out ") + argv[1]).c_str());
    system((string("lex lexico_") + argv[1] + string(".l")).c_str());
    system((string("g++ scanner_") + argv[1] + string(".cpp -o scanner_") + argv[1] + string(".out")).c_str());

    htmlBuilder(argv[1]);
    return 0;
}