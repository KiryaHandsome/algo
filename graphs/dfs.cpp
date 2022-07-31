#include <vector>

using namespace std;


vector<vector<int>> g; //graph
vector<char> used;

void dfs(int v)
{
    used[v] = true;
    for (auto i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}