#pragma once

#include <iostream>
#include <algorithm>

template< unsigned N=64, typename T=char >
class ShortString
{
public:

	ShortString() {}
	ShortString(const T* p);
	ShortString(const T* p, unsigned l);
	ShortString(const ShortString& ss);

	ShortString& append(const T* p);
	ShortString& append(const char c);
	ShortString& append(const ShortString& ss);
	ShortString& append(const int num);
	ShortString& append(const float num);
	ShortString& append(const double num);

	ShortString& operator = (const T* p);
	ShortString& operator = (const ShortString& ss);

	bool operator == (const ShortString& that) const;
	bool operator != (const ShortString& that) const;
	bool operator <  (const ShortString& that) const;
	bool operator >  (const ShortString& that) const;
	bool operator <= (const ShortString& that) const;
	bool operator >= (const ShortString& that) const;

	unsigned length() { return len; }

	int findFirstOf(const T* p, unsigned s=0);
	int findLastOf(const T* p, unsigned s=0);

	ShortString subString(unsigned pos, unsigned l);

	friend std::ostream& operator<<(std::ostream& os, const ShortString& s) { os << s.data; return os; }

private:

	T data[N];
	unsigned len = 0;
};

template< unsigned N, typename T > inline
int ShortString<N, T>::findFirstOf(const T* p, unsigned s)
{
	unsigned lw = (unsigned)strlen(p);

	for (unsigned n = s; n <= len-lw; ++n)
	{
		if (data[n] != p[0] || data[n+lw-1] != p[lw-1]) continue;

		bool check(true);
		for(unsigned x=1; x<lw-1; ++x)
		{
			if (data[n+x] != p[x]) { check = false; break; }
		}

		if (check == true) return n;
	}

	return -1;
}

template< unsigned N, typename T > inline
int ShortString<N, T>::findLastOf(const T* p, unsigned s)
{
	unsigned lw = (unsigned)strlen(p);

	for (unsigned n = len-1; n >= s+lw-1; --n)
	{
		if (data[n] != p[lw-1] || data[n-lw+1] != p[0]) continue;

		bool check(true);
		for (unsigned x = 1; x < lw - 1; ++x)
		{
			if (data[n-x] != p[lw-1-x]) { check = false; break; }
		}

		if (check == true) return n-lw+1;
	}

	return -1;
}

template< unsigned N, typename T > inline
ShortString<N, T> ShortString<N, T>::subString(unsigned p, unsigned l)
{
	return ShortString<N, T>(data+p, l);
}


template< unsigned N, typename T > inline
ShortString<N,T>::ShortString(const T* p)
{
	len = 0;
	append(p);
}

template< unsigned N, typename T > inline
ShortString<N, T>::ShortString(const T* p, unsigned l)
{
	len = l;
	for (unsigned i = 0; i < len; ++i) data[i] = p[i];
	data[len] = '\0';
}

template< unsigned N, typename T > inline
ShortString<N,T>::ShortString(const ShortString<N,T>& ss)
{
	len = 0;
	append(ss);
}

template< unsigned N, typename T > inline
ShortString<N,T>& ShortString<N,T>::append(const T* p)
{
	unsigned s = strlen(p);
	strcpy_s(data+len, s+1, p);
	len += s;
	return *this;
}

template< unsigned N, typename T > inline
ShortString<N, T>& ShortString<N, T>::append(const char p)
{
	data[len++] = p;
	return *this;
}

template< unsigned N, typename T > inline
ShortString<N,T>& ShortString<N, T>::append(const ShortString<N, T>& ss)
{
	return append(ss.data);
}

template< unsigned N, typename T> inline
ShortString<N, T>& ShortString<N, T>::append(const int num)
{
	len += sprintf_s(data+len, N-len, "%d", num );
	return *this;
}

template< unsigned N, typename T> inline
ShortString<N, T>& ShortString<N, T>::append(const float num)
{
	len += sprintf_s(data+len, N-len, "%f", num);
	return *this;
}

template< unsigned N, typename T> inline
ShortString<N, T>& ShortString<N, T>::append(const double num)
{
	len += sprintf_s(data+len, N-len, "%f", num);
	return *this;
}

template< unsigned N, typename T > inline
ShortString<N,T>& ShortString<N, T>::operator = (const T* p)
{
	len = 0;
	append(p);
}

template< unsigned N, typename T > inline
ShortString<N,T>& ShortString<N, T>::operator = (const ShortString<N, T>& ss)
{
	len = 0;
	append(ss);
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator == (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if (data[i] != that.data[i]) return false;
	}
	return true;
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator != (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if (data[i] != that.data[i]) return true;
	}
	return false;
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator < (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if(data[i] < that.data[i]) return true;
		else if (data[i] > that.data[i]) return false;
	}

	return false;
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator > (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if (data[i] > that.data[i]) return true;
		else if (data[i] < that.data[i]) return false;
	}

	return false;
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator <= (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if (data[i] < that.data[i]) return true;
		else if (data[i] > that.data[i]) return false;
	}

	return true;
}

template<unsigned N, typename T>
bool ShortString<N, T>::operator >= (const ShortString& that) const
{
	unsigned mx = std::max(len, that.len);
	for (unsigned i = 0; i < mx; ++i)
	{
		if (data[i] > that.data[i]) return true;
		else if (data[i] < that.data[i]) return false;
	}

	return true;
}
