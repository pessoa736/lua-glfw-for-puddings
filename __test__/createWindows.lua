package.cpath =  "./build/?.so;" .. package.cpath

local lgfp = require("lgfp")

print(lgfp.IsInitialized())
if not lgfp.IsInitialized() then print(" no started lgfp "); os.exit() end


local win = lgfp.CreateWindows(800, 600, "teste de criação de function")

if not win then error("failed to create windows") end
print(win)