#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	
public:
    V m_valBegin;
	std::map<K,V> m_map;
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if(!(keyBegin<keyEnd)){
            return;
        }
        std::map<K,V> temp=m_map;
        bool flag=false;
        m_map.clear();
        if(temp.size()==0){     // Initial case where there are no other vals in the map, so basic solution.
            m_map[keyBegin]=val;
            m_map[keyEnd]=m_valBegin;
            return;
        }
        auto it = temp.begin();         //Will iterate through all the items that were in the map
        while (it != temp.end()) {      //to find the first instance where keyBegin is smaller than the keys in the map
            if (!(it->first < keyBegin)) {
                if (it->second == val) {                //If the assigned val is within the interval of an existing interval with the same value
                                                        //it will reassign using the smallest key and the biggest key from both.
                    auto nextIt = std::next(it);        //Find if there is another element after the current one 
                    K nextKey = (nextIt != temp.end()) ? nextIt->first : keyEnd;
                    assign(it->first, std::min(nextKey, keyEnd), val);
                    break;
                } else {                        //If the current key is indeed smaller, we simply add it in and reassign again
                    m_map[it->first] = val;
                    flag = true;
                    auto nextIt = std::next(it);
                    assign(nextIt->first, std::min(nextIt->first, keyEnd), temp[it->first]);
                    break;
                }
            } 
            else {
                flag = true;
                m_map[it->first] = temp[it->first];
                ++it;
            }
        }
        if (!flag) {
            m_map[keyBegin] = val;
        }
        auto itBeforeEnd = std::prev(m_map.end());
        if (itBeforeEnd->first == keyEnd) {
            itBeforeEnd->second = m_valBegin;
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
    

