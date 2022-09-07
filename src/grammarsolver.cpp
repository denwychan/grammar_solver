// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include <iostream>

#include "grammarsolver.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "filelib.h"
using namespace std;

// Function prototypes
void readInputFile(istream& input, Vector<string> v, Map<string, Vector<string> >& map);

Vector<string> grammarGenerate(istream& input, string symbol, int times) {

    Vector<string> v;
    Map<string, Vector<string> > map;

    // readInputFile() read an input file with a grammar in Backus-Naur Form
    // and turns its contents into a data structure

    readInputFile(input, v, map);

    // generate elements randomly generate elements of the grammar (recursively)
    
    // Use trim to get rid of white space


    return v;           // this is only here so it will compile
}

void readInputFile(istream& input, Vector<string> v, Map<string, Vector<string> >& map){
    // Open text from reading the input stream
    string text = readEntireStream(input);
    cout << text << endl;
    cout << endl;
    v = stringSplit(text, "\n");
    cout << v << endl;
    // extract key and extract values for a map
    // if values have no white space, put into vector of strings
    // if values have space, put into nested vector (vector inside a vector
    // of strings

    // stringSplit
    // Vector<string> stringSplit(string s, string delimiter)

}
