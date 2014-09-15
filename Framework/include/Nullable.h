#ifndef NULLABLE
#define NULLABLE

template<typename T>
struct Nullable
{
	Nullable(const T& v)
	: val(new T(v))
	{}

	T Value()
	{
		if (HasValue())
		{
			return std::move(*val);
		}
		else
		{
			throw std::runtime_error("Attempted to access null pointer");
		}
	}
	bool HasValue()
	{
		return val != nullptr;
	}

	operator T()
	{
		return Value();
	}


private:
	std::unique_ptr<T> val;
};


#endif