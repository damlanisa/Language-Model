/* @Author
 * Student Name: Damla Nisa CEVIK
 * Student ID : 150170712
 * Date: 08.11.18 */

#ifndef vocab_node_h
#define vocab_node_h

#include "occur_node.h"
struct vocab_node {
    char character;
    vocab_node *next;
    occur_node *list;
};

#endif /* vocab_node_h */
