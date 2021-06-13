#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000

class Graph 
{
public:
    Graph(int v); //построение матрицы смежности
    void addEdge(int i, int j); // добавление ребра (дружбы)
    void printMatrix(); //вывод матрицы смежности (дружбы)
    void findMinDistance (int start);
private:    
    int distance[SIZE]; //массив расстояний
    bool visited[SIZE]; //массив меток
    int vertexCount,index, u, start; 
    int matrix[SIZE][SIZE]; // матрица смежности
};
