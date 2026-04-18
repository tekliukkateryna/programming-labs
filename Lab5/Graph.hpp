#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Block 0
class AdjacencyMatrix {
public:
    int V;
    int E=0;
    bool directed;
    vector<vector<int>> mat;

    AdjacencyMatrix(int v, vector<vector<int>> &edges, bool dr = false): V(v), directed(dr) {
        E = edges.size();
        mat.assign(V, vector<int>(V, 0));

        for (vector<int> edge:edges) {
            addEdge(edge[0], edge[1], edge[2]);
        }
    }
    AdjacencyMatrix(int v, bool dr = false): V(v), directed(dr) {
        mat.assign(V, vector<int>(V, 0));
    }

    void addEdge(int v1, int v2, int weight=1) {
        mat[v1][v2]=weight;
        E++;
        if (!directed) {
            mat[v2][v1]=weight;
        }
    }

    void print() {
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

class AdjacencyList {
public:
    int V;
    int E=0;
    bool directed;
    vector<vector<pair<int, int>>> list;

    AdjacencyList(int v, vector<vector<int>> &edges, bool dr = false): V(v), directed(dr){
        E = edges.size();
        list.resize(V);

        for (vector<int> edge:edges) {
            addEdge(edge[0], edge[1], edge[2]);
        }
    }

    AdjacencyList(int v, bool dr = false): V(v), directed(dr){
        list.resize(V);
    }

    void addEdge(int v1, int v2, int weight=1) {
        list[v1].push_back({v2, weight});
        E++;
        if (!directed) {
            list[v2].push_back({v1, weight});
            E++;
        }
    }

    void print() {
        int N = list.size();
        for (int i=0; i<N; i++) {
            int M = list[i].size();
            cout<<i<<": ";
            for (int j=0; j<M; j++) {
                cout<<"("<<list[i][j].first<<";"<<list[i][j].second<<") ";
            }
            cout<<endl;
        }
    }

};

AdjacencyMatrix genRandMatrix(int V, int E, bool dir, int range) {
    AdjacencyMatrix mat (V, dir);
    for (int i = 0; i<E; i++) {
        int v1 = rand() % V;
        int v2 = rand() % V;
        if (v1==v2) {
            i--;
            continue;
        }
        int weight = (rand() % (range-1))+1;
        mat.addEdge(v1, v2, weight);
    }
    return mat;
}

AdjacencyList genRandList(int V, int E, bool dir, int range) {
    AdjacencyList list (V, dir);
    for (int i = 0; i<E; i++) {
        int v1 = rand() % V;
        int v2 = rand() % V;
        if (v1==v2) {
            i--;
            continue;
        }
        int weight = (rand() % (range-1))+1;
        list.addEdge(v1, v2, weight);
    }
    return list;
}

AdjacencyList toList(AdjacencyMatrix &mat) {
    AdjacencyList list (mat.V, mat.directed);

    for (int i = 0; i<mat.V; i++) {
        int start = mat.directed ? 0 : i;
        for (int j = start; j<mat.V; j++) {
            if (mat.mat[i][j]!=0) {
                list.addEdge(i, j, mat.mat[i][j]);
            }
        }
    }

    return list;
}

AdjacencyMatrix toMatrix(AdjacencyList &list) {
    AdjacencyMatrix mat (list.V, list.directed);

    int N = list.list.size();
    for (int i=0; i<N; i++) {
        int M = list.list[i].size();
        for (int j=0; j<M; j++) {
            mat.addEdge(i, list.list[i][j].first, list.list[i][j].second);
        }
    }

    return mat;
}