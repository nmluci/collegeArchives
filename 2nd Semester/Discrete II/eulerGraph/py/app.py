# Eulerian Path and Circuit Route Finder
import sys

class EulerRoute:
    def __init__(self, length=0, verbose=False):
        self.graphLength = length
        self.currVertices = 0
        self.verbose = verbose

        if self.graphLength > 0:
            self.graph = [ [0 for _ in range(self.graphLength)] for _ in range(self.graphLength)]
        else:
            self.graph = list(list())

    def getInput(self):
        self.graphLength = int(input("Masukkan jumlah vertex: "))
        self.graph = [ [0 for _ in range(self.graphLength)] for _ in range(self.graphLength)]

        for i in range(self.graphLength):
            for j in range(self.graphLength):
                if i != j:
                    self.graph[i][j] = int(input("Ketik 1 bila {} dan {} terhubung: ".format(i, j)))
                else:
                    self.graph[i][j] = 0
                self.currVertices+=1
        self.start()

    def isEuler(self) -> bool:
        odd = 0

        for v in self.graph:
            if self.degree(v) % 2 != 0:
                odd += 1
            if odd == 0:
                if self.verbose: print("Graph -> Sirkuit Euler!")
                return True
            elif odd <= 2:
                if self.verbose: print("Graph -> Lintasan Euler!")
                return True
            else:
                return False

    def isNextEdge(self, x, y):
        if self.degree(self.graph[x]) == 1:
            return True
        else:
            visiteda = [False] * (self.graphLength)
            counta = self.countEdges(x, visiteda)

            self.removeEdge(x, y)
            visitedb = [False] * (self.graphLength)
            countb = self.countEdges(x, visitedb)
            
            self.addEdge(x, y)
            return False if counta > countb else True

    def addEdge(self, x, y):
        if not (self.graph[x][y] == 1 or self.graph[y][x] == 1):
            self.graph[x][y] = 1
            self.graph[y][x] = 1
            self.currVertices += 1
    
    def removeEdge(self, x, y):
        if not (self.graph[x][y] == 0 or self.graph[y][x] == 0):
            self.graph[x][y] = 0
            self.graph[y][x] = 0
            self.currVertices -= 1

    def countEdges(self, vertex, visited: bool) -> int:
        ctr = 1
        visited[vertex] = True

        for i in range(len(self.graph[vertex])):
            if not visited[i]:
                ctr += self.countEdges(i, visited)
        return ctr

    def isBridge(self, x, y) -> bool:
        visiteda = [False] * (self.graphLength)
        counta = self.countEdges(x, visiteda)
        
        self.removeEdge(x, y)
        visitedb = [False] * (self.graphLength)
        countb = self.countEdges(x, visitedb)
        
        self.addEdge(x, y)
        return False if counta > countb else True

    def degree(self, vertices: list) -> int:
        ctr = 0
        for v in vertices: 
            if v: ctr+=1
        return ctr

    def eulerRoute(self, start: int):
        len = self.graphLength

        for i in range(self.graphLength):
            if self.graph[start][i]:
                visited = [False] * self.graphLength
                if self.isBridge(start, i): 
                    len-=1
                ctr = self.countEdges(i, visited)
                if abs(len-ctr) <= 2:
                    sys.stdout.write("{} --> {}\n".format(start, i))
                    if self.isBridge(i, start): 
                        len -=1
                    self.removeEdge(i, start)
                    self.eulerRoute(i)

    def eulerRouteWrapper(self):
        print("Rute: ")
        startVertex = self.getStart()
        self.eulerRoute(startVertex)

    def printMatrix(self):
        sys.stdout.write("\nMatrix: \n")
        for i in self.graph:
            for j in i:
                sys.stdout.write("{} ".format(j))
            sys.stdout.write("\n")
        sys.stdout.write("\n")

    def getStart(self) -> int:
        for idx, i in enumerate(self.graph):
            if self.degree(i) % 2 != 0:
                return idx
        return 0

    def start(self):
        if self.graphLength > 0:
            self.printMatrix()
            if self.isEuler(): self.eulerRouteWrapper()
            else: print("Bukan Euler!")
        else:
            self.getInput()

print("Eulerian Graph Tour")
print("Discrete II")

g1 = EulerRoute(4, True)
g1.addEdge(0, 1)
g1.addEdge(0, 2)
g1.addEdge(1, 2)
g1.addEdge(2, 3)
g1.start()


g2 = EulerRoute(3, True)
g2.addEdge(0, 1)
g2.addEdge(1, 2)
g2.addEdge(2, 0)
g2.start()

g3 = EulerRoute(5, True)
g3.addEdge(1, 0)
g3.addEdge(0, 2)
g3.addEdge(2, 1)
g3.addEdge(0, 3)
g3.addEdge(3, 4)
g3.addEdge(3, 2)
g3.addEdge(3, 1)
g3.addEdge(2, 4)
g3.start()

g4 = EulerRoute(5, True)
g4.addEdge(0,1)
g4.addEdge(1,2)
g4.addEdge(1,3)
g4.addEdge(1,4)
g4.addEdge(2,3)
g4.addEdge(3,4)
g4.addEdge(4,1)
g4.start()

# if __name__ == '__main__':
#     EulerRoute().start()