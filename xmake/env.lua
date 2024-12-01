-- get the llvm install dir from the os path
function get_llvm_install_dir_from_path()
    local dirs = os.getenv("PATH")
    dirs = dirs:split(";")
    for _, dir in ipairs(dirs) do
        if dir:find("LLVM") then
            local realdir = dir.sub(dir, 1, dir.find(dir, "bin") - 1)
            return realdir
        end
    end
end