// Lectura, asignación de colores y escritura de expresiones regulares a lexico.l

#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

// asignación de colores
vector<tuple<string, string>> colorRegExp(vector<string> outRegExps)
{
	vector<tuple<string, string>> colorRegExp;
	vector<string> colors{"burlywood", "crimson", "blue", "fuchsia",
						  "green", "red", "blueviolet", "lime", "deepskyblue",
						  "indigo", "maroon", "tomato", "pink", "mediumvioletred", "dodgerblue"};

	for (int i = 0; i < outRegExps.size(); i++)
	{
		tuple<string, string> aux;
		aux = make_tuple(outRegExps[i], colors[i]);
		colorRegExp.push_back(aux);
	}

	return colorRegExp;
}

// lextura del archivo de expresiones regulares
vector<string> readRegExps(string regexFile)
{
	ifstream myfile(regexFile);
	string line;

	vector<string> outRegExps;

	while (getline(myfile, line))
	{
		line = line.substr(0, line.size() - 1);
		outRegExps.push_back(line);
	}

	myfile.close();

	return outRegExps;
}

// escritura a lexico.l
void writeRegExps(vector<tuple<string, string>> colorRegExp, string inputFile)
{
	ofstream myfile;
	myfile.open("lexico_" + inputFile + ".l");

	string line;

	if (myfile.is_open())
	{
		myfile << "%{" << endl;
		myfile << "\t#include <stdio.h>" << endl;
		myfile << "\t#include <stdlib.h>" << endl;
		myfile << "\tFILE* myfile = fopen(\"final_" << inputFile << ".html\", \"a\");" << endl;
		myfile << "%}" << endl;
		myfile << "\%option c++" << endl;
		myfile << "\%option outfile=\"scanner_" << inputFile << ".cpp\"" << endl;
		myfile << "\%option noyywrap" << endl;
		myfile << "\%%" << endl;

		// fprintf(myfile, \"<span> \\\%emsp </span>\");"
		myfile << "\"\\t\"|\"    \"    fprintf(myfile, \"&emsp;\"); " << endl;
		myfile << "\"\\n\"	    fprintf(myfile, \"<br>\");" << endl;
		for (int i = 0; i < colorRegExp.size(); i++)
		{
			myfile << get<0>(colorRegExp[i]) << "\tfprintf(myfile, \"<span style = \\\"color: " << get<1>(colorRegExp[i]) << "\\\">\%s</span>\", yytext);" << endl;
		}

		myfile << "\%%" << endl;

		// funcion main de scanner.cpp. Se separó con el propósito de visualizarlo de forma más sencilla.

		// myfile << "#include \"FlexLexer.h\"" << endl;
		myfile << "#include <bits/stdc++.h>" << endl;
		myfile << "#include <fstream>" << endl;
		myfile << "using namespace std;" << endl;
		myfile << "int main(int argc, char *argv[]){" << endl;

		myfile << "ifstream toAnalyze(\""<< inputFile << ".txt\");" << endl;

// crea un objeto yyFlexLexer e indica su lectura con yylex().
		myfile << "yyFlexLexer *lexer = new yyFlexLexer(&toAnalyze);" << endl;
		myfile << "while (lexer->yylex() != 0)" << endl;
		myfile << "{" << endl;
		myfile << 	";" << endl;
		myfile << "}" << endl;

		myfile << "return 0;" << endl;
		myfile << "}" << endl;
		// myfile << "}" << endl;

	myfile.close();
	}
}

int main(int argc, char *argv[])
{
	writeRegExps(colorRegExp(readRegExps("regularexpressions.txt")), argv[1]);

	return 0;
}
