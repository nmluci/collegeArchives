#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <time.h>

typedef std::vector<int> array_t;
typedef std::vector<array_t> matrices_t;
typedef std::vector<bool> boolArray_t;
typedef std::vector<std::string> stringArray_t;
typedef std::list<int> llist_t;
const std::string shuujin = "Coloring Graph";

matrices_t parseObject(std::string filename, int size);
matrices_t degree(matrices_t graph);
matrices_t sort(matrices_t arr, bool desc);
matrices_t colorize(matrices_t graph, int modelSize, int maxcolor);
stringArray_t parseName(std::string filename);
stringArray_t parseModel(std::string filename);

void printArray(array_t arr);
void printArray(matrices_t arr);
void printMatrices(matrices_t arr);
void printString(stringArray_t arr);
void visualize(matrices_t colored, stringArray_t models, stringArray_t names);
void getOutput(matrices_t colored, stringArray_t models, stringArray_t names);

int main(int argc, char* argv[]) {
    std::cout << shuujin << std::endl;
    int maxNum = -1;
    std::string fname;
    std::string input;
    if (argc == 1) {
        std::cout << "app.exe [nama datafile] [jumlah maximum warna (kosongkan untuk paling optimal)]";
        return -1;
    } else if (argc >= 2) {
        fname = argv[1];
        if (argc >= 3) maxNum = std::atoi(argv[2]);
    }

    stringArray_t models = parseModel(fname);
    stringArray_t names = parseName(fname);
    matrices_t parsed = parseObject(fname, names.size());
    matrices_t colored = colorize(parsed, models.size(), maxNum);
    visualize(colored, models, names);
    
    std::cout << "Print Output to file? [Y/N]: ";
    while (std::getline(std::cin, input)) {
        if (input == "y") {
            getOutput(colored, models, names);
        }
        break;
    }
}

stringArray_t parseName(std::string filename) {
    std::string tStart = "name_Start";
    std::string tEnd = "name_End";
    std::string str;
    stringArray_t parsed;
    std::ifstream file(filename);
    bool isTemplate = false;

    while (std::getline(file, str)) {
        if (str == tStart) isTemplate = true;
        if (str == tEnd) isTemplate = false;
        
        if (isTemplate && (str != tStart && str != tEnd)) parsed.push_back(str);
    }
    if (parsed.size() == 0) {
        std::cout << "[ERROR] Data tidak lengkap!" << std::endl;
        exit(-1);
    }

    std::cout << "Names: " << std::endl;
    for (auto &i: parsed) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    
    file.close();
    return parsed;
}

stringArray_t parseModel(std::string filename) {
    std::string mStart = "model_Start";
    std::string mEnd = "model_End";
    std::ifstream file(filename);
    std::string str;
    stringArray_t parsed;
    bool isTemplate = false;
    
    while (std::getline(file, str)) {
        if (str == mStart) isTemplate = true;
        if (str == mEnd) isTemplate = false;
        
        if (isTemplate && (str != mStart && str != mEnd)) parsed.push_back(str);
    }

    if (parsed.size() == 0) {
        std::cout << "[ERROR] Data tidak lengkap!" << std::endl;
        exit(-1);
    }

    std::cout << "Models: " << std::endl;
    for (auto &i: parsed) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    
    file.close();
    return parsed;
}

matrices_t parseObject(std::string filename, int size) {
    std::string dStart = "data_start";
    std::string dEnd = "data_end";
    std::ifstream file(filename);
    std::string str;
    matrices_t zeroes(size, std::vector<int>(size, 0));
    int index = 0;
    bool isObj = false;
    array_t parsedBuff;

    matrices_t parsed(size, std::vector<int>(size, 0));

    while (std::getline(file, str)) {
        if (str == dStart) isObj = true;
        if (str == dEnd) isObj = false;

        if (isObj) {
            std::stringstream strbuff(str);
            strbuff >> index;
            for (int x; strbuff >> x;) {
                parsed[index][x] = 1;
                parsed[x][index] = 1;
            }
        }
    }

    if (parsed == zeroes) {
        std::cout << "[Warning] Data Kemungkinan Tidak Terdefinisi Sesuai Struktur" << std::endl;
    }
    // printMatrices(parsed);
    return parsed;
}

