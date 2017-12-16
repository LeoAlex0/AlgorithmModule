// DLLTester.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

const int dest = 30;
const int start = 0;
GraphAlgorithm::FirstEdgeAdapter firstOf = [](int v) -> int {return 0; };
GraphAlgorithm::NextEdgeAdapter nextOf = [](int v,int e) -> int {return GraphAlgorithm::NIL; };
GraphAlgorithm::EdgeToAdapter to = [](int v, int e) -> int {return v + (dest - v) / 2; };

int main()
{
	const int dep = GraphAlgorithm::bfsStep(start, dest, firstOf, nextOf, to);
	if (dep == GraphAlgorithm::NIL)
		printf_s("NIL Finded\n");
	else printf_s("%d Step(s)\n", dep);
    return 0;
}

