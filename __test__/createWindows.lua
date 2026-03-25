package.cpath =  "./build/?.so;" .. package.cpath

local lgfp = require("lgfp")


if (lgfp.Init()) then

    local winman = lgfp.WindowManager

    local win = winman.CreateWindows(600, 400, "teste de criação de function")
    
    if not win then
        lgfp.Terminate()
        error("Creation Windows failed")
    end

    win:MakeContextCurrent()

    while not win:ShouldClose() do
        print("close window")
    end


    print(win, type(win), win:GetWidth(), win:GetHeight(), win:GetTitle())
    
    lgfp.Terminate()
end