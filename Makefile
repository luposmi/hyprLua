SOURCE_FILES=$(wildcard *.cpp *.hpp)

all:
	$(CXX) -shared -fPIC $(SOURCE_FILES)  -o hyprLua.so -I/usr/include/lua5.3 -llua5.3 -I/usr/include/hyprland/wlroots-hyprland -g `pkg-config --cflags pixman-1 libdrm hyprland` -std=c++2b -DWLR_USE_UNSTABLE
