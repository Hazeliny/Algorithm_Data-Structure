
	if (!(keyBegin < keyEnd))
		return ;
	if (keyBegin < begin) {
		if (val == m_valBegin) {
			if (keyEnd < begin) nothing;
			else if (keyEnd == begin) nothing;
			else if (keyEnd > begin && keyEnd != end()) {
				erase(all the elements from begin to prev(itHigh));
				if (keyEnd == itHigh->first) {
					if (val == itHigh->second)
						erase(itHigh);
					else
						nothing;
				}
				else if (keyEnd < itHigh->first) {
					V postVal = get the original value between keyEnd and itHigh->first;
					if (val != postVal)
						m_map[keyEnd] = postVal;
				}
			}
			else if (keyEnd == end()) nothing;
		}
		else if (val != m_valBegin) {
			m_map[keyBegin] = val;
			if (keyEnd < begin)
				m_map[keyEnd] = m_valBegin; // keep original value between keyEnd and begin()
			else if (keyEnd == begin) {
				if (val != begin->second) nothing;
				else
					erase(begin); // begin means: std::next(m_map.find(keyBegin)). merge the added new area and the one beginning with begin()
			}
			else if (keyEnd > begin && keyEnd != end()) {
				erase(all the elements from begin(included) to prev(itHigh));
				if (keyEnd == itHigh->first) {
					if (val == itHigh->second)
						erase(itHigh);
					else nothing;
				}
				else if (keyEnd < itHigh->first) {
					V postVal = get the original value between keyEnd and itHigh->first; // i.o. std::prev(itHigh)->second
					if (val != postVal)
						m_map[keyEnd] = postVal;
					else nothing;
				}
				else if (keyEnd == end()) {
					erase(all the old elements from begin(not included) to end()(included. last element));//because begin() is new keyBegin at this time, it can't be deleted.
					m_map[keyEnd] = m_valBegin;
				}
			}
		}
	}
	else if (keyBegin == begin) {
		if (val == m_valBegin) {
			if (keyEnd > begin && keyEnd != end()) {
				erase(all the elements from begin to prev(itHigh)->first);
				if (keyEnd == itHigh->first) {
					if (val == itHigh->second)
						erase(itHigh);
					else nothing;
				}
				else if (keyEnd < itHigh->first) {
					V postVal = get the original value between keyEnd and itHigh->first;
					if (val != postVal)
						m_map[keyEnd] = postVal;
				}
			}
			else if (keyEnd == end())
				erase(all the elements from begin);
		}
		else if (val != m_valBegin) {
			if (keyEnd > begin && keyEnd != end()) {
				erase(all the elements from begin to prev(itHigh)->first);
				if (keyEnd == itHigh->first) {
					if (val == itHigh->second) {
						erase(itHigh);
						m_map[keyBegin] = val;
					}
					else if (val != itHigh->second)
						m_map[keyBegin] = val;
					else if (keyEnd < itHigh->first) {
						postVal = get the original value between keyEnd and itHigh->first;
						if (val != postVal) {
							m_map[keyEnd] = postVal;
							m_map[keyBegin] = val;
						}
						else if (val == postVal)
							m_map[keyBegin] = val;
					}
				}
			}
			else if (keyEnd == end()) {
				erase(all the elements);
				m_map[keyBegin] = val;
				m_map[keyEnd] = m_valBegin;	
			}
		}
	}
	else if (keyBegin > begin && keyBegin != end()) {
		if (keyEnd > keyBegin && keyEnd != end()) {
			V preVal = get the original value between keyBegin and prev(itLow)->first;
			if (val == preVal) {
				postVal = get the original value between keyEnd and itHigh->first or the value of itHigh->second;
				if (val == postVal)
					erase(all the elements between keyBegin(included) and keyEnd(included) (not includes itHigh->first(keyEnd<itHigh), but includes itHigh->first(keyEnd==itHigh)));
			}
			else if (val != preVal) {
				if (keyBegin < itLow->first || keyBegin == itLow->first && val != itLow->second)
					m_map[keyBegin] = val;
				postVal = get the original value between keyEnd and itHigh->first or the value of itHigh->second;
				if (val == postVal)
					erase(all the elements between keyBegin(not included) and keyEnd(when keyEnd<itHigh, not includes itHigh, when keyEnd==itHigh, includes itHigh));
				else if (val != postVal)
					m_map[keyEnd] = postVal;
			}
		}
		else if (keyEnd == end()) {
			V preVal = get the original value between keyBegin and prev(itLow)->first, i.o. the value of prev(itLow)->second;
			if (val == preVal) {
				if (val == m_valBegin)
					erase(all the elements between keyBegin(included) and the last one(included)(itLow(included)--->nn));
				else if (val != m_valBegin) {
					erase(all the elements from keyBegin to last one);
					m_map[keyEnd] = m_valBegin;
				}
			}
			else if (val != preVal) {
				if (keyBegin < itLow->first || keyBegin == itLow->first && val != itLow->second)
					m_map[keyBegin] = val;
				erase(all the elements from keyBegin(not inlcuded) to last one);
				if (val == m_valBegin) nothing;
				else if (val != m_valBegin)
					m_map[keyEnd] = m_valBegin;
			}
		}
	}
	else if (keyBegin == end() && keyEnd ==  end()) {
		if (val == m_valBegin) nothing;
		else if (val != m_valBegin) {
			m_map[keyBegin] = val;
			m_map[keyEnd] = m_valBegin;
		}
	}
