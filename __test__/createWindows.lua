package.cpath =  "./build/?.so;" .. package.cpath

local lgfp = require("lgfp")

local win = lgfp.WindowManager.CreateWindows(800, 600, "teste de criação de function")

if win:ShouldClose() then
    print("close window")
end

print(win)