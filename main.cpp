/* @Author
 * Student Name: Damla Nisa CEVIK
 * Student ID : 150170712
 * Date: 08.11.18 */

#include <iostream>
#include <fstream>
#include <cctype> //tolower function
#include <string>
#include "vocab_node.h"
#include "occur_node.h"
#include "LanguageModel.h"
#include "VocabList.h"
using namespace std;

int main(int argc, const char* argv[]) {
    struct language_model languageModel;
    languageModel.readData(argv[1]);
    if(argc == 2){      // to print the whole vocablist
        languageModel.vocabularylist->print();
    }
    else{
        if(argv[2] == "<SP>"){
            if(languageModel.calculateProbability(' ' , argv[3][0]) == 0){
                cout << "0/0 undefined" << endl;
            }
            else{
                cout << languageModel.calculateProbability(' ' , argv[3][0]) << endl;
            }
        }
        else if(argv[3] == "<SP>"){
            if(languageModel.calculateProbability(argv[2][0], ' ') == 0){
                cout << "0/0 undefined" << endl;
            }
            else{
                cout << languageModel.calculateProbability(argv[2][0], ' ') << endl;
            }
        }
        else{
            if(languageModel.calculateProbability(argv[2][0], argv[3][0]) == 0){
                cout << "0/0 undefined" << endl;
            }
            else{
                cout << languageModel.calculateProbability(argv[2][0], argv[3][0]) << endl;
            }
        }
    }
    languageModel.delete_model();       
    return 0;
}

