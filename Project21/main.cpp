#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Graph socnet(SIZE);
    
    // ������ ���
    socnet.addEdge(0, 1);
    socnet.addEdge(0, 8);
    //������ ����
    socnet.addEdge(1, 0);
    socnet.addEdge(1, 4);
    socnet.addEdge(1, 5);
    //������ ����
    socnet.addEdge(2, 3);
    socnet.addEdge(2, 9);
    //������ ����
    socnet.addEdge(3, 2);
    socnet.addEdge(3, 4);
    //������ �����
    socnet.addEdge(4, 1);
    socnet.addEdge(4, 3);
    //������ �����
    socnet.addEdge(5, 6);
    socnet.addEdge(5, 6);
    //������ ����
    socnet.addEdge(6, 5);
    socnet.addEdge(6, 7);
    socnet.addEdge(6, 8);
    // ������ �����
    socnet.addEdge(7, 6);
    socnet.addEdge(7, 9);
    // ������ �����
    socnet.addEdge(8, 0);
    socnet.addEdge(8, 6);
    //������ �����
    socnet.addEdge(9,2);
    socnet.addEdge(9,7);
    cout << "\n";

    socnet.printMatrix();
    cout << "\n";
        
    socnet.findMinDistance(0);
    socnet.findMinDistance(1);
    socnet.findMinDistance(2);
    socnet.findMinDistance(3);
    socnet.findMinDistance(4);
    socnet.findMinDistance(5);
    socnet.findMinDistance(6);
    socnet.findMinDistance(7);
    socnet.findMinDistance(8);
    socnet.findMinDistance(9);

    return 0;
}