package.cpath =  "./build/?.so;" .. package.cpath

local lgfp = require("lgfp")
local winman = lgfp.WindowManager

local win = winman.CreateWindows(800, 600, "teste de criação de function")

if win:ShouldClose() then
    print("close window")
end

print(win)