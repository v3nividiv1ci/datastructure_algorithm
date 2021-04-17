//
// Created by 王烨 on 2021/4/16.
//
#include "graphs.h"
#define INF 1000000000
#include <queue>
//创建邻接表
//邻接表链表的表中结点

typedef struct list_body{
    int v_index; //记录u的邻接结点v的下标
    list_body *next_body;
}list_body;

//邻接表的表头结点
typedef struct list_head{
    int u_index; //他自己的下标
    int father; //前驱
//    0是白色，1是灰色，2是黑色
    int color; //判断是黑（访问了且邻接结点都被发现了），灰（访问到了但是没有去寻找他的所有邻接结点）还是白（没访问过）
    int d; //距离
    char data; //这个结点叫什么
    list_body *first_body;
}list_head;

//邻接表
typedef struct adj_graph{
    list_head vertices[100];
    int v, e; //结点和边的数量
}adj_graph;

//BFS
void BFS(adj_graph adj){
    for (int i = 1; i < adj.v; i++){
        adj.vertices[i].d = INF;
        adj.vertices[i].color = 0;
        adj.vertices[i].father = -1;
    }
//    用下标0来放源结点
    list_head s = adj.vertices[0];
    s.father = -1;
    s.color = 1;
    s.d = 0;
    std::queue <list_head> g;
    g.push(s);
    while (!g.empty()){
        list_head u = g.front();
        g.pop();
        while (u . first_body != NULL){
            int v_idx = u.first_body->v_index;
            list_head v = adj.vertices[v_idx];
            if (v.color == 0){
                v.color = 1;
                v.d = u.d + 1;
                v.father = u.u_index;
                g.push(v);
            }
        }
        u.color = 2;
    }
}

//DFS
void DFS(){

}


//拓扑排序

void Topological_sorting(){

}