#pragma once
#ifndef TYPELIST_HPP_
#define TYPELIST_HPP_

template <typename T, typename U>
struct Typelist
{
	typedef T head;
	typedef U tail;
};

class NullType {};


/// Macros for linear typelist generation. 
/// Append to this list for creating longer lists.
/// Defined Typelist length is 4. (Update here after adding a new linear typelist generator)...
#define TYPELIST_01(T1)				Typelist<T1, NullType>					/// Typelist with 1 type
#define TYPELIST_02(T1, T2)			Typelist<T1, TYPELIST_01(T2)>			/// Typelist with 2 types
#define TYPELIST_03(T1, T2, T3)		Typelist<T1, TYPELIST_02(T2, T3)>		/// Typelist with 3 types
#define TYPELIST_04(T1, T2, T3, T4) Typelist<T1, TYPELIST_03(T2, T3, T4)>	/// Typelist with 4 types
// Follow the above pattern to create longer lists

namespace RCV
{
	/// Algo to calculate the length of Typelist
	template<typename TList> struct Length;

	template<> struct Length<NullType>
	{
		enum { value = 0 };
	};

	template<typename T, typename U>
	struct Length<Typelist<T, U> >
	{
		enum {value = 1 + Length<U>::value };
	};


	/// Indexed access
	template<typename TList, unsigned int INDEX> struct TypeAt;

	template<typename Head, typename Tail>
	struct TypeAt <Typelist<Head, Tail >, 0 >
	{
		typedef Head Type;
	};

	template<typename Head, typename Tail, unsigned int INDEX>
	struct TypeAt <Typelist<Head, Tail >, INDEX >
	{
		typedef typename TypeAt<Tail, INDEX - 1 >::Type Type;
	};


	/// Searching for a Type
	template<typename TList, typename TYPE> struct IndexOf;

	template<typename TYPE>
	struct IndexOf<NullType, TYPE>
	{ 
		enum { index = -1 }; 
	};

	template <class T, class Tail> 
	struct IndexOf<Typelist<T, Tail>, T> 
	{ 
		enum { index = 0 }; 
	};

	template <class Head, class Tail, class T> 
	struct IndexOf<Typelist<Head, Tail>, T> 
	{ 
	private:
		enum { temp = IndexOf<Tail, T>::index };
	public:
		enum { index = temp == -1 ? -1 : 1 + temp }; 
	};


	/// Appending to a typelist

}

#endif //TYPELIST_HPP_