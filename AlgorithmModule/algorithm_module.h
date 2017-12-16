#pragma once

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <utility>

#define PUBLIC __declspec(dllexport)
namespace GraphAlgorithm {
	//�����ڵı��
	const int NIL = -1;

	//��������������

	//@Param idx_v:�ڵ���
	//@Return:�ڵ�idx_v�����ĵ�һ���ߵı��,�ޱ�ʱ����NIL
	typedef std::function<int(int idx_v)> FirstEdgeAdapter;

	//@Param: idx_v:�ڵ���
	//@Param: idx_e:��ǰɨ�赽�ı�
	//@Return:������һ���ߵ�id,�ޱ�ʱ����NIL
	typedef std::function<int(int idx_v, int idx_e)> NextEdgeAdapter;

	//@Param: idx_v:�ڵ���
	//@Param: idx_e:��ǰɨ�赽�ı�
	//@Return:����ָ��ڵ��id,�ޱ�ʱ����NIL
	typedef std::function<int(int idx_v, int idx_e)> EdgeToAdapter;

	//@Param idx_v:��ʾ�˱���v����
	//@Param idx_e:��ʾ�˱߱��
	//@Return:�ڵ�idx_v�ı��Ϊidx_e�ıߵĳ���
	typedef std::function<double(int idx_v, int idx_e)> EdgeLengthAdapter;

	//@Param idx_v:��ʾ�ڵ�idx_v
	//@Param idx_e:��ʾ��idx_v�����ı��Ϊidx_e�ı�
	//@Return:�ڵ�idx_v�ı��Ϊidx_e�ıߵ�����
	typedef std::function <double(int idx_v, int idx_e)> EdgeContainAdapter;

	PUBLIC int
		bfsStep(
			int idx_start_v, int idx_dest_v,
			FirstEdgeAdapter firstOf, NextEdgeAdapter nextOf,
			EdgeToAdapter edgeTo);
}