#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include "Graph.hpp"
using namespace std;

//Block 1
void DFSlist (int v, AdjacencyList &inp, vector<bool> &visited) {
    if (visited[v]) {
        return;
    }
    visited[v]=true;
    for (int i = 0; i<inp.list[v].size(); i++) {
        DFSlist(inp.list[v][i].first, inp, visited);
    }
}

int CountComponentsList (AdjacencyList &inp) {
    int count = 0;
    vector<bool> visited(inp.V, false);
    for (int i=0; i<inp.V; i++) {
        if (!visited[i]) {
            count++;
            DFSlist(i, inp, visited);
        }
    }
    return count;
}

void DFSmatrix (int v, int n, AdjacencyMatrix &inp, vector<bool> &visited) {
    if (visited[v]) {
        return;
    }
    visited[v]=true;
    for (int i = 0; i<n; i++) {
        if (inp.mat[v][i]!=0) {
            DFSmatrix(i, n, inp, visited);
        }
    }
}

int CountComponentsList (AdjacencyMatrix &inp) {
    int count = 0;
    vector<bool> visited(inp.V, false);
    for (int i=0; i<inp.V; i++) {
        if (!visited[i]) {
            count++;
            DFSmatrix(i, inp.V, inp, visited);
        }
    }
    return count;
}

//Block 2
//I`ve done iterative version additional, because I thought that it was interesting
void DFSlistIterByNum (int StartNd, AdjacencyList &inp, vector<bool> &visited) {
    stack<int> res;
    res.push(StartNd);
    while (!res.empty()) {
        int v = res.top();
        res.pop();

        if (visited[v]) {
            continue;
        }
        visited[v]=true;
        cout << v << " ";

        vector<pair<int, int>> vect = inp.list[v];
        sort(vect.begin(), vect.end());

        for (int i = vect.size()-1; i>=0; i--) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
            }
        }
    }
    cout<<endl;
}

void DFSlistIterByWt (int StartNd, AdjacencyList &inp, vector<bool> &visited) {
    stack<int> res;
    res.push(StartNd);
    while (!res.empty()) {
        int v = res.top();
        res.pop();

        if (visited[v]) {
            continue;
        }
        visited[v]=true;
        cout << v << " ";

        vector<pair<int, int>> vect = inp.list[v];
        sort(vect.begin(), vect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for (int i = vect.size()-1; i>=0; i--) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
            }
        }
    }
    cout<<endl;
}

void DFSmatrixIterByNum (int StartNd, AdjacencyMatrix &inp, vector<bool> &visited) {
    stack<int> res;
    res.push(StartNd);
    while (!res.empty()) {
        int v = res.top();
        res.pop();

        if (visited[v]) {
            continue;
        }
        visited[v]=true;
        cout << v << " ";

        vector<pair<int, int>> vect = {};
        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i] != 0) {
                vect.push_back(pair<int, int> {i, inp.mat[v][i]});
            }
        }

        sort(vect.begin(), vect.end()); //just in case

        for (int i = vect.size()-1; i>=0; i--) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
            }
        }
    }
    cout<<endl;
}

void DFSmatrixIterByWt (int StartNd, AdjacencyMatrix &inp, vector<bool> &visited) {
    stack<int> res;
    res.push(StartNd);
    while (!res.empty()) {
        int v = res.top();
        res.pop();

        if (visited[v]) {
            continue;
        }
        visited[v]=true;
        cout << v << " ";

        vector<pair<int, int>> vect = {};
        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i] != 0) {
                vect.push_back(pair<int, int> {i, inp.mat[v][i]});
            }
        }

        sort(vect.begin(), vect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for (int i = vect.size()-1; i>=0; i--) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
            }
        }
    }
    cout<<endl;
}

void BFSlistIterByNum (int StartNd, AdjacencyList &inp, vector<bool> &visited) {
    queue<int> res;
    res.push(StartNd);
    visited[StartNd] = true;
    while (!res.empty()) {
        int v = res.front();
        cout<<v<<" ";
        res.pop();

        vector<pair<int, int>> vect = inp.list[v];
        sort(vect.begin(), vect.end());

        for (int i = 0; i<vect.size(); i++) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
                visited[next]=true;
            }
        }
    }
    cout<<endl;
}

