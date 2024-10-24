
#include <map>
#include <iostream>
using namespace std;

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
void assign(K const& keyBegin, K const& keyEnd, V_forward&& val)
    requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
{
    if (!(keyBegin < keyEnd))
        return;
    auto itLow = m_map.lower_bound(keyBegin);
    auto itHigh = m_map.lower_bound(keyEnd);
    m_map[keyBegin] = V(std::forward<V_forward>(val));
	V postVal = (itHigh == m_map.end()) ? m_valBegin : 
                 (keyEnd < itHigh->first ? 
                 (itHigh == m_map.begin() ? m_valBegin : std::prev(itHigh)->second) : 
                 itHigh->second);
	if (itHigh == m_map.end() || keyEnd < itHigh->first) {
		if (m_map.find(keyEnd) == m_map.end())
    		m_map.emplace(keyEnd, V(postVal));
	}
    if (itLow != m_map.begin() && std::prev(itLow)->second == m_map[keyBegin])
        m_map.erase(itLow);
    auto itEnd = m_map.find(keyEnd);
    if (itEnd != m_map.end()) {
		auto nextItEnd = std::next(itEnd);
		if (nextItEnd != m_map.end() && nextItEnd->second == itEnd->second)
			m_map.erase(nextItEnd);
		itEnd = m_map.find(keyEnd);
		if (itEnd !=m_map.end() && itEnd != m_map.begin()) {
			auto prevItEnd = std::prev(itEnd);
			if (prevItEnd->second == itEnd->second)
				m_map.erase(itEnd);
		}
	}
}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};
void intervalMapTest() {
	interval_map<int, char> imap('A');
	char valueAt0 = imap[0];
	char valueAt1 = imap[1];
	char valueAt2 = imap[2];
	char valueAt3 = imap[3];
	char valueAt4 = imap[4];
	std::cout << "0 " <<valueAt0 << " " << valueAt1 << " " << valueAt2 << " " << valueAt3 << " " << valueAt4 << std::endl;
	imap.assign(1, 3, 'B');
	valueAt0 = imap[0];
	valueAt1 = imap[1];
	valueAt2 = imap[2];
	valueAt3 = imap[3];
	valueAt4 = imap[4];
	std::cout << "1 " <<valueAt0 << " " << valueAt1 << " " << valueAt2 << " " << valueAt3 << " " << valueAt4 << std::endl;
	
	imap.assign(2, 5, 'C');
	valueAt0 = imap[0];
	valueAt1 = imap[1];
	valueAt2 = imap[2];
	valueAt3 = imap[3];
	valueAt4 = imap[4];
	std::cout << "2 " << valueAt0 << " " << valueAt1 << " " << valueAt2 << " " << valueAt3 << " " << valueAt4 << std::endl;

	imap.assign(2, 4, 'B');
	valueAt0 = imap[0];
	valueAt1 = imap[1];
	valueAt2 = imap[2];
	valueAt3 = imap[3];
	valueAt4 = imap[4];
	std::cout << "3 " << valueAt0 << " " << valueAt1 << " " << valueAt2 << " " << valueAt3 << " " << valueAt4 << std::endl;
}
int main() {
	intervalMapTest();
	return 0;
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
