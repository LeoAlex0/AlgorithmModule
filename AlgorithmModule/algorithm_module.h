#pragma once

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <list>
#include <utility>

#define PUBLIC __declspec(dllexport) //dll输出函数，至于为什么要叫public.......

namespace GraphAlgorithm {
	//不存在的编号
	const int NIL = -1;

	//适配器类型声明

	//@Param idx_v:节点编号
	//@Return:节点idx_v相连的第一条边的编号,无边时返回NIL
	typedef std::function<int(int idx_v)> FirstEdgeAdapter;

	//@Param: idx_v:节点编号
	//@Param: idx_e:当前扫描到的边
	//@Return:返回下一条边的id,无边时返回NIL
	typedef std::function<int(int idx_v, int idx_e)> NextEdgeAdapter;

	//@Param: idx_v:节点编号
	//@Param: idx_e:当前扫描到的边
	//@Return:返回指向节点的id,无边时返回NIL
	typedef std::function<int(int idx_v, int idx_e)> EdgeToAdapter;

	//@Param idx_v:表示此边与v相连
	//@Param idx_e:表示此边编号
	//@Return:节点idx_v的编号为idx_e的边的长度
	typedef std::function<double(int idx_v, int idx_e)> EdgeLengthAdapter;

	//@Param idx_v:表示节点idx_v
	//@Param idx_e:表示与idx_v相连的编号为idx_e的边
	//@Return:节点idx_v的编号为idx_e的边的容量
	typedef std::function <double(int idx_v, int idx_e)> EdgeContainAdapter;

	struct GraphAdapter {
		FirstEdgeAdapter firstOf;
		NextEdgeAdapter nextOf;
		EdgeToAdapter destOf;
		EdgeLengthAdapter lengthOf;
		EdgeContainAdapter containOf;
	};

	//@Param idx_start_v:最初的节点编号
	//@Param idx_dest_v:目标节点编号
	//@Param firstOf,nextOf,edgeTo:图的属性
	//@Return: 返回所需的步数
	PUBLIC int
		bfsStep(
			int idx_start_v, int idx_dest_v,
			const FirstEdgeAdapter & firstOf, const NextEdgeAdapter & nextOf,
			const EdgeToAdapter & destOf);

	inline int
		bfsStep(
			int idx_start_v, int idx_dest_v,
			const GraphAdapter & graph) {
		return bfsStep(idx_start_v, idx_dest_v,
				graph.firstOf, graph.nextOf, graph.destOf);
	}
}