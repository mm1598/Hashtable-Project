// main.cpp : Defines the entry point for the console application.
/*This code create a hash table that uses Linear Probing Open Addressing using unordered map key and the provided hash
function.*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

//define namePair using C++  pair template class (2 strings - first & last name)
typedef pair<string, string> namePair;

//define stl::hash function for namePair keys
namespace std {

template <> class hash<namePair> {
public:
    size_t operator()(const namePair& namePair) const {
        return hash<string>()(namePair.first) ^ hash<string>()(namePair.second);
    }//size_t operator()
};//class hash

}//namespace std


void displayHashTableLookupResult(pair<string, string> namePair, unordered_map<pair<string, string>, unsigned int>& hashTable) {

    stringstream resultStream;

    if (hashTable.find(namePair) != hashTable.end()) {
        resultStream << "ID: " << hashTable[namePair];
    } else {
        resultStream << "Entry not found in hash table";
    }

    cout << "Lookup result for " << namePair.first << ", " << namePair.second << ": " << resultStream.str() << endl;
}


int main(int argc, char* argv[]) {

    //define hashTable as namepair keys and integer value identifications (open address linear probe)
    unordered_map<namePair, unsigned int> hashTable;

    // Put in the hash table the namePair keys and associated number ids from text
    string nameData =
        "Gal       Varsano    77789\n"
        "Marion    Morrison   40561\n"
        "Stephanie Clifford   40562\n"
        "Armando   Pere       10101\n"
        "Peter     Hernandez  77777\n"
        "Monica    Lewinsky   69696\n"
        "Park      Jae-sang   88888\n"
        "Stefani   Germanotta 11111\n"
        "Melania   Knavs      99999\n"
        "Marshal   Mathers    33333\n"
        "Robyn     Fenty      77777\n"
        "Hillary   Rodham     44444\n"
        "Barry     Soetoro    66666\n"
        "Michelle  Robinson   12121\n"
        "Aubrey    Graham     23232\n"
        "Richard   Starkey    89898\n"
        "Curtis    Jackson    21212\n"
        "Ryan	  Hamaz	     24532\n"
        "Ansh	  Anand	     12121\n"
        "Abraham  Chris	     34577\n"
        "John	  Chris      11247"
;

    stringstream inputDataStream(nameData);
    string firstName, lastname;
    unsigned int id;

    while (inputDataStream >> firstName >> lastname >> id) {
        hashTable[make_pair(firstName, lastname)] = id;
    }

    // Range based for loop to display elements in the hash table map, namePair keys along with ids
    for (const auto& entry : hashTable) {
        cout << entry.first.first << ", " << entry.first.second << ": " << entry.second << endl;
    }

    cout << endl << endl;

    // Look up 6 ids in hash table, 2 of each are not in the table

    displayHashTableLookupResult(make_pair("John", "Doe"), hashTable);
    displayHashTableLookupResult(make_pair("Jane", "Doe"), hashTable);
    displayHashTableLookupResult(make_pair("Peter", "Jones"), hashTable);
    displayHashTableLookupResult(make_pair("Mary", "Smith"), hashTable);
    displayHashTableLookupResult(make_pair("David", "Williams"), hashTable);
    displayHashTableLookupResult(make_pair("Elizabeth", "Brown"), hashTable);

    // Freeze screen with Press enter key once or twice to end code

    cout << "Press enter key once or twice to end code...";
    getchar();
    getchar();

    return 0;
}
