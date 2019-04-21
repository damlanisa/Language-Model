/* @Author
 * Student Name: Damla Nisa CEVIK
 * Student ID : 150170712
 * Date: 08.11.18 */

#ifndef LanguageModel_h
#define LanguageModel_h
#include "VocabList.h"
using namespace std;

struct language_model {
    vocab_list *vocabularylist;
    void readData (const char *);
    double calculateProbability (char, char);
    void delete_model();
};

void language_model::readData(const char * file_name){
    ifstream input_file;
    input_file.open(file_name);
    vocabularylist = new vocab_list;
    vocabularylist->create();
    string line;
    int i, j;
    while(getline(input_file, line)){
        for(i=0; i<line.length(); i++){
            vocabularylist->add_char(tolower(line[i]));
        }
        for(j=0; j<(line.length()-1); j++){ //creating occurence lists
            vocabularylist->add_occurence(tolower(line[j]),tolower(line[j+1]));
        }
    }
    input_file.close();
}

double language_model::calculateProbability(char primary_char, char secondary_char){
    int total_occurance = vocabularylist->get_occurence(primary_char);
    int union_occurance = vocabularylist->get_union_occurence(primary_char, secondary_char);
    double probability = (double)union_occurance / (double)total_occurance;
    return probability;
}

void language_model::delete_model(){
    vocab_node *traverse_vocab;
    occur_node *traverse_occur;
    while(vocabularylist->head){
        traverse_vocab = vocabularylist->head;
        vocabularylist->head = (vocabularylist->head)->next;
        while(traverse_vocab->list){
            traverse_occur = traverse_vocab->list;
            traverse_vocab->list = (traverse_vocab->list)->next;
            delete traverse_occur;
        }
        delete traverse_vocab;
    }
}

#endif /* LanguageModel_h */
