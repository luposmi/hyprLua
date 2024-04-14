SOURCE_FILES=$(wildcard *.cpp *.hpp)

all:
	$(CXX) -shared -fPIC $(SOURCE_FILES)  -o hyprLua.so -g `pkg-config --cflags pixman-1 libdrm hyprland` -std=c++2b
