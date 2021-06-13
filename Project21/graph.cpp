#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(int v) //построение матрицы смежности
{
        for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
}

void Graph::addEdge(int i, int j) // добавление ребра (дружбы)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void Graph::printMatrix() // вывод матрицы
{
    const int n = 10;
    char arr[n][10] = { "Аня", "Петя", "Вася", "Лена", "Настя", "Игорь", "Маша", "Макс", "Костя", "Ольга" };
    for (int i = 0; i < SIZE; i++)
    {
        cout <<i+1<<' '<<arr[i] << " : "<<"\t";
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t ";
        cout << "\n";
    }
}
 
void Graph::findMinDistance(int start)
{
    const int n = 10;
    char arr[n][10] = { "Аня", "Петя", "Вася", "Лена", "Настя", "Игорь", "Маша", "Макс", "Костя", "Ольга" };
    for (int i = 0; i < n; i++) //инициализируем массив расстояний и массив меток посещена вершина или нет
    {
        distance[i] = VERYBIGINT; 
        visited[i] = false;
    }
    distance[start] = 0; //расстояние до себя равно 0
    
    for (vertexCount = 0; vertexCount < n - 1; vertexCount++) //цикл по  вершинам
    {
        int min = VERYBIGINT;  //предполагаем что минимальное расстояние это число бесконечности для алгоритма Дейстры
        
        for (int i = 0; i < n; i++) //далее проходимся по массиву расстояний
        {
            if (!visited[i] && distance[i] <= min) //если вершина не посещена и расстояние до неё меньше min то
            {
                //запоминаем расстояние и индекс
                min = distance[i]; 
                index = i;
            }
        } 
        u = index;
        //указываем что вершину посетили
        visited[u] = true;
        //цикл сбора расстояний до вершины
        for (int i = 0; i < n; i++) 
        {
            //если вершина не посещена и есть ребро и расстояние не равна константе бесконечности и
            //если добавить расстоние до вершины то не станет она больше текущей дистанции то
            if (!visited[i] && matrix[u][i] && distance[u] != VERYBIGINT && distance[u] + matrix[u][i] < distance[i]) 
            {
                //добавляем это расстояние
                distance[i] = distance[u] + matrix[u][i];
            }
        }
    }
    //выводим имя для кого строили связи с учётом 3-х рукопожатий 
    cout << arr[start] << " дружит с :";
    for (int i = 0; i < n; i++) 
    {
        //если путь есть и он не равен самому себе и дистанция меньше или равна 3 то выводим имя друга
        if (distance[i] != VERYBIGINT && start != i && distance[i] <= 3) cout << "\t" << arr[i];
    }
    cout << endl << endl;
}
                
        
    