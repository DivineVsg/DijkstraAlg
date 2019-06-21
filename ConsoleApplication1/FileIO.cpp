#include "pch.h"
#include "FileIO.h"


// 1 shag, path = put' na fajl
FileIO::FileIO(std::string path)
{
	this->filePath = path;
	this->MaxVertices = 0; // vershiny

	Graph();
}

// 2 shag
std::vector<std::vector<int>> FileIO::Graph()
{
	//diagramma
	std::vector<std::vector<int>> dijGraph;

	//array iz fajla
	std::vector<std::string> givenGraph = ReadGraphFrom();
	
	//chitaet vershiny iz pervoj stroki array
	MaxVertices = std::stoi(givenGraph[0]);

	//ostalnye stroki push_back v vector dijGraph
	for (int iter = 0; iter < MaxVertices; iter++)
		dijGraph.push_back(std::vector<int>());

	//temp
	int x;

	//stroku [0] ja propuskaju t.k. eto cifra MaxVertices
	for (int i = 1; i < givenGraph.size(); i++)
	{
		std::stringstream ss(givenGraph[i]);

		while (ss >> x)
		{
			dijGraph[i - 1].push_back(x);

			if (ss.peek() == ',')
				ss.ignore();
		}

	}

	return dijGraph;
}

void FileIO::AnswerToFile(std::vector<std::string> inGraph, std::string outPath)
{
	std::ofstream f(outPath);

	for (auto line : inGraph)
	{
		f << line;
	}

	f.close();
}

std::vector<std::string> FileIO::ReadGraphFrom()
{
	std::vector<std::string> lines;
	std::string line;

	std::ifstream myReadFile;

	myReadFile.open(filePath);

	while (std::getline(myReadFile, line))
		lines.push_back(line);

	myReadFile.close();

	return lines;
}
