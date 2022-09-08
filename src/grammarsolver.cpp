/*
 * This is an implementation of a random grammar elements generater according to formalised rules
 * described in Backus-Naur Form (BNF). The program prompts the user to open a text file
 * by its file name, and convert the content to a map if it is in valid BNF. This is used
 * to randomly generate elements (words or phrases) according to the key of the BNF and frequency
 * inputted by the user
 */

// Imports
#include <iostream>

#include "grammarsolver.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "filelib.h"
#include "error.h"
#include "random.h"
using namespace std;

// Function prototypes
void readInputFile(istream& input, Map<string, Vector<Vector<string> > >& map);
void splitByDelimiter(string text, Vector<string>& v, string delimiter);
string generateRandomElements(
        Map<string, Vector<Vector<string> > >& map, string symbol);

Vector<string> grammarGenerate(istream& input, string symbol, int times) {
    // Initialising a vector for the final output
    Vector<string> v;
    // Initialising the map for the symbol and rules
    Map<string, Vector<Vector<string> > > map;

    // Read an input file with grammar in Backus-Naur Form and turns the contents into a map
    readInputFile(input, map);

    // Generate elements of the grammar randomly according to the number of time specified by the
    // user
    for (int i = 0; i < times; i ++){
        string results = generateRandomElements(map, symbol);
        v.add(results);
    }
    // Return the results as a vector
    return v;
}

// Read input file and turn its contents into a map
void readInputFile(istream& input, Map<string, Vector<Vector<string> > >& map){
    // Open text from reading the input stream and split text into a vector of lines
    string text = readEntireStream(input);
    Vector<string> v = stringSplit(text, "\n");

    // Put each line into a map data structure
    for (int i = 0; i < v.size(); i++){
        // Instantiate a vector of vector of strings to go into the map as the value
        Vector<Vector<string> > value;
        // Split into key and value by "::=" e.g. {"VERB", "TVERB NOUNP|IVERB"}
        Vector<string> tempV = stringSplit(v[i], "::=");
        string key = tempV[0]; // This is the key e.g. tempV[0] >>> "VERB"
        // If the key is duplicated in the content, then throw an error
        if (map.containsKey(key)){
            error("Grammar cannot contain multiple lines of rules for the same non-terminal");
        }
        string valueString = tempV[1]; // This is the value e.g. tempV[1] >>> "TVERB NOUNP|IVERB"
        // Split up rules as separated by "|" e.g. "TVERB NOUNP|IVERB" >>> {"TVERB NOUNP", IVERB"}
        Vector<string> tempVPipe = stringSplit(valueString, "|");
        for (int j = 0; j < tempVPipe.size(); j++) {
            // Split by space e.g. "TVERB NOUNP" >>> {"TVERB", "NOUNP"}
            Vector<string> tempVSpace = stringSplit(tempVPipe[j], " ");
            value.add(tempVSpace);
        }
        // Add final key and vector and vectors to map
        map.put(key, value);
    }
}

string generateRandomElements(Map<string, Vector<Vector<string> > >& map, string symbol){
    string results = "";
    if (!map.containsKey(symbol)){ // Base case: if the symbol is a terminal, return the symbol
        // as it is
        return trim(symbol);
    } else if (symbol == ""){ // Base case: if the symbol is empty "", throw string exception
        error("Symbol cannot be empty!");
        return symbol;
    } else { // Recursive case: look up the symobol for the grammar rules to generate the results
        Vector<Vector<string> > rules = map.get(symbol);
        Vector<string> subRules = rules[randomInteger(0, rules.size() - 1)];
        // Generate random elements for each sub-rule
        for (int i = 0; i < subRules.size() ; i++){
            results = results + " " + generateRandomElements(map, subRules[i]);
        }
        // Clean up the results
        return trim(results);
    }
}
