#define NULL
#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

typedef  struct node Tree_node;

//深度遍历：先进后出：栈和递归
//广度遍历：先进先出：队列

//递归：先序遍历
void preorder_tree_walk(Tree_node *head){
    if(head != NULL){
        printf("%d", head -> data);
        preorder_tree_walk(head -> left);
        preorder_tree_walk(head -> right);
    }
}

//递归：中序遍历
void inorder_tree_walk(Tree_node *head){
    if(head != NULL){
        preorder_tree_walk(head -> left);
        printf("%d", head -> data);
        preorder_tree_walk(head -> right);
    }
}

//递归：后序遍历
void postorder_tree_walk(Tree_node *head){
    if(head != NULL){
        preorder_tree_walk(head -> left);
        preorder_tree_walk(head -> right);
        printf("%d", head -> data);
    }
}
//递归本质是压栈的过程，故可用堆栈来模拟

//非递归：先序遍历
//这是一个访问左子树的函数
static void visit_left_branch(Tree_node *x, std::stack<Tree_node *> &s){
    while(x){
        printf("%d ", x -> data);
        if (x -> right)
            s.push(x -> right); //右分支入栈暂存
        x = x -> left; //继续沿左分支往深走
    }
}

void preorder_tree_walk_stack(Tree_node *root){
    std::stack<Tree_node  *> s;
    while (true){
        visit_left_branch(root, s);
        if(s.empty()) //直到栈空
            break;
        root = s.top(); // .top()没有返回值
        s.pop(); //弹出下一批的起点，用.top()取到
    }
}

//非递归：中序遍历
static void go_left_branch_end(Tree_node *x, std::stack<Tree_node *> &s){
    while (x){
        s.push(x);
        x = x -> left;
    }

}

void inorder_tree_walk_stack(Tree_node *root){
    std::stack<Tree_node *> s; //建一个辅助栈
    while(true) {
        go_left_branch_end(root, s);
        if (s.empty())
            break;
        root = s.top();
        printf("%d", root -> data);
        s.pop();
        root = root -> right;
    }
}

//非递归：后序遍历
//递归深入，找到最高左侧叶结点
void go_deepest_highest_left(std::stack<Tree_node* > &s){
    while(Tree_node* x = s.top())
        if (x -> left) {
            if (x -> right)
                s.push(x -> right);
            s.push(x -> left);
        }
        else
            s.push(x->right);
    s.pop(); //弹出最后入栈的空节点（已经找到了，目标结点的左右子都是null）
}

void postorder_tree_walk_stack(Tree_node *root){
    std::stack<Tree_node* > s;
    if (root)
        s.push(root);
    while (!s.empty()){
//        根据上个函数的入栈顺序，对于刚刚pop出去的结点，比他先一个入栈的（即现在的栈顶）不是他的父节点就是他的右兄
        if (s.top() != root -> parent)
            go_deepest_highest_left(s);
        root = s.top();
        s.pop();
        printf("%d", root -> data);
    }
}

//层次遍历：使用队列
void level_tree_walk(Tree_node* root){
    std::queue<Tree_node* > q;
    q.push(root); //入队
    if (! q.empty()){
        root = q.front();
        q.pop();
        if (root -> left)
            q.push(root -> left);
        if (root -> right)
            q.push(root -> right);
    }
}