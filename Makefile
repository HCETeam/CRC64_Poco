NAME = test_app
#------------------------------------
C++11_FLAGS = -std=c++11 
#------------------------------------
# poco library
POCO_LIBS =  -lPocoFoundation
#------------------------------------
CEXTRA = -fomit-frame-pointer -mfpmath=sse -ffast-math 
CFLAGS =  -Wall -Wno-deprecated -ggdb3 -pipe -fexceptions $(C++11_FLAG)
LIBS =  -lpthread -lstdc++ `cppunit-config --libs` $(POCO_LIBS)
INCLUDE = -I./user/local/include -I./Include -I./Tests/Include -I./CppUnit/Include -I./testsuite/src
CC = g++
OBJ_DIR := ./Obj/
source_dirs := ./Source  ./Tests ./Tests/Source ./testsuite/src ./CppUnit/Source
search_wildcards := $(addsuffix /*.cpp,$(source_dirs))
first: all
all: $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards)))))
	@echo Linking..
	@$(CC) $^ $(LIBS) -o $(NAME) 
VPATH := $(source_dirs)
$(OBJ_DIR)%.o: %.cpp
	@echo -e CC\\t $(notdir $<)
	@$(CC)  $(CFLAGS) -c -MMD -MF $(OBJ_DIR)$(notdir $(patsubst %.cpp,%.d,$<))  $(addprefix -I ,$(source_dirs)) $(INCLUDE)  $< -o $(OBJ_DIR)$(notdir $(patsubst %.cpp,%.o,$<))

include $(wildcard $(OBJ_DIR)*.d)

clean:
	rm -Rf $(NAME) $(OBJ_DIR)*.o $(OBJ_DIR)*.d tags
