#pragma once
#ifndef COMPILE_TIME_ASSERT_HPP_
#define COMPILE_TIME_ASSERT_HPP_

template<bool>
struct CompileTimeCheck
{
	CompileTimeCheck(...);
};

template<>
struct CompileTimeCheck<false> {};

#define STATIC_CHECK(expr, msg)\
{\
	class ERROR_##msg{};\
	(void)sizeof(CompileTimeCheck<(expr) != 0>((ERROR_##msg())));\
}

#endif //COMPILE_TIME_ASSERT_HPP_