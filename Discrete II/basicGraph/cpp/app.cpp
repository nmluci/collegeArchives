#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <conio.h>

const int MAX_SIZE = 10;

bool isExist(std::vector<int> arr, int val) {
    for (auto i: arr) {
        if (i == val) return true;
    }
    return false;
}

std::vector<std::vector<int>> init(size_t len) {
    std::vector<std::vector<int>> verticles(len, std::vector<int>(len));

    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            if (i != j)  {
                std::cout << "Ketik 1 bila " << i+1 << " dan " << j+1 << " terhubung: ";
                std::cin >> verticles[i][j];;
            } else {
                verticles[i][j] = 0;
            }
        }
    }
    return verticles;
}

void printMatrix(std::vector<std::vector<int>> verticles, size_t len) {
    for (int i=0; i < len; i++) {
        for (int j=0; j<len; j++) {
            std::cout << verticles[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isConnected(std::vector<std::vector<int>> verticles, size_t len) {
    std::vector<int> vertex(len-1, 0);
    std::vector<int> refVertex(len-1, 1);
    bool status = false;

    for (int i=0; i < len-1; i++) {
        vertex[i] = verticles[0][i+1];
    }

    for (int index = 0; index < len-1; index++) {
        if (vertex[index] == 1) {
            for (int subindex = 0; subindex < len-1; subindex++) {
                if (vertex == refVertex) break;
                if (verticles[index+1][subindex] == 1 && subindex != vertex[subindex-1] && subindex-1 >= 0) {
                    vertex[subindex-1] = 1;
                }
            }
        }
    }

    return vertex == refVertex;
}

bool isDirected(std::vector<std::vector<int>> verticles, size_t len) {
    int directed = 0;
    std::vector<int> checked;

    for (int i=0; i < len; i++) {
        for (int j=0; j < len; j++) {
            if (verticles[i][j] != verticles[j][i]) directed++;
            checked.push_back(i);
        }
    }
    return directed != 0;
}

void degree(std::vector<std::vector<int>> verticles, size_t len) {
    if (isDirected(verticles, len)) {
        for (int index=0; index < len; index++) {
            int in = 0;
            int out = 0;
            for (int x=0; x < len; x++) in += verticles[x][index];
            for (int y=0; y < len; y++) out += verticles[index][y];
            std::cout << index+1 << " In: " << in << " Out: " << out << std::endl;
        }
    } else {
        for (int index=0; index < len; index++) {
            int degree = 0;
            for (int z=0; z < len; z++) degree += verticles[index][z];
            std::cout << index+1 << " Degree: " << degree << std::endl;
        }
    }
}

void route(std::vector<std::vector<int>> verticles, size_t len) {
    std::string routes;
    std::vector<int> visited;
    int ctr = 0;
    while (!isExist(visited, ctr)) {
        for (int index=0; index < len; index++) {
            if (verticles[ctr][index] == 1) {
                visited.push_back(ctr);
                if ((verticles[ctr][index] == verticles[index][ctr]) && verticles[ctr][index] == 1) {
                    routes += (std::to_string(ctr+1) + " <-> ");
                } else if ((verticles[ctr][index] != verticles[index][ctr]) && verticles[ctr][index] == 1) {
                    routes += (std::to_string(ctr+1) + " -> ");
                } else if ((verticles[ctr][index] != verticles[index][ctr]) && verticles[ctr][index] == 0) {
                    routes += (std::to_string(ctr+1) + " <- ");
                }
                ctr = index;
            }
        }
    }

    if (routes.find("<->") != std::string::npos) routes = routes.substr(0, routes.length()-4);
    if (routes.find("->") != std::string::npos) routes = routes.substr(0, routes.length()-3);
    if (routes.find("<-") != std::string::npos) routes = routes.substr(0, routes.length()-3);

    std::cout << "Routes: " << routes << std::endl;
}

int main() {
    int len = 0;
    int opt = 0;
    bool isInit = false;
    std::vector<std::vector<int>> vertices;

    while (opt != 6) {
        system("cls");
        std::cout << "=====================" << std::endl;
        std::cout << "=  Discrete Math II =" << std::endl;
        std::cout << "== Graphing System ==" << std::endl;
        std::cout << "=====================" << std::endl;
        if (isInit) {
            std::cout << "======= Graph =======" << std::endl;
            printMatrix(vertices, len);
            std::cout << "=====================" << std::endl;
        }
        std::cout << "[1] Masukkan Graph" << std::endl;
        std::cout << "[2] Periksa Keterhubungan" << std::endl;
        std::cout << "[3] Periksa Jenis" << std::endl;
        std::cout << "[4] Perika Derajat" << std::endl;
        std::cout << "[5] Tampilkan Salah Satu Rute" << std::endl;
        std::cout << "[6] Keluar" << std::endl << std::endl;
        std::cout << "Input: ";
        std::cin >> opt;

        if (opt == 1) {
            std::cout << "Masukkan panjang vertex: ";
            std::cin >> len;
            vertices = init(len);
            isInit = true;
        }
        if (opt == 2) {
            if (isInit) {
                std::cout << "Graph " << (isConnected(vertices, len) ? "Terhubung" : "Tidak Terhubung") << std::endl;
            } else {
                std::cout << "Masukkan Graph Terlebih Dahulu!" << std::endl;
            }
        }
        if (opt == 3) {
            if (isInit) {
                std::cout << "Graph " << (isDirected(vertices, len) ? "Berarah" : "Tidak Berarah") << std::endl;
            } else {
                std::cout << "Masukkan Graph Terlebih Dahulu!" << std::endl;
            }
        }
        if (opt == 4) {
            if (isInit) {
                degree(vertices, len);
            } else {
                std::cout << "Masukkan Graph Terlebih Dahulu!" << std::endl;
            }
        }
        if (opt == 5) {
            if (isInit) {
                route(vertices, len);
            } else {
                std::cout << "Masukkan Graph Terlebih Dahulu!" << std::endl;
            }
        }
        getch();
    }

    std::cout << "Terima Kasih!" << std::endl;
}