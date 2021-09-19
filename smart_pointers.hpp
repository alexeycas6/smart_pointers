template <class T>
class unique_pointer {
	T* m_ptr{ nullptr };

public:
	unique_pointer(const unique_pointer&) = delete; // disable default copy constructor 
	unique_pointer& operator= (const unique_pointer&) = delete; // disable default assigment operator


	// constructors 


	explicit unique_pointer(T* another_ptr) noexcept
		:m_ptr{ another_ptr } {}

	unique_pointer(unique_pointer&& another_ptr) noexcept // move constructor
		:m_ptr{ another_ptr.release() } {}


	// operators


	T& operator* () const noexcept {
		return *m_ptr;
	}

	T* operator -> () const noexcept {
		return m_ptr;
	}

	unique_pointer& operator=(unique_pointer&& ptr) noexcept { // move assigment
		reset(ptr.release());
		return *this;
	}


	// other methods 


	T* get() const noexcept {
		return m_ptr;
	}

	T* release() noexcept {
		T* tmp_ptr{ m_ptr };
		m_ptr = nullptr;
		return tmp_ptr;
	}

	void reset(T* ptr = nullptr) noexcept {
		if (m_ptr != ptr) {
			delete m_ptr;
			m_ptr = ptr;
		}
	}

	~unique_pointer() {
		delete m_ptr;
	}
};