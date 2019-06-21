#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "FileIO.h"
//#define V 10

#pragma once

struct DijkstraSolution
{

};

class DijkstraAlg
{
private:
	int maxVertices;
public:
	DijkstraAlg(int);
	std::vector<std::string> Answer;

	void Run(FileIO);
	int MinDistance(std::vector<int>, std::vector<bool>);
	void PrintPath(std::vector<int>, int);
	void PrintedAnswer(std::vector<int>, int, std::vector<int>);
};

