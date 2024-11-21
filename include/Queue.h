template <class T>
class Queue {
	T* data = nullptr;
	size_t memSize;
	size_t sz;
	size_t head;
	size_t tail;

	void repack() {
		T* new_data = new T[memSize * 2];
		size_t i = head, j = 0;
		while (i != tail) {
			new_data[j] = data[i];
			i = (i + 1) % memSize;
			j++;
		}
		memSize *= 2;
		head = 0;
		tail = j;
		delete[] data;
		data = new_data;
	}

public:
	Queue() : sz(0), memSize(10), head(0), tail(0){
		data = new T[memSize];
	}

	Queue(const Queue& q) {
		sz = q.sz;
		memSize = q.memSize;
		head = q.head;
		tail = q.tail;
		data = new T[memSize];
		memcpy(data, q.data, memSize * sizeof(T));
	}

	Queue& operator=(const Queue& q) {
		if (this != &q) {
			sz = q.sz;
			memSize = q.memSize;
			head = q.head;
			tail = q.tail;
			delete[] data;
			data = new T[memSize];
			memcpy(data, q.data, memSize * sizeof(T));
		}
		return *this;
	}

	~Queue() {
		delete[] data;
	}

	size_t size() const {
		return sz;
	}

	bool isEmpty() {
		return sz == 0;
	}

	bool isFull() {
		return sz == memSize;
	}

	void push(const T& elem) {
		if (sz == memSize) {
			repack();
		}
		data[tail] = elem;
		tail = (tail + 1) % memSize;
		sz++;
	}

	T pop() {
		if (sz == 0) {
			throw "Can't pop from empty queue";
		}
		T ret = data[head];
		head = (head + 1) % memSize;
		sz--;
		return ret;
	}

	bool operator==(const Queue& q) const {
		if (sz != q.sz) {
			return false;
		}
		size_t i = head, j = q.head;
		bool flag;
		while (i != tail) {
			flag = q.data[j] == data[i];
			if (!flag) {
				break;
			}
			i = (i + 1) % memSize;
			j = (j + 1) % memSize;
		}
		flag = j == q.tail;
		return flag;
	}

	void clear() {
		sz = 0;
		head = 0;
		tail = 0;
		delete[] data;
		data = new T[memSize];
	}
};