#include "pch.h"
#include "DijkstraAlg.h"

//1 shag
DijkstraAlg::DijkstraAlg(int maxVertices)
{
	this->maxVertices = maxVertices;
}

int DijkstraAlg::MinDistance(std::vector<int> dist, std::vector<bool> sptSet)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < maxVertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void DijkstraAlg::PrintPath(std::vector<int> parent, int j)
{
	if (parent[j] == -1)
	{
		Answer.push_back(std::string(std::to_string(1) + " "));
		return;
	}

	PrintPath(parent, parent[j]);

	Answer.push_back(std::string(std::to_string(j + 1) + " "));
}

void DijkstraAlg::PrintedAnswer(std::vector<int> dist, int n, std::vector<int> p)
{
	//std::vector<std::string> answer;
	//std::ostringstream s;

	for (int i = 0; i < maxVertices; i++)
	{
		Answer.push_back(std::string(std::to_string(i + 1) + " -> " + std::to_string(dist[i]) + " -> "));
		PrintPath(p, i);
		Answer.push_back("\n");
		//std::cout << std::endl;
	}

	//std::cout << std::endl;
	Answer.push_back(std::string("\n KpaTko oT 1 dO 10: " + std::to_string(dist[maxVertices - 1]) + "\n"));

	for (int j = 0; j < Answer.size(); j++)
	{
		std::cout << Answer[j];
	}
}

//delaet algoritm
void DijkstraAlg::Run(FileIO graphFile)
{
	std::vector<int> D(maxVertices);
	std::vector<int> P(maxVertices);

	std::vector<bool> sptSet(maxVertices);

	for (int i = 0; i < maxVertices; i++)
		D[i] = INT_MAX, sptSet[i] = false, P[0] = -1;

	D[0] = 0;

	for (int count = 0; count < maxVertices - 1; count++)
	{
		int u = MinDistance(D, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < maxVertices; v++)

			if (!sptSet[v] && graphFile.Graph()[u][v] && D[u] + graphFile.Graph()[u][v] < D[v])
			{
				D[v] = D[u] + graphFile.Graph()[u][v];
				P[v] = u;
			}
	}

	std::cout << std::endl;

	PrintedAnswer(D, maxVertices, P);
}

