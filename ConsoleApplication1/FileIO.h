#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "pch.h"

#pragma once
class FileIO
{
private:
	std::string filePath;
public:
	FileIO(std::string);

	int MaxVertices;
	std::vector<std::string> ReadGraphFrom();
	std::vector<std::vector<int>> Graph();
	void AnswerToFile(std::vector<std::string>, std::string);
};

