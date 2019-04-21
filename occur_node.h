/* @Author
 * Student Name: Damla Nisa CEVIK
 * Student ID : 150170712
 * Date: 08.11.18 */

#ifndef occur_node_h
#define occur_node_h

struct occur_node {
    char character;
    occur_node *next;
    int occurence;
};

#endif /* occur_node_h */
