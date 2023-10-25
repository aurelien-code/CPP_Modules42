# Variables
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
TARGET = megaphone
SRC = $(TARGET).cpp

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

fclean:
	rm -f $(TARGET)

re: fclean all