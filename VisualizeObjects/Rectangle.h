#pragma once
#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "IShapes.h"

namespace RCV
{
	class Rectangle : public IShape
	{
	public:
		void draw();
	};
}

#endif // !RECTANGLE_HPP_
