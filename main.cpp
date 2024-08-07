#include <hyprland/src/plugins/PluginAPI.hpp>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

inline HANDLE PHANDLE = nullptr;

// Do NOT change this function.
APICALL EXPORT std::string PLUGIN_API_VERSION() {
    return HYPRLAND_API_VERSION;
}

void init(){
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);

    //if (luaL_dofile(state, "/home/main/.config/hypr/init.lua") == LUA_OK) {
    //    lua_pop(state, lua_gettop(state));
    //}


    lua_close(state);
}
APICALL EXPORT PLUGIN_DESCRIPTION_INFO PLUGIN_INIT(HANDLE handle) {
    PHANDLE = handle;
    const std::string HASH = __hyprland_api_get_hash();
    // ALWAYS add this to your plugins. It will prevent random crashes coming from
    // mismatched header versions.
    if (HASH != GIT_COMMIT_HASH) {
        HyprlandAPI::addNotification(PHANDLE, "HyprLua Mismatched headers! Can't proceed.",
                                     CColor{1.0, 0.2, 0.2, 1.0}, 5000);
        throw std::runtime_error("HyprLua Version mismatch");
    }

    lua_State *state = luaL_newstate();
    return {"HyprLua", "Lua integration for Hyprland API", "Luposmi", "0.0"};
}

APICALL EXPORT void PLUGIN_EXIT() {
}