void BFSlistIterByWeight (int StartNd, AdjacencyList &inp, vector<bool> &visited) {
    queue<int> res;
    res.push(StartNd);
    visited[StartNd] = true;
    while (!res.empty()) {
        int v = res.front();
        cout<<v<<endl;
        res.pop();

        vector<pair<int, int>> vect = inp.list[v];
        sort(vect.begin(), vect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for (int i = 0; i<vect.size(); i++) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
                visited[next]=true;
            }
        }
    }
    cout<<endl;
}

void BFSmatrixIterByNum (int StartNd, AdjacencyMatrix &inp, vector<bool> &visited) {
    queue<int> res;
    res.push(StartNd);
    visited[StartNd] = true;
    while (!res.empty()) {
        int v = res.front();
        cout<<v<<" ";
        res.pop();

        vector<pair<int, int>> vect = {};
        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i] != 0) {
                vect.push_back(pair<int, int> {i, inp.mat[v][i]});
            }
        }

        sort(vect.begin(), vect.end()); //just in case

        for (int i = 0; i<vect.size(); i++) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
                visited[next]=true;
            }
        }
    }
    cout<<endl;
}

void BFSmatrixIterByWeight (int StartNd, AdjacencyMatrix &inp, vector<bool> &visited) {
    queue<int> res;
    res.push(StartNd);
    visited[StartNd] = true;
    while (!res.empty()) {
        int v = res.front();
        cout<<v<<" ";
        res.pop();

        vector<pair<int, int>> vect = {};
        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i] != 0) {
                vect.push_back(pair<int, int> {i, inp.mat[v][i]});
            }
        }

        sort(vect.begin(), vect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for (int i = 0; i<vect.size(); i++) {
            int next = vect[i].first;
            if (!visited[next]) {
                res.push(next);
                visited[next]=true;
            }
        }
    }
    cout<<endl;
}

//Block 3
void DijkstraList (int start, AdjacencyList &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d>dist[v]) {
            continue;
        }

        int n = inp.list[v].size();
        for (int i = 0; i<n; i++) {
            pair<int, int> curr = {inp.list[v][i].second, inp.list[v][i].first};
            if (dist[curr.second]<=dist[v]+curr.first) {
                continue;
            }
            curr.first = dist[v]+curr.first;
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
}

vector<int> DijkstraListBetween (int start, int end, AdjacencyList &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (v==end) {
            vector<int> path = {};
            int curr = end;
            while (curr!=-1) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        if (d>dist[v]) {
            continue;
        }

        int m = inp.list[v].size();
        for (int i = 0; i<m; i++) {
            pair<int, int> curr = {inp.list[v][i].second, inp.list[v][i].first};
            if (dist[curr.second]<=dist[v]+curr.first) {
                continue;
            }
            curr.first = dist[v]+curr.first;
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
    cout<<"Can`t find path to vertice!";
    return {};
}

void DijkstraListAll (AdjacencyList &inp, vector<vector<int>> &dist, vector<vector<int>> &parent) {
   int n =inp.V;
    dist.resize(n);
    parent.resize(n);

    for (int i = 0; i<n; i++) {
        DijkstraList(i, inp, dist[i], parent[i]);
    }
}

void DijkstraMatrix (int start, AdjacencyMatrix &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d>dist[v]) {
            continue;
        }

        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i]<=0) {
                continue;
            }
            pair<int, int> curr = {inp.mat[v][i], i};
            if (dist[curr.second]<=dist[v]+curr.first) {
                continue;
            }
            curr.first = dist[v]+curr.first;
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
}

