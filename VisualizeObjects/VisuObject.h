#pragma once
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "IShapes.h"

namespace RCV
{
	template <typename SHAPE_TYPE>
	class VisuObject : public SHAPE_TYPE
	{
	public:
		void setObjectID(signed char id);
		signed char getObjectID();
		void setObjectColor(unsigned char Red, unsigned char Green, unsigned char Blue);

	private:
		signed char mID;
		unsigned char mColor[3];
	};
}

#endif //OBJECT_HPP_