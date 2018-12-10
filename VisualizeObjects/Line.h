#pragma once
#ifndef LINE_HPP_
#define LINE_HPP_

#include "IShapes.h"

namespace RCV
{
	class Line : public IShape
	{
	public:
		void draw();
	};
}

#endif // !LINE_HPP_
