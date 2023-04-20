# -*- coding: utf-8 -*-
import queue

BRANCO = 1
CINZA = 2
PRETO = 3
class Grafo:

    def __init__(self, _n):
        self.n = _n
        self.M = [[0 for _ in range(_n)] for _ in range(_n)]
        self.L = [[] for _ in range(_n)]
        self.pai = [None for _ in range(_n)]
        self.d = [float("inf") for _ in range(_n)]
    
    def print(self):
        print("Matriz de Adjacencia:")
        print(self.M)
        print("")
        print("Lista de Adjacencia:")
        print(self.L)
        print("")
        print("D:")
        print(self.d)
        print("")
        print("Pai:")
        print(self.pai)
     
        
    def BFS(self, s):
         cor = [BRANCO for _ in range(self.n)]
         cor[s] = CINZA
         self.d[s] = 0
         Q = queue.Queue()
         Q.put(s)
         while Q.empty() == False:
             v = Q.get()
             for u in self.L[v]:
                 if cor[u] == BRANCO:
                     cor[u] = CINZA
                     self.d[u] = self.d[v] + 1
                     self.pai[u] = v
                     Q.put(u)
             cor[v] = PRETO

 

#g = Grafo(4)
#g.print()