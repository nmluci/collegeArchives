# Pseudocode and Prove of Concept of Graphing System
# By Cxizaki (Fuyuna#1273)
# Github: nmluci
import os

def init(len: int) -> list:
    vertices = [[0 for _ in range(len)] for _ in range(len)]

    for i in range(len):
        for j in range(len):
            if (i != j): 
                vertices[i][j] = int(input("Ketik 1 bila vertex {} dan vertex {} terhubung: ".format(i+1, j+1)))
            else:
                vertices[i][j] = 0
    return vertices

def printMatrix(vertices, length):
    for i in range(length):
        temp = ""
        for j in range(length):
            temp += str(vertices[i][j]) + ' '
        print(temp)
        temp = ""

def isConnected(vertices, length):
    vertex = [0 for _ in range(length-1)]

    for i in range(length-1):
        vertex[i] = vertices[0][i+1]

    for index, node in enumerate(vertex):
        if (node == 1):
            for subindex, subnode in enumerate(vertices[index+1]):
                if (vertex == [1 for _ in range(length-1)]): break
                if (subnode == 1 and subindex != vertex[subindex-1] and subindex-1 >= 0):
                    vertex[subindex-1] = 1

    print(vertex)
    return vertex == [1 for _ in range(length-1)]

def isDirected(vertices, length) -> bool:
    directed = 0
    checked = []
    for i in range(length):
        for j in range(length):
            if (vertices[i][j] != vertices[j][i]): 
                directed+=1
            checked.append(i)
    return directed != 0

def degree(vertices, length):
    if (isDirected(vertices, length)):
        for index, node in enumerate(vertices):
            inset = 0
            outset = 0
            for subindex, subnode in enumerate(vertices[index]):
                outset += subnode
            for subindex, submode in enumerate(vertices):
                inset += vertices[subindex][index]
            print("{}: Keluar {}, Masuk {}".format(index+1, inset, outset))
    else:
        for index, node in enumerate(vertices):
            degree = 0
            for subindex, subnode in enumerate(vertices[index]):
                degree += subnode
            print("{}: Derajat {}".format(index+1, degree))

def route(vertices, length):
    route = ""
    visited = []
    ctr = 0
    while(ctr not in visited):
        for index, node in enumerate(vertices[ctr]):
            if (node == 1):
                visited.append(ctr)
                # print("{} | {} {} | {} {}".format(vertices[ctr], ctr+1, index+1, vertices[ctr][index], vertices[index][ctr]))
                if vertices[ctr][index] == vertices[index][ctr] and vertices[ctr][index] == 1 :route += "{} <-> ".format(ctr+1)
                if vertices[ctr][index] != vertices[index][ctr] and vertices[ctr][index] == 1 :route += "{} -> ".format(ctr+1)
                if vertices[ctr][index] != vertices[index][ctr] and vertices[ctr][index] == 0 :route += "{} <- ".format(ctr+1)
                ctr = index
    if route[-4:] == "<-> ":
        route = route[:-4]
    elif route[-3:] == "-> " or route[-3:] == "<- ":
        route = route[:-3]

    print("Rute", route)

def menu():
    opt = 0
    isInit = False
    while (opt != 6):
        print("Graphing System")
        print("Discrete Mathematics II")
        print("Main Menu =============")
        if (isInit):
            print("Graph =================")
            printMatrix(vertices, len)
            print("========================")
        print("[1] Input Vertex")
        print("[2] Periksa Keterhubungan Vertex")
        print("[3] Perika Jenis Graph")
        print("[4] Periksa Derajat Tiap Vertex")
        print("[5] Tampilkan Salah Satu Rute")
        print("[6] Keluar")
        opt = int(input("Masukkan pilihan: "))
        os.system("cls")
        if opt == 1:
            len = int(input("Masukkan panjang graph: "))
            vertices = init(len)
            isInit = True
        if opt == 2:
            if (isInit): 
                print("Graph Terhubung: {}".format(isConnected(vertices, len)))
            else:
                print("Masukkan vertex!")
        if opt == 3:
            if (isInit):
                stats = isDirected(vertices, len)
                if (not stats):
                    print("Graph tidak berarah!")
                else:
                    print("Graph berarah!")
            else:
                print("Masukkan vertex!")
        if opt == 4:
            if (isInit):
                degree(vertices, len)
            else:
                print("Masukkan vertex!")
        if opt == 5:
            if (isInit):
                route(vertices, len)
            else:
                print("Masukkan vertex!")
    
    print("Terima Kasih!!!")
    exit()

menu()