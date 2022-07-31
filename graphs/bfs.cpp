#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int v; // number of vertices
    vector<vector<int>> g; //graph
public:
    Graph(int v)
        : v(v)
    {
        g.resize(v);

    }

    void addEdge(int from, int to) {
        g[from].push_back(to);
    }

    //s - start vertice
    void bfs(int s)
    {
        vector<bool> used(v);
        queue<int> q;
        q.push(s);
        used[s] = true;
        vector<int> d(v), p(v); //arrays of shortest lengths and paths
        p[s] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v][i];
                if (used[to] == false) {
                    used[to] = true;
                    q.push(to);
                    d[to] = d[v] + 1;
                    p[to] = v;
                }
            }
        }

        //rebuild path to some vertice 'to'
        /*
        vector<int> path;
        for(int v = to; v != -1; v = p[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        сout << "Path: ";
        for(int i : path) {
            cout << i + 1 << " ";
        }
        */
    }
};


int main()
{

}
