#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

typedef std::vector<int> array_t;
typedef std::vector<bool> boolArr_t;
typedef int matrices_t[8][8];
const size_t size = 8;

// matrices_t init(size_t len);
int dfs(matrices_t graph, int prev, int start, bool* visited);
bool isBridge(matrices_t graph, int x, int y);
bool isEuler(matrices_t graph);
int count(matrices_t graph);
int getStart(matrices_t graph);
void printMatrix(matrices_t graph);
void eulerRoute(matrices_t graph, int start);
int absolute(int num);

int main() {
    size_t len = 8;

    // std::cout << "Masukkan jumlah vertex: ";
    // std::cin >> len;

    matrices_t graph = {
        {0,1,1,0,0,0,0,0},
        {1,0,1,1,1,0,0,0},
        {1,1,0,1,0,1,0,0},
        {0,1,1,0,0,0,0,0},
        {0,1,0,0,0,1,1,1},
        {0,0,1,0,1,0,1,1},
        {0,0,0,0,1,1,0,0},
        {0,0,0,0,1,1,0,0}
    };
    // static matrices_t copy = graph;
    eulerRoute(graph, getStart(graph));
}

// matrices_t init(size_t len) {
//     matrices_t vertices(len, array_t(len));

//     for (int i=0; i<len; i++) {
//         for (int j=0; j<len; j++) {
//             if (i!=j) {
//                 std::cout << "Enter 1 if " << i+1 << " and " << j+1 << " connected: ";
//                 std::cin >> vertices[i][j];
//             } else {
//                 vertices[i][j] = 0;
//             }
//         }
//     }

//     return vertices;
// }

int absolute(int num) {
    return (num > 0) ? num : num*-1;
}

int dfs(matrices_t graph, int prev, int start, bool visited[]) {
    int ctr = 1;
    visited[start] = true;
    for (int i = 0; i<size; i++) {
        if (prev != i) {
            if (!visited[i]) {
                if (graph[start][i]) {
                    ctr += dfs(graph, start, i, visited);
                }
            }
        }
    }
    return ctr;
}

bool isBridge(matrices_t graph, int x, int y) {
    int deg = 0;
    for (int i=0; i<size; i++) if (graph[y][i]) deg++;
    if (deg > 1) return false;
    return true;
}

int count(matrices_t graph) {
    int ctr = 0;
    for (int i=0; i<size; i++)
    for (int j=i; j<size; j++)
    if (graph[i][j]) ctr++;

    return ctr;
}

int getStart(matrices_t graph) {
    for (int i=0; i<size; i++) {
        int deg = 0;
        for (int j=0; j<size; j++) {
            if (graph[i][j]) deg++;
        }
        if (deg%2 != 0) return i;
    }
    return 0;
}

void eulerRoute(matrices_t graph, int start) {
    int edge = count(graph);
    int len = size;

    for (int i=0; i<size; i++) {
        if (graph[start][i]) {
            bool visited[8] = {false};
            if (isBridge(graph, start, i)) len--;
            int ctr = dfs(graph, start, i, visited);
            if (absolute(len-ctr) <= 2) {
                std::cout << start << "--" << i << " ";
                if (isBridge(graph, i, start)) len--;

                graph[start][i] = graph[i][start] = 0;
                edge--;
                eulerRoute(graph, i);
            }
        }
    }
}