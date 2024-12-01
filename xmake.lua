set_project("WCompiler")
set_version("0.1.0")

add_rules("mode.debug", "mode.release")

includes("xmake/env.lua")
local llvm_install_dir = get_llvm_install_dir_from_path()
local llvm_header_dir = llvm_install_dir .. "/include"
local llvm_lib_dir = llvm_install_dir .. "/lib"

target("Compiler")
    -- llvm part
    add_includedirs(llvm_header_dir, "include/")
    add_linkdirs(llvm_lib_dir)
    add_links("ntdll")
    add_links(llvm_lib_dir .. "/*.lib")
    -- set languages
    set_languages("cxx20")
    -- other settings
    set_kind("binary")
    add_files("src/*.cpp")
    add_headerfiles("include/*.h")
