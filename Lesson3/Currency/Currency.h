#pragma once
#include <tuple>

template <class T, class V>
class Currency
{
	private:
		T code;
		V name;
	
	public:
		Currency(T &code, V &name);
		bool operator<(const Currency<T, V>& currency) const;
		T getCode();
		V getName();
};


template <class T, class V>
Currency<T, V>::Currency(T &code, V &name) : code(code), name(name)
{

}

template <class T, class V>
T Currency<T,V>::getCode()
{
	return code;
}

template <class T, class V>
V Currency<T, V>::getName()
{
	return name; 
}

template <class T, class V>
bool Currency<T, V>::operator<(const Currency<T, V>& currency) const
{
	return std::tie(code, name) < std::tie(currency.code, currency.name);
}
