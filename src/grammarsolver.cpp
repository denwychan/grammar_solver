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

    // Put the text into a map data structure
    // Examples
    // NOUN::=dog|cat|girl|store|second cousin|great grandpa|child|television|homework|Java program
    // VERBP::=TVERB NOUNP|IVERB
    // tempV
    // {"NOUN", "dog|cat|girl|store|second cousin|great grandpa|child|television|homework|Java program}
    // {"VERB", "TVERB NOUNP|IVERB"}
    // tempV[0] >>> "VERB"
    // tempV[1] >>> "TVERB NOUNP|IVERB"
    // tempVPipe >>> {"TVERB NOUNP", "IVERB}
    // tempV3Space >> {"TVERB", "NOUNP"}
    // value >>> {{"TVERB", "NOUNP"}, "IVERB}

    Vector<string> tempV;
    Vector<Vector<string> > valueVec;
    for (int i = 0; i < v.size(); i++)
        tempV = stringSplit(v[i], ":=");
        string key = tempV[0];
        string value = tempV[1];
        // Check for multiple rules separated by "|"
        if (stringContains(value, "|")){
            valueVec.add(stringSplit(value, "|"));
            // Check for multiple tokens separated by " "
            for (int j = 0; j < valueVec.size(); j++) {
                if (stringContains(valueVec[i][j], " ")) {
                    valueVec.set(j, stringSplit(value, " "));
                }
            }
        }
        valueVec.add(value);
        map.put(key, valueVec);
        valueVec.clear();
        }
    // extract key and extract values for a map
    // if values have no white space, put into vector of strings
    // if values have space, put into nested vector (vector inside a vector
    // of strings

    // stringSplit
    // Vector<string> stringSplit(string s, string delimiter)

}
