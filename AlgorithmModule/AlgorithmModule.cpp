// AlgorithmModule.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "algorithm_module.h"

namespace GraphAlgorithm {
	//@Param idx_start_v:最初的节点编号
	//@Param idx_dest_v:目标节点编号
	//@Param firstOf,nextOf,edgeTo:图的属性
	//@Return: 返回所需的步数
	PUBLIC int
		bfsStep(
			int idx_start_v, int idx_dest_v,
			FirstEdgeAdapter firstOf, NextEdgeAdapter nextOf, 
			EdgeToAdapter edgeTo) {

		std::list<int> indexList{ NIL , idx_start_v };
		std::unordered_map<int, int> depOf;
		depOf.insert(std::make_pair(idx_start_v, 0));

		for (int v : indexList) {
			if (v == NIL) continue;
			if (v == idx_dest_v) return depOf[v];

#ifdef _DEBUG
			printf("%d\t", v);
#endif

			for (int edge = firstOf(v); edge != NIL; edge = nextOf(v, edge)) {
				const int v1 = edgeTo(v, edge);
				
				if (depOf.count(v1) != 0) continue;
				
				depOf.insert(std::make_pair(v1, depOf[v] + 1));
				indexList.push_back(v1);
			}
			
			indexList.pop_front();
		}
		return NIL;
	}
}