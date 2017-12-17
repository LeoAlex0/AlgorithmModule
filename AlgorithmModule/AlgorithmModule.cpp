// AlgorithmModule.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "algorithm_module.h"

namespace GraphAlgorithm {
	
	PUBLIC int
		bfsStep(
			int idx_start_v, int idx_dest_v,
			const FirstEdgeAdapter & firstOf, const NextEdgeAdapter & nextOf, 
			const EdgeToAdapter & destOf) {

		std::list<int> indexList{ NIL , idx_start_v };
		std::unordered_map<int, int> depOf;
		depOf.insert(std::make_pair(idx_start_v, 0));

		for (int v : indexList) {
			if (v == NIL) continue;
			if (v == idx_dest_v) return depOf[v];
			indexList.pop_front();

			for (int edge = firstOf(v); edge != NIL; edge = nextOf(v, edge)) {
				const int v1 = destOf(v, edge);
				
				if (depOf.count(v1) != 0) continue;
				
				depOf.insert(std::make_pair(v1, depOf[v] + 1));
				indexList.push_back(v1);
			}
		}
		return NIL;
	}
}