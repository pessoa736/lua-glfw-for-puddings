---@meta lgfp
---@module "lgfp"
---@autor Davi passos / pessoa736 / xpudding
---
---@class lgfpLibDef
--- lua glfw for puddings
local lgfp = {}



---@class LuaWindows: userdata
---@field ShouldClose fun(self: LuaWindows):boolean
---@field MakeCurrentContext fun(self: LuaWindows)


---@class lgfpWindowManagerLibDef: table, metatable
lgfp.WindowManager = {}



---@param width integer
---@param height integer
---@param title string
---@return LuaWindows
lgfp.WindowManager.CreateWindows = function (width, height, title) end


return lgfp