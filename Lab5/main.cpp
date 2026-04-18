#include <iostream>

#include "Algorithms.hpp"
#include "Graph.hpp"
using namespace std;

void demonstration_mode() {
    cout<<"BLOCK 0"<<endl;
    int v = 5;  // кількість вершин
    int e = 7;  // кількість ребер
    bool isDirected = false;

    cout << "Generate AdjacencyMatrix" << endl;
    AdjacencyMatrix myMatrix = genRandMatrix(v, e, isDirected, 10);
    myMatrix.print();

    cout << "Convert to AdjacencyList" << endl;
    AdjacencyList myList = toList(myMatrix);
    myList.print();

    cout << "Convert back to AdjacencyMatrix" << endl;
    AdjacencyMatrix convertedBack = toMatrix(myList);
    convertedBack.print();

    cout<<"BLOCK 1"<<endl;
    int n = 5;
    AdjacencyList connList(n, false);
    connList.addEdge(0, 1);
    connList.addEdge(1, 2);
    connList.addEdge(2, 0);
    connList.addEdge(3, 4);

    cout << "Adjacency List: " << endl;
    connList.print();

    int componentsL = CountComponentsList(connList);
    cout << "Count components by list: " << componentsL << endl;

    AdjacencyMatrix connMatrix = toMatrix(connList);
    int componentsM = CountComponentsList(connMatrix);
    cout << "Count components by matrix: " << componentsM << endl;

    cout<<"BLOCK 2 (DFS and additional BFS)"<<endl;

    int n2 = 4;
    AdjacencyList demoList(n2, true);
    demoList.addEdge(0, 1, 10);
    demoList.addEdge(0, 2, 2);
    demoList.addEdge(1, 3, 1);
    demoList.addEdge(2, 3, 5);
    demoList.print();

    vector<bool> v1(n2, false);
    cout << "DFS (List) by number: ";
    DFSlistIterByNum(0, demoList, v1);

    vector<bool> v2(n2, false);
    cout << "DFS (List) by weight: ";
    DFSlistIterByWt(0, demoList, v2);

    vector<bool> v3(n2, false);
    cout << "BFS (List) by number: ";
    BFSlistIterByNum(0, demoList, v3);

    vector<bool> v4(n2, false);
    cout << "BFS (List) by weight: ";
    BFSlistIterByNum(0, demoList, v4);

    AdjacencyMatrix demoMatrix = toMatrix(demoList);

    vector<bool> v5(n2, false);
    cout << "DFS (Matrix) by number: ";
    DFSmatrixIterByNum(0, demoMatrix, v5);

    vector<bool> v6(n2, false);
    cout << "DFS (Matrix) by weight: ";
    DFSmatrixIterByWt(0, demoMatrix, v6);

    vector<bool> v7(n2, false);
    cout << "BFS (Matrix) by number: ";
    BFSmatrixIterByNum(0, demoMatrix, v7);

    vector<bool> v8(n2, false);
    cout << "BFS (Matrix) by weight: ";
    BFSmatrixIterByNum(0, demoMatrix, v8);

    cout << "BLOCK 3 (Dijkstra)" << endl;

    int n3 = 4;
    AdjacencyList dList(n, true); // орієнтований
    dList.addEdge(0, 1, 10);
    dList.addEdge(0, 2, 3);
    dList.addEdge(2, 1, 2);
    dList.addEdge(1, 3, 1);
    dList.addEdge(2, 3, 8);
    dList.print();

    vector<int> dist, parent;
    vector<int> path = DijkstraListBetween(0, 3, dList, dist, parent);

    cout << "(List) Path 0 -> 3:" << endl;
    for (int v : path) cout << v << (v == 3 ? "" : " -> ");
    cout<<endl;
    cout << "(List) Minimum distance: " << dist[3] << endl;

    cout << "(List) Dijkstra all to all:" << endl;
    vector<vector<int>> allDist, allParent;
    DijkstraListAll(dList, allDist, allParent);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (allDist[i][j] == INT_MAX) cout << "- ";
            else cout << allDist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "(Matrix) Dijkstra all to all:" << endl;
    AdjacencyMatrix dMatrix = toMatrix(dList);
    vector<vector<int>> mDist, mParent;
    DijkstraMatrixAll(dMatrix, mDist, mParent);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (allDist[i][j] == INT_MAX) cout << "- ";
            else cout << allDist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "BLOCK 4 (Topological sorting)" << endl;

    int n4 = 4;
    AdjacencyList tList(n4, true); // Обов'язково oriented = true
    tList.addEdge(0, 1);
    tList.addEdge(0, 2);
    tList.addEdge(1, 3);
    tList.addEdge(2, 3);
    tList.print();

    cout << "(List) Test on directed acyclic graph:" << endl;
    vector<int> resList = KahnList(tList);
    for (int v : resList) cout << v << " ";
    cout << endl;

    AdjacencyList cycleList(3, true);
    cycleList.addEdge(0, 1);
    cycleList.addEdge(1, 2);
    cycleList.addEdge(2, 0);

    cout << "(List) Test on the graph that has cycle:" << endl;
    vector<int> resCycle = KahnList(cycleList);
    //has to print error

    AdjacencyMatrix dagMatrix = toMatrix(tList);
    cout << "(Matrix) Test on directed acyclic graph:" << endl;
    vector<int> resMatrix = KahnMatrix(dagMatrix);
    for (int v : resMatrix) cout << v << " ";
    cout << endl;

    cout << "BLOCK 5 (Spanning tree)" << endl;

    int n5 = 4;
    AdjacencyList stList(n5, false);
    stList.addEdge(0, 1, 10);
    stList.addEdge(1, 2, 5);
    stList.addEdge(2, 3, 2);
    stList.addEdge(3, 0, 8);
    stList.addEdge(0, 2, 1);
    stList.print();

    vector<pair<int, int>> treeL;
    vector<bool> visitedL(n, false);
    int total_weightL = 0;

    cout << "(List) Spanning tree from 0:" << endl;
    SpanningTreeList(stList, treeL, visitedL, 0, total_weightL);

    for (pair<int, int> edge : treeL) {
        cout << edge.first << " - " << edge.second << "; ";
    }
    cout<<endl;
    cout << "(List) Total weight: " << total_weightL << endl;

    AdjacencyMatrix stMatrix = toMatrix(stList);
    vector<pair<int, int>> treeM;
    vector<bool> visitedM(n, false);
    int total_weightM = 0;

    cout << "(Matrix) Spanning tree from 0: " << endl;
    SpanningTreeMatrix(stMatrix, treeM, visitedM, 0, total_weightM);

    for (pair<int, int> edge : treeM) {
        cout << edge.first << " - " << edge.second << "; ";
    }
    cout<<endl;
    cout << "(Matrix) Total weight: " << total_weightM << endl;

    cout<<"BLOCK 6"<<endl;
    int n6 = 5;
    AdjacencyList gList(n, false);
    gList.addEdge(0, 1, 2);
    gList.addEdge(0, 3, 6);
    gList.addEdge(1, 2, 3);
    gList.addEdge(1, 3, 8);
    gList.addEdge(1, 4, 5);
    gList.addEdge(2, 4, 7);
    gList.addEdge(3, 4, 9);

    cout << "(List) Find minimum spanning tree: " << endl;
    vector<int> distL, parentL;
    int weightL = PrimList(0, gList, distL, parentL);
    for (int i = 0; i < n; i++) {
        if (parentL[i] != -1) cout << parentL[i] << "-" << i << "; ";
    }
    cout << endl;
    cout << "(List) Total weight: " << weightL << endl;

    cout << "(Matrix) Find minimum spanning tree: " << endl;
    AdjacencyMatrix gMat = toMatrix(gList);
    vector<int> distM, parentM;
    int weightM = PrimMatrix(0, gMat, distM, parentM);
    for (int i = 0; i < n; i++) {
        if (parentM[i] != -1) cout << parentM[i] << "-" << i << "; ";
    }
    cout << endl;
    cout << "(Matrix) Total weight: " << weightM << endl;

    cout<<endl;
    cout<<"The end :)"<<endl;
}

int main() {
    demonstration_mode();
}