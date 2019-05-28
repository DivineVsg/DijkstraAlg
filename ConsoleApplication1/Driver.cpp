#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define V 10

void алгоритм(int[V][V], int);
int дистанцияМинимум(int[], bool[]);
void printPath(int[], int);
void ответ(int[], int, int[]);

int main()
{
	int аррэй[10][10] =
	{
		{0,3,4,2,0,0,0,0,0,0},
		{3,0,0,0,3,0,0,0,0,0},
		{4,0,0,0,6,0,0,0,0,0},
		{2,0,0,0,3,1,0,0,0,0},
		{0,3,6,3,0,1,8,0,7,0},
		{0,0,0,1,1,0,6,12,0,0},
		{0,0,0,0,8,6,0,0,0,14},
		{0,0,0,0,0,12,0,0,6,11},
		{0,0,0,0,7,0,0,6,0,3},
		{0,0,0,0,0,0,14,11,3,0}
	};

	алгоритм(аррэй, 0);
}

int дистанцияМинимум(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printPath(int parent[], int j)
{
	if (parent[j] == -1)
	{
		std::cout << 1 << " ";
		return;
	}

	printPath(parent, parent[j]);

	std::cout << j+1 << " ";
}

void ответ(int dist[], int n, int p[])
{
	for (int i = 0; i < V; i++)
	{
		std::cout << i + 1 << " -> " << dist[i] << " -> ";
		printPath(p, i);
		std::cout << std::endl;
	}	

	std::cout << std::endl;
	std::cout << "KpaTko oT 1 dO 10:" << " " << dist[V - 1] << std::endl;
}

void алгоритм(int graph[V][V], int Node)
{
	int D[V];
	int P[V];

	bool sptSet[V];

	for (int i = 0; i < V; i++)
		D[i] = INT_MAX, sptSet[i] = false, P[0] = -1;

	D[Node] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = дистанцияМинимум(D, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && D[u] + graph[u][v] < D[v])
			{
				D[v] = D[u] + graph[u][v];
				P[v] = u;
			}

	}

	std::cout << std::endl;

	ответ(D, V, P);
}
