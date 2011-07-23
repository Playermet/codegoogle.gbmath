

namespace gb
{
	namespace color
	{
	
	template <typename T>
	class bitmap {
	public:
	
		bitmap() : _num_columns(0), _num_rows(0)
		{
		
		}
		
		bitmap(size_t num_columns,  size_t num_rows) :  _num_columns(num_columns), 
														_num_rows(num_rows)
		{
			_data.reserve(_num_columns * num_rows);
		}
		
		
		~bitmap()
		{
			_data.clear();
		}
		
		void fill(const T& value)
		{
			T* pdata = &_data[0];
			for(size_t c=0;c<_num_rows;c++)
			{
				for(size_t j=0;j<_num_rows;j++)
				{
					*pdata[c*j] = value; 
				}
			}
		}
		
		inline T& at(int column, int row)
		{
			if( ((size_t)column>=_num_columns) || ((size_t)_num_rows>=row) )
			{
				throw std::runtime_error_xxx("bad index");
			}
			
			T& res = &_data[0] + ,,,,,;
			return res;
		}
		
	private:
		size_t _num_rows;
		size_t _num_columns;
		std::vector<T> _data;
	
	
	
	};
	
	
	
	
	}


}

template <>