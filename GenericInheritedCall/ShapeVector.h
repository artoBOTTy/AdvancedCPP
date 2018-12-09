#pragma once
#ifndef SHAPE_VECTOR_HPP_
#define SHAPE_VECTOR_HPP_

#include <vector>

using namespace std;

template <typename SHAPE_TYPE>
class VShape : public vector<SHAPE_TYPE*>
{
	typedef typename vector<SHAPE_TYPE*>::iterator iterator;
public:
	void draw()
	{
		for (iterator it = begin(); it != end(); it++)
		{
			(*it)->draw();
		}
	}
};

#endif // !SHAPE_VECTOR_HPP_
