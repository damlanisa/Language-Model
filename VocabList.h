/* @Author
 * Student Name: Damla Nisa CEVIK
 * Student ID : 150170712
 * Date: 08.11.18 */

#ifndef VocabList_h
#define VocabList_h
using namespace std;

struct vocab_list {
    vocab_node *head;
    void create();
    void print();
    void add_char(char);
    void add_occurence(char , char);
    int get_occurence(char);
    int get_union_occurence (char , char);
};

void vocab_list::create(){
    head= NULL;
}

void vocab_list::add_char(char ch){
    vocab_node *traverse, *tail;
    tail = NULL;
    traverse = head;
    if(ch == '\r'){
        return;
    }
    vocab_node *newnode;
    newnode = new vocab_node;
    newnode->character = ch;
    newnode->next = NULL;
    newnode->list = NULL;
    if(newnode->character >= 'a' && newnode->character <= 'z'){ //for alphabetical characters
        if(head == NULL){                                       //add the first node
            head = newnode;
            return;
        }
        if(head->character < 'a' || head->character > 'z'){     //if the first character is special character
            newnode->next = head;
            head = newnode;
            return;
        }
        if(newnode->character < head->character){                //add to the beginning
            if(newnode->character == head->character){           //if the character already exists
                delete newnode;                                  //to avoid memory fleak
                return;
            }
            newnode->next = head;
            head = newnode;
            return;
        }
        while(traverse && (newnode->character > traverse->character) &&
              (traverse->character >= 'a' && traverse->character <= 'z')){ //for alphabetical characters
            tail = traverse;
            traverse = traverse->next;
        }
        if(traverse){                                       //add to the position which is not the beginning or the end
            if(newnode->character == traverse->character){  //if the character already exists
                delete newnode;                             //to avoid memory fleak
                return;
            }
            newnode->next = traverse;
            tail->next = newnode;
        }
        else{                                               //add to the end
            tail->next = newnode;
        }
    }
    else{                                                   //for special characters
        while(traverse->next != NULL){
            tail = traverse;
            traverse = traverse->next;
            if(newnode->character == traverse->character){
                delete newnode;
                return;
            }
        }
        traverse->next = newnode;
    }
}

void vocab_list::add_occurence(char primary_char, char secondary_char){
    vocab_node *traverse_vocab_node;
    traverse_vocab_node = head;
    occur_node *traverse_occur_node;
    traverse_occur_node = NULL;                             //to avoid unintialized warning
    occur_node *tail_occur_node;
    tail_occur_node = NULL;
    occur_node *new_occurance;
    new_occurance = new occur_node;
    new_occurance->character = secondary_char;
    new_occurance->next = NULL;
    new_occurance->occurence = 1;
    while(traverse_vocab_node){
        if(traverse_vocab_node->character == primary_char){
            if(traverse_vocab_node->list == NULL){  //first occur node
                traverse_vocab_node->list = new_occurance;
                return;
            }
            else{
                traverse_occur_node = traverse_vocab_node->list;
                break;
            }
        }
        else{
            traverse_vocab_node = traverse_vocab_node->next;
        }
    }
    while(traverse_occur_node){
        if(traverse_occur_node->character == secondary_char){
            traverse_occur_node->occurence++;
            return;
        }
        else{
            tail_occur_node = traverse_occur_node;
            traverse_occur_node = traverse_occur_node->next;
        }
    }
    if(tail_occur_node){
        tail_occur_node->next = new_occurance;
    }
}

int vocab_list::get_occurence(char ch){
    int counter= 0;
    vocab_node *traverse_vocab_list;
    traverse_vocab_list = head;
    occur_node *traverse_occur_list;
    traverse_occur_list = NULL;
    while(traverse_vocab_list){
        if(traverse_vocab_list->character == ch){
            traverse_occur_list = traverse_vocab_list->list;
            break;
        }
        else{
            traverse_vocab_list = traverse_vocab_list->next;
        }
    }
    while(traverse_occur_list){
        counter+=traverse_occur_list->occurence;
        traverse_occur_list = traverse_occur_list->next;
    }
    return counter;
}

int vocab_list::get_union_occurence(char primary_char, char secondary_char){
    int counter= 0;
    vocab_node *traverse_vocab_list;
    traverse_vocab_list = head;
    occur_node *traverse_occur_list;
    traverse_occur_list = NULL;
    while(traverse_vocab_list){
        if(traverse_vocab_list->character == primary_char){
            traverse_occur_list = traverse_vocab_list->list;
            break;
        }
        else{
            traverse_vocab_list = traverse_vocab_list->next;
        }
    }
    while(traverse_occur_list){
        if(traverse_occur_list->character == secondary_char){
            counter = traverse_occur_list->occurence;
            break;
        }
        else{
            traverse_occur_list = traverse_occur_list->next;
        }
    }
    return counter;
}

void vocab_list::print(){
    vocab_node *traverse_vocab_list;
    traverse_vocab_list = head;
    occur_node *traverse_occurence;
    traverse_occurence = traverse_vocab_list->list;
    while(traverse_vocab_list){
        traverse_occurence = traverse_vocab_list->list;
        if(traverse_vocab_list->character == ' '){
            cout << "<SP>" << ":" <<endl;
        }
        else{
            cout << traverse_vocab_list->character << ":" <<endl;
        }
        while(traverse_occurence){
            if(traverse_occurence->character == ' '){
                cout << "\t<<SP>," << traverse_occurence->occurence << ">" << endl;
            }
            else cout << "\t<" << traverse_occurence->character << "," << traverse_occurence->occurence << ">" << endl;
            
            traverse_occurence = traverse_occurence->next;
        }
        traverse_vocab_list = traverse_vocab_list->next;
    }
}

#endif /* VocabList_h */
