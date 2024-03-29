#include "pch.h"
#include "DijkstraAlg.h"
#include "FileIO.h"

int main()
{
	FileIO f("array.txt");
	DijkstraAlg alg(f.MaxVertices);

	alg.Run(f);
	f.AnswerToFile(alg.Answer, "answer.txt");
}
