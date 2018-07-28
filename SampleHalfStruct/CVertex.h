#ifndef CVERTEX_H_INCLUDED
#define CVERTEX_H_INCLUDED

#include <stdlib.h>
#include "CPoint.h"
#include "CHalfEdge.h"
#include <list>

namespace Meshlib
{
	class HalfEdge;
	///<summary>
	///��������Ļ���
	///</summary>
	class Vertex
	{
	public:
		Vertex() { m_halfedge = NULL; };
		~Vertex() {};
		int m_vertex_id;
		Point m_position;
		HalfEdge *m_halfedge;

		//��Ϊ�Ǽ��׵�������ʱ���÷�װ
		std::list<Edge*> m_edges;
	};

}

#endif
