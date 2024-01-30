NAME = NowWeAreTalking

# Source files
SOURCE_FOLDER = src/
SOURCE_FILES = main.cpp\
               Fixed.cpp

SOURCES = $(addprefix $(SOURCE_FOLDER), $(SOURCE_FILES))

# Objects
OBJECTS= $(SOURCE_FILES:.cpp=.o)
# OBJECTS = $(addprefix $(OBJECT_FOLDER), $(OBJECT_FILES))

# Headers
HEADERS_FOLDER	= include/

# Flags and output
CXXFLAGS = -Wall -Wextra -Werror -Wno-c++0x-compat -std=c++98

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME): $(OBJECTS)
	@echo "🚧 Compiling binary... 🚧"
	@c++ $(OBJECTS) -o $(NAME)
	@echo "✅ Done!"

#objects
$(OBJECTS):
	@echo "🚧 Compiling objects... 🚧"
	@c++  -c $(SOURCES) $(CXXCFLAGS) -I$(HEADERS_FOLDER)
	@echo "✅ Done!"
# Rule to remove object files
clean:
	@echo "🧹 Deleting objects..."
	@rm -f $(OBJECTS)
	@echo "✅ Done!"
# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	@rm -f $(NAME)
	@echo "Deleted binary $(NAME)"

# Rule to remove object files and binary, then re-build everything
re:	fclean all

# Rule to test norminette
normi:	
	@cpplint --root=include $(SOURCES) $(HEADERS_FOLDER)*

# Rule to debug, include norminette and similars
test: re
	@echo "⚡️Binary execution⚡️\n"
	@./$(NAME)
	@echo "\n🛡️Valgrind execution🛡️\n"
	@valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--verbose \
	--log-file=leaks.$(NAME).txt \
	./$(NAME) 
	@echo "\n📚Valgrind summary📚\nCheck leaks.$(NAME).txt for a detailed report."
	@cat leaks.$(NAME).txt | grep 'ERROR SUMMARY'
