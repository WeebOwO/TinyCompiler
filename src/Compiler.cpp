#include "Compiler.h"

#include <system_error>

#include "llvm/Support/raw_ostream.h"

namespace wind 
{
    Compiler::Compiler() 
    {
        m_Context = std::make_unique<llvm::LLVMContext>();
        m_Module = std::make_unique<llvm::Module>("wind", *m_Context);
        m_Builder = std::make_unique<llvm::IRBuilder<>>(*m_Context);
    }

    void Compiler::Execute(const std::string& code)
    {
        SaveModuleToFile();
    };

    Compiler::~Compiler() 
    {
        
    }

    void Compiler::SaveModuleToFile()
    {
        std::error_code error;
        llvm::raw_fd_ostream file("output.ll", error); 
        m_Module->print(file, nullptr);
    }
}