matrices_t degree(matrices_t graph) {
    int len = graph[0].size();
    matrices_t degree(len, std::vector<int>(2, 0));

    for (int i=0; i<len; i++) {
        degree[i][0] = i;
        for (int j=0; j<len; j++) {
            degree[i][1] += graph[i][j];
        }
    }
    return degree;
}

matrices_t sort(matrices_t arr, bool desc=1) {
    array_t base;
    int len = arr.size();

    for (int i=0; i<len; i++) {
        for (int j=0; j<len-1; j++) {
            if (desc) {
                if (arr[j][1] < arr[j+1][1]) {
                    base = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = base;
                }
            } else {
                if (arr[j][1] > arr[j+1][1]) {
                    base = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = base;
                }
            }
        }
    }
    return arr;
}

matrices_t colorize(matrices_t graph, int modelSize, int maxcolor = -1) {
    if (maxcolor == -1) maxcolor = 9999;
    int len = graph.size();
    int color = 0;
    matrices_t priority = sort(degree(graph));

    llist_t uncolored;
    array_t colored(len, -1);
    boolArray_t isAdjVertex(len, false);
    matrices_t parsed(len, std::vector<int>(2, 0));
    array_t coloredUsed(modelSize, 0);

    for (auto &i: priority) {
        uncolored.push_back(i[0]);
    }

    for (int i=0; i<len; i++) {
        if (uncolored.empty()) break;

        int ord = uncolored.front();
        bool isColorChange = false;
        uncolored.pop_front();

        if (i==0) {
            colored[ord] = color;
            coloredUsed[color]++;
        }

        for (int i=0; i<len; i++) if (graph[ord][i]==1) isAdjVertex[i] = true;
        for (int i=0; i<len; i++) {
            if (!isAdjVertex[i] && colored[i] == -1 && coloredUsed[color] < maxcolor) {
                // std::cout << color << " " << coloredUsed[color] << std::endl;
                colored[i] = color;
                coloredUsed[color]++;
                isColorChange = true;
            }
        }
        
        for (int i=0; i<len; i++) isAdjVertex[i] = false;
        if (isColorChange) color++;
    }

    for (int i=0; i<len; i++) {
        parsed[i][0] = i;
        for (int j=0; j<len; j++) {
            parsed[i][1] = colored[i];
        }
    }

    int num = 0;
    for (auto &a: coloredUsed) {
        num += a;
    }
    if (num == len) {
        return parsed;
    } else {
        std::cout << "Coloring Graph Gagal! (Jumlah elemen maksimal terlalu sedikit)" << std::endl;
        exit(-1);
    }
}

void visualize(matrices_t colored, stringArray_t models, stringArray_t names) {
    for (int i=0; i<models.size(); i++) {
        std::cout << models[i] << std::endl;
        for (int j=0; j<colored.size(); j++) {
            if (colored[j][1] == i) {
                std::cout << names[colored[j][0]] << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void printArray(matrices_t arr) {
    for (auto &i: arr) std::cout << i[0] << " ";
    std::cout << std::endl;
    for (auto &i: arr) std::cout << i[1] << " ";
    std::cout << std::endl;
}

void printMatrices(matrices_t graph) {
    for (auto &i: graph) {
        for(auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void getOutput(matrices_t colored, stringArray_t models, stringArray_t names) {
    time_t now = time(0);
    struct tm local = *localtime(&now);

    std::string filename = std::to_string(local.tm_year+1900) + std::to_string(local.tm_mon) + std::to_string(local.tm_mday) + "_" + std::to_string(local.tm_hour) + std::to_string(local.tm_min) + std::to_string(local.tm_sec) + ".txt"; 

    std::ofstream file(filename, std::fstream::app);
    for (int i=0; i<models.size(); i++) {
        file << models[i] << std::endl;
        for (int j=0; j<colored.size(); j++) {
            if (colored[j][1] == i) {
                file << names[colored[j][0]] << std::endl;
            }
        }
        file << std::endl;
    }
    file << shuujin;
    std::cout << "Data tersimpan! [" + filename + "]" << std::endl;
}

