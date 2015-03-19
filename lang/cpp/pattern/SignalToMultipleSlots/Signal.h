//
// V 0.1
//

#include<vector>
#include<algorithm>


namespace ami
{
	template<class function>
		class signal
		{

			std::vector<function> _list;
			public:

			void connect(function func)
			{
				_list.push_back(func);
			}

			void operator()()
			{
				for(int i =0;i<_list.size();++i)
					_list[i]();
			}

		};


}
