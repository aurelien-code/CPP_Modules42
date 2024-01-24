#include <string>

class Transform {
	private:
		std::string _s1;
		std::string _s2;
		std::string _file_path;
		
		std::string _replace_in_line(std::string line);
	public:
		Transform(std::string s1, std::string s2, std::string file_path);
		~Transform();
		void replace(void);
};