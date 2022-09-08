// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include <iostream>

#include "grammarsolver.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "filelib.h"
using namespace std;

// Function prototypes
void readInputFile(istream& input, Vector<string>& v, Map<string, Vector<Vector<string> > >& map);
void splitByDelimiter(string text, Vector<string>& v, string delimiter);

Vector<string> grammarGenerate(istream& input, string symbol, int times) {

    Vector<string> v;
    Map<string, Vector<Vector<string> > > map;

    // readInputFile() read an input file with a grammar in Backus-Naur Form
    // and turns its contents into a data structure

    readInputFile(input, v, map);

    // generate elements randomly generate elements of the grammar (recursively)
    
    // Use trim to get rid of white space


    return v;           // this is only here so it will compile
}

void readInputFile(istream& input, Vector<string>& v, Map<string, Vector<Vector<string> > >& map){
    // Open text from reading the input stream
    string text = readEntireStream(input);

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
    // tempVSpace >> {"TVERB", "NOUNP"}
    // value >>> {{"TVERB", "NOUNP"}, "IVERB}


    for (int i = 0; i < v.size(); i++){
        Vector<Vector<string> > value;

        Vector<string> tempV = stringSplit(v[i], "::=");
        string key = tempV[0]; // e.g. tempV[0] >>> "VERB"
        string valueString = tempV[1]; // e.g. tempV[1] >>> "TVERB NOUNP|IVERB"

        // Check for multiple rules separated by "|"
        // If there are spaces <dp> <adjp> <n> >>> {<dp>, <adjp>, <n>}
        // If there are no spaces <pn> <<< {<pn>}

        Vector<string> tempVPipe = stringSplit(valueString, "|");
        for (int j = 0; j < tempVPipe.size(); j++) {
            Vector<string> tempVSpace = stringSplit(tempVPipe[j], " ");
            value.add(tempVSpace);
        }
        map.put(key, value);
    }

//    cout << map.keys() << endl;
//    for (int i = 0; i < map.keys().size(); i++ ){
//        string mapKey = map.keys()[i];
//        cout << mapKey << endl;
//        cout << map.get(mapKey) << endl;
//        cout << endl;
    }
}
