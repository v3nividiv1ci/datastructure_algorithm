//
// Created by 王烨 on 2021/4/13.
//
#include "trees.h"
#ifndef DATASTRUCTURE_LEARNING_TREES_H
#define DATASTRUCTURE_LEARNING_TREES_H
//递归
void preorder_tree_walk(Tree_node *head);

void inorder_tree_walk(Tree_node *head);

void postorder_tree_walk(Tree_node *head);

//栈
static void visit_left_branch(Tree_node *x, std::stack<Tree_node *> &s);
void preorder_tree_walk_stack(Tree_node *root);

static void go_left_branch_end(Tree_node *x, std::stack<Tree_node *> &s);
void inorder_tree_walk_stack(Tree_node *root);

void go_deepest_highest_left(std::stack<Tree_node* > &s);
void postorder_tree_walk_stack(Tree_node *root);

//队列
void level_tree_walk(Tree_node* root);
#endif //DATASTRUCTURE_LEARNING_TREES_H
