template <class T, class TCont = std::vector<T>>
class Stack {
	TCont data;
	
public:
	Stack() {}

	void push(T elem) {
		data.push_back(elem);
	}

	void pop() {
		if (!data.size()) {
			throw "Can't pop element from empty stack";
		}
		data.pop_back();
	}

	T& top() {
		return data[data.size() - 1];
	}

	void clear() {
		data.clear();
	}

	size_t size() {
		return data.size();
	}

	bool empty() {
		return data.empty();
	}
};