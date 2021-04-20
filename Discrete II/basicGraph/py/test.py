# Pseudocode and Prove of Concept of Graphing System
# By Cxizaki (Fuyuna#1273)
# Github: nmluci

import sys
print("Discrete Mathematics II")
print("Graphing System\n")

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
            print("{}: Inset {}, Outset {}".format(index+1, inset, outset))
    else:
        for index, node in enumerate(vertices):
            degree = 0
            for subindex, subnode in enumerate(vertices[index]):
                degree += subnode
            print("{}: Degree {}".format(index+1, degree))

def isExist(arr, val):
    if val in arr: return True
    else: return False

def route(vertices, length):
    stop = False
    root = ""
    ctr = 0
    visited = []
    while(not isExist(visited, ctr)):
        for index, node in enumerate(vertices[ctr]):
            if (node == 1):
                visited.append(ctr)
                print(root)
                print(visited)
                # print("{} | {} {} | {} {}".format(vertices[ctr], ctr+1, index+1, vertices[ctr][index], vertices[index][ctr]))
                if vertices[ctr][index] == vertices[index][ctr] and vertices[ctr][index] == 1 :root += "{} <-> ".format(ctr+1)
                if vertices[ctr][index] != vertices[index][ctr] and vertices[ctr][index] == 1 :root += "{} -> ".format(ctr+1)
                if vertices[ctr][index] != vertices[index][ctr] and vertices[ctr][index] == 0 :root += "{} <- ".format(ctr+1)
                ctr = index
    if root[-4:] == "<-> ":
        root = root[:-4]
    elif root[-3:] == "-> " or root[-3:] == "<- ":
        root = root[:-3]

    print("Exit", ctr, visited)
    print("Route", root)

def testBase():
    print("First Data")
    length = 4
    vertices = [
        [0, 0, 1, 1],
        [0, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0]
    ]
    printMatrix(vertices,length)
    print("Expected Result: Connected, Undirected")
    print("Connected Graph: {}".format(isConnected(vertices, length)))
    print("Directed Graph: {}".format(isDirected(vertices, length)))
    degree(vertices, length)
    route(vertices, length)
    
    print("Second Data")
    length = 5
    vertices = [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0]
    ]
    printMatrix(vertices,length)
    print("Expected Result: Connected, Directed")
    print("Connected Graph: {}".format(isConnected(vertices, length)))
    print("Directed Graph: {}".format(isDirected(vertices, length)))
    degree(vertices, length)
    route(vertices, length)

    print("Third Data")
    length = 5
    vertices = [
        [0, 1, 0, 0, 0],
        [1, 0, 1, 0, 0],
        [0, 1, 0, 1, 1],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0]
    ]
    printMatrix(vertices,length)
    print("Expected Result: Connected, Undirected")
    print("Connected Graph: {}".format(isConnected(vertices, length)))
    print("Directed Graph: {}".format(isDirected(vertices, length)))
    degree(vertices, length)
    route(vertices, length)

    print("Forth Data")
    length = 4
    vertices = [
        [0, 1, 0, 0],
        [1, 0, 0, 0],
        [0, 0, 0, 1],
        [0, 0, 1, 0]
    ]
    printMatrix(vertices,length)
    print("Expected Result: Disconnected, Undirected")
    print("Connected Graph: {}".format(isConnected(vertices, length)))
    print("Directed Graph: {}".format(isDirected(vertices, length)))
    degree(vertices, length)
    route(vertices, length)

    print("Fifth Data")
    length = 4
    vertices = [
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 1, 0, 1],
        [0, 1, 0, 0]
    ]
    printMatrix(vertices, length)
    print("Expected Result: Connected, Directed")
    print("Connected Graph: {}".format(isConnected(vertices, length)))
    print("Directed Graph: {}".format(isDirected(vertices, length)))
    degree(vertices, length)
    route(vertices, length)

testBase()