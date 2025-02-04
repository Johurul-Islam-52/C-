#pragma once
#include<set>
using namespace std;

template<class K>
class Colecao : public std::set<K> {
public:
	bool insert(const K& c);
	K* find(const K& c);
	int size() const;
	void erase(const K&);
	//void clear();
	//bool empty() const;
	//iterator begin();
	//iterator end();
};
template<class K>
bool Colecao<K>::insert(const K& c) {
	pair<set<K>::iterator, bool> r = set<K>::insert(c);
	return (r.second);
}
template<class K>
K* Colecao<K>::find(const K& c) {
	K* r = 0;
	typename set<K>::iterator it = set<K>::find(c);
	if (it != set<K>::end())
		r = const_cast<K*>(it.operator->());
	return (r);
}
template<class K>
int Colecao<K>::size()const {
	return ((int)set<K>::size());
}
template<class K>
void Colecao<K>::erase(const K& c) {
	set<K>::erase(c);
}



