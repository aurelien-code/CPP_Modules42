#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		struct LevelFunc {
			std::string level;
			void (Harl::*func)();
		};
		
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};