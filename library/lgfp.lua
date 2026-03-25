---@meta lgfp
---@module "lgfp"
---@autor Davi passos / pessoa736 / xpudding
---
---@class lgfpLibDef
--- lua glfw for puddings
local lgfp = {}

---It starts GLFW and returns the initialization result.
---@return boolean 
lgfp.Init = function ()end

---turn off ther GLFW
lgfp.Terminate = function () end


---@class LuaWindows: userdata
---@field ShouldClose fun(self: LuaWindows):boolean
---@field MakeContextCurrent fun(self: LuaWindows)
---@field GetWidth fun(self: LuaWindows):integer
---@field GetHeight fun(self: LuaWindows):integer
---@field GetTitle fun(self: LuaWindows):string 


---@class lgfpWindowManagerLibDef: table, metatable
lgfp.WindowManager = {}



---@param width integer
---@param height integer
---@param title string
---@return LuaWindows
lgfp.WindowManager.CreateWindows = function (width, height, title) end


return lgfp