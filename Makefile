# OMPL_DIR is the installation prefix for OMPL.
# YOU MUST CHANGE THIS VARIABLE depending on your installation!
# /usr for the virtual machine and deb packages
# /usr/local for install script
# /opt/local for OS X using MacPorts
OMPL_DIR=/usr

# Compilation flags
CXX_FLAGS=-std=c++11 -O2
# Change the -O2 flag to -g -O0 when debugging code, -O2 is for optimization.
# -g allows you to use tools like gdb to analyze your code.

# Include directories
INCLUDE_FLAGS=-I${OMPL_DIR}/include
# Linker options
#LD_FLAGS=-L${OMPL_DIR}/lib -lompl -Wl,-rpath ${OMPL_DIR}/lib
LD_FLAGS=-L${OMPL_DIR}/lib -lompl -lompl_app_base  -lompl_app -lboost_program_options

# The c++ compiler to invoke
CXX=c++

all:	RT project3 Benchmark

clean:
	rm -f *.o
	rm -f RT
	rm -f project3
	rm -f Benchmark
project3: RT.o project3.o CollisionChecking.o
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -o project3 project3.o CollisionChecking.o RT.o  $(LD_FLAGS)

RT: RT.o MyRigidBodyPlanning.o CollisionChecking.o
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -o RT MyRigidBodyPlanning.o CollisionChecking.o RT.o  $(LD_FLAGS)

Benchmark: RT.o Benchmark.o CollisionChecking.o
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -o Benchmark Benchmark.o CollisionChecking.o RT.o  $(LD_FLAGS)

%.o: %.cpp
	$(CXX) -c $(CXX_FLAGS) $(INCLUDE_FLAGS) $< -o $@
