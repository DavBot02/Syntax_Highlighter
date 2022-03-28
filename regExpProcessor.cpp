#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

vector<tuple<string, string>> colorRegExp(vector<string> outRegExps) {
    vector<tuple<string, string>> colorRegExp;
    vector<string> colors {"burlywood", "crimson", "blue", "fuchsia", 
                            "green", "slateblue", "blueviolet", "coral", "deepskyblue", 
                            "indigo", "maroon", "tomato"};

    for (int i = 0; i < outRegExps.size(); i++) {
        tuple<string, string> aux;
        aux = make_tuple(outRegExps[i], colors[i]);
        colorRegExp.push_back(aux);
    }

    return colorRegExp;
}


vector<string> readRegExps(string regExpFile) {
    ifstream myfile(regExpFile);
    string line;

    vector<string> outRegExps;

    while (getline(myfile, line)) {
        line = line.substr(0, line.size() - 1);
        outRegExps.push_back(line);
    }

    myfile.close();

    return outRegExps;
}


void writeRegExps(vector<tuple<string, string>> colorRegExp) {
    ofstream myfile;
    myfile.open("lexico.l");

    string line;

    if (myfile.is_open()) {
        myfile << "%{" << endl;
        myfile << "\t#include <stdio.h>" << endl;
        myfile << "\t#include <stdlib.h>" << endl;
        myfile << "\tFILE* myfile = fopen(\"final.html\", \"a\");" << endl;
        myfile << "%}" << endl;
        myfile << "\%option c++" << endl;
        myfile << "\%option outfile=\"scanner.cpp\"" << endl;
        myfile << "\%option noyywrap" << endl;
        myfile << "\%%" << endl;
        
        //fprintf(myfile, \"<span> \\\%emsp </span>\");"
        myfile << "\"\\t\"|\"    \"    fprintf(myfile, \"&emsp;\"); "	 << endl;
        myfile << "\"\\n\"	    fprintf(myfile, \"<br>\");" << endl;
        for (int i = 0; i < colorRegExp.size(); i++) {
            myfile <<  get<0>(colorRegExp[i]) << "\tfprintf(myfile, \"<span style = \\\"color: " << get<1>(colorRegExp[i]) << "\\\">\%s</span>\", yytext);" << endl;
        }

        myfile << "\%%";
    }

    myfile.close();

}




int main() {
    writeRegExps(colorRegExp(readRegExps("regularexpressions.txt")));
    
    return 0; 
}
