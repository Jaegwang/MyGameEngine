#pragma once

#include <ShortString.h>

template< unsigned N, unsigned M >
class ShortStringArray
{
public:

	ShortStringArray() {}

private:

	ShortString<N> arr[M];

};
