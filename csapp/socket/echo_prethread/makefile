#Makefile
CXX = g++

SRCS_SERVER = echoserver.cpp ../Condition.cpp ../MutexLock.cpp ../Rio.cpp ../SocketBase.cpp ../ThreadBase.cpp

SRCS_CLIENT = echoclient.cpp ../Rio.cpp ../SocketBase.cpp

LIBS =

FLAGS = -I../

OBJS = $(SRCS:.cpp=.o)

EXECUTABLE_SERVER = echoserver
EXECUTABLE_CLIENT = echoclient

all:
	$(CXX) -Wall -o $(EXECUTABLE_SERVER) $(SRCS_SERVER) $(FLAGS) $(LIBS) -lpthread
	$(CXX) -Wall -o $(EXECUTABLE_CLIENT) $(SRCS_CLIENT) $(FLAGS) $(LIBS)

.PHONY:clean

clean:
	rm $(OBJS) $(EXECUTABLE_SERVER) $(EXECUTABLE_CLIENT)
