#pragma once

#include <string>
#include <memory>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

namespace wind 
{
    class Compiler
    {
    public:
        Compiler();
        ~Compiler();

        void Execute(const std::string& code);

    private:
        void SaveModuleToFile();

        std::unique_ptr<llvm::LLVMContext> m_Context;
        std::unique_ptr<llvm::Module> m_Module;
        std::unique_ptr<llvm::IRBuilder<>> m_Builder;
    };
}