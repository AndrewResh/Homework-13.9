#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(int v) //���������� ������� ���������
{
        for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
}

void Graph::addEdge(int i, int j) // ���������� ����� (������)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void Graph::printMatrix() // ����� �������
{
    const int n = 10;
    char arr[n][10] = { "���", "����", "����", "����", "�����", "�����", "����", "����", "�����", "�����" };
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
    char arr[n][10] = { "���", "����", "����", "����", "�����", "�����", "����", "����", "�����", "�����" };
    for (int i = 0; i < n; i++) //�������������� ������ ���������� � ������ ����� �������� ������� ��� ���
    {
        distance[i] = VERYBIGINT; 
        visited[i] = false;
    }
    distance[start] = 0; //���������� �� ���� ����� 0
    
    for (vertexCount = 0; vertexCount < n - 1; vertexCount++) //���� ��  ��������
    {
        int min = VERYBIGINT;  //������������ ��� ����������� ���������� ��� ����� ������������� ��� ��������� �������
        
        for (int i = 0; i < n; i++) //����� ���������� �� ������� ����������
        {
            if (!visited[i] && distance[i] <= min) //���� ������� �� �������� � ���������� �� �� ������ min ��
            {
                //���������� ���������� � ������
                min = distance[i]; 
                index = i;
            }
        } 
        u = index;
        //��������� ��� ������� ��������
        visited[u] = true;
        //���� ����� ���������� �� �������
        for (int i = 0; i < n; i++) 
        {
            //���� ������� �� �������� � ���� ����� � ���������� �� ����� ��������� ������������� �
            //���� �������� ��������� �� ������� �� �� ������ ��� ������ ������� ��������� ��
            if (!visited[i] && matrix[u][i] && distance[u] != VERYBIGINT && distance[u] + matrix[u][i] < distance[i]) 
            {
                //��������� ��� ����������
                distance[i] = distance[u] + matrix[u][i];
            }
        }
    }
    //������� ��� ��� ���� ������� ����� � ������ 3-� ����������� 
    cout << arr[start] << " ������ � :";
    for (int i = 0; i < n; i++) 
    {
        //���� ���� ���� � �� �� ����� ������ ���� � ��������� ������ ��� ����� 3 �� ������� ��� �����
        if (distance[i] != VERYBIGINT && start != i && distance[i] <= 3) cout << "\t" << arr[i];
    }
    cout << endl << endl;
}
                
        
    