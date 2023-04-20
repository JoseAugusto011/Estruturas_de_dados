# -*- coding: utf-8 -*-
from grafo import Grafo

def ler_arquivo(nome_arquivo):
    f = open(nome_arquivo, 'r')
    n = int(f.readline())
    print(n)
    g = Grafo(n)
    g.print()
    
    i = 0
    for l in f:
        numeros = l.split('\t')
        print(numeros)
        j = 0
        for k in range(g.n):
            p = int(numeros[k])
            if p > 0:
                g.M[i][j] = p
                g.L[i].append(j)
            
            j += 1
        i += 1   
    
    return g

g = ler_arquivo("Grafo/pcv177.txt")
g.BFS(2)
g.print()