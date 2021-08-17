template<class T>
class Auto_ptr5
{
	T* m_ptr;
public:
	Auto_ptr5(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
 
	~Auto_ptr5()
	{
		delete m_ptr;
	}
 
	Auto_ptr5(const Auto_ptr5& x) = delete;
 
	Auto_ptr5(Auto_ptr5&& x)
		: m_ptr(x.m_ptr)
	{
		x.m_ptr = nullptr;
	}
 
	Auto_ptr5& operator=(const Auto_ptr5& x) = delete;
 
	Auto_ptr5& operator=(Auto_ptr5&& x)
	{
		if (&x == this)
			return *this;
 
		delete m_ptr;
 
		m_ptr = x.m_ptr;
		x.m_ptr = nullptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
