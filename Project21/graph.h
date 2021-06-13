#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000

class Graph 
{
public:
    Graph(int v); //���������� ������� ���������
    void addEdge(int i, int j); // ���������� ����� (������)
    void printMatrix(); //����� ������� ��������� (������)
    void findMinDistance (int start);
private:    
    int distance[SIZE]; //������ ����������
    bool visited[SIZE]; //������ �����
    int vertexCount,index, u, start; 
    int matrix[SIZE][SIZE]; // ������� ���������
};
