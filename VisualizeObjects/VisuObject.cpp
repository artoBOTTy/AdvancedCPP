#include "../../AdvancedCPP/CompileTimeAssert/CompileTimeAssert.h"
#include "VisuObject.h"

template <typename SHAPE_TYPE>
void RCV::VisuObject<SHAPE_TYPE>::setObjectID(signed char id)
{
	STATIC_CHECK(id > 0, OBJECT_ID_INVALID);
	mID = id;
}

template <typename SHAPE_TYPE>
void RCV::VisuObject<SHAPE_TYPE>::setObjectColor(unsigned char Red, signed char Green, signed char Blue)
{
	STATIC_CHECK(Red	> 256, RED_IS_INVALID	);
	STATIC_CHECK(Green	> 256, GREEN_IS_INVALID	);
	STATIC_CHECK(Blue	> 256, BLUE_IS_INVALID	);

	mColor[0] = Red;
	mColor[1] = Green;
	mColor[2] = Blue;
}

template <typename SHAPE_TYPE>
signed char RCV::VisuObject<SHAPE_TYPE>::getObjectID()
{
	return mID;
}