vector<int> DijkstraMatrixBetween (int start, int end, AdjacencyMatrix &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (v==end) {
            vector<int> path = {};
            int curr = end;
            while (curr!=-1) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        if (d>dist[v]) {
            continue;
        }

        for (int i = 0; i<inp.mat[v].size(); i++) {
            if (inp.mat[v][i]<=0) {
                continue;
            }
            pair<int, int> curr = {inp.mat[v][i], i};
            if (dist[curr.second]<=dist[v]+curr.first) {
                continue;
            }
            curr.first = dist[v]+curr.first;
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
    cout<<"Can`t find path to vertice!";
    return {};
}

void DijkstraMatrixAll (AdjacencyMatrix &inp, vector<vector<int>> &dist, vector<vector<int>> &parent) {
    int n =inp.V;
    dist.resize(n);
    parent.resize(n);

    for (int i = 0; i<n; i++) {
        DijkstraMatrix(i, inp, dist[i], parent[i]);
    }
}

//Block 4
vector<int> KahnList (AdjacencyList &inp) {
    int n = inp.V;
    vector<int> in_degree (n, 0);

    for (int i=0; i<n; i++) {
        int m = inp.list[i].size();
        for (int j=0; j<m; j++) {
            in_degree[inp.list[i][j].first]++;
        }
    }

    queue<int> q;
    vector<int> res;
    for (int i = 0; i<n; i++) {
        if (in_degree[i]==0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        res.push_back(top);
        for (int i = 0; i<inp.list[top].size(); i++) {
            int next = inp.list[top][i].first;
            in_degree[next]--;
            if (in_degree[next]==0) {
                q.push(next);
            }
        }
    }

    if (res.size() != n) {
        cout<<"There were cycles in graph. Topological sorting is impossible!"<<endl;
        return {};
    }

    return res;
}

vector<int> KahnMatrix (AdjacencyMatrix &inp) {

    int n = inp.V;
    vector<int> in_degree (n, 0);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (inp.mat[i][j]!=0) {
                in_degree[j]++;
            }
        }
    }

    queue<int> q;
    vector<int> res;
    for (int i = 0; i<n; i++) {
        if (in_degree[i]==0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        res.push_back(top);
        for (int i = 0; i<n; i++) {
            if (inp.mat[top][i]==0) {
                continue;
            }
            in_degree[i]--;
            if (in_degree[i]==0) {
                q.push(i);
            }
        }
    }

    if (res.size() != n) {
        cout<<"There were cycles in graph. Topological sorting is impossible!"<<endl;
        return {};
    }

    return res;
}

//Block 5
void SpanningTreeList (AdjacencyList &inp, vector<pair<int, int>> &tree, vector<bool> &visited, int v, int &total_weight) {
    if (visited[v]) {
        return;
    }
    visited[v]=true;
    for (int i = 0; i<inp.list[v].size(); i++) {
        pair<int, int> next = inp.list[v][i];
        if (!visited[next.first]) {
            tree.push_back({v, next.first});
            total_weight += next.second;
            SpanningTreeList(inp, tree, visited, inp.list[v][i].first, total_weight);
        }
    }
}

void SpanningTreeMatrix (AdjacencyMatrix &inp, vector<pair<int, int>> &tree, vector<bool> &visited, int v, int &total_weight) {
    if (visited[v]) {
        return;
    }
    visited[v]=true;
    for (int i = 0; i<inp.mat.size(); i++) {
        if (inp.mat[v][i]!=0 && !visited[i]) {
            tree.push_back({v, i});
            total_weight += inp.mat[v][i];
            SpanningTreeMatrix(inp, tree, visited, i, total_weight);
        }
    }
}

//Block 6
int PrimList (int start, AdjacencyList &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    vector<pair<int, int>> res = {};
    vector<bool> visited;
    visited.assign(n, false);

    int total_weight = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (visited[v]) continue;

        visited[v]=true;
        res.push_back({d, v});
        total_weight+=d;

        int m = inp.list[v].size();
        for (int i = 0; i<m; i++) {
            pair<int, int> curr = {inp.list[v][i].second, inp.list[v][i].first};
            if (visited[curr.second] || curr.first>=dist[curr.second]) {
                continue;
            }
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
    return total_weight;
}
int PrimMatrix (int start, AdjacencyMatrix &inp, vector<int> &dist, vector<int> &parent) {
    int n = inp.V;
    dist.assign(n, INT_MAX);
    dist[start] = 0;
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    vector<pair<int, int>> res = {};
    vector<bool> visited;
    visited.assign(n, false);

    int total_weight = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (visited[v]) continue;

        visited[v]=true;
        res.push_back({d, v});
        total_weight+=d;

        for (int i = 0; i<n; i++) {
            if (inp.mat[v][i]==0) continue;
            pair<int, int> curr = {inp.mat[v][i], i};
            if (visited[curr.second] || curr.first>=dist[curr.second]) {
                continue;
            }
            dist[curr.second] = curr.first;
            parent[curr.second] = v;
            pq.push(curr);
        }
    }
    return total_weight;
}