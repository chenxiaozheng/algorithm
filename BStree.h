#ifndef _BSTREE_H
#define _BSTREE_H

struct tree_node
{
    int num;       /*存储的节点值*/
    struct tree_node *left;
    struct tree_node *right;
};


#define TREE_INIT(dest, num) {num,NULL, NULL}             /*通过两个define来对树的节点进行初始话*/
#define TREE_INIT_HEAD(dest, num) struct tree_node dest =  TREE_INIT(dest, num)

struct tree_node *create_tree_node(int num);
void insert_tree_node(struct tree_node * dest);
void print_tree_num(struct tree_node *dest);


#endif       /*end of _BSTREE_H*/
