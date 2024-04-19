#pragma once
#include <iostream>
#include <memory>

class BaseAST {
    public:
     virtual ~BaseAST() = default;
     virtual void DumpAST() const = 0;

     virtual void Dump() const = 0;


};


class CompUnit:public BaseAST {
    public:
    std::unique_ptr<BaseAST> func_def;

    void DumpAST() const override {
        std::cout << "CompUnitAST { ";
        func_def->DumpAST();
        std::cout << " }";
    }

    void Dump() const override {
        func_def->Dump();
    }
};

class FuncDefAST:public BaseAST {
    public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;

    void DumpAST() const override {
        std::cout << "FuncDefAST { ";
        func_type->DumpAST();
        std::cout << ", " << ident << ", ";
        block->DumpAST();
        std::cout << " }";
    }

    void Dump() const override {
        std::cout << "fun ";
        std::cout << "@" << ident << "(): ";
        func_type->Dump();
        std::cout << "{ " << std::endl;
        block->Dump();
        std::cout << "} " << std::endl;
    }

};

class FuncTypeAST:public BaseAST {
    public:
    std::string func_type = "int";

    void DumpAST() const override {
        std::cout << "FuncTypeAST { ";
        std::cout << func_type;
        std::cout << " }";
    }

    void Dump() const override {
        std::cout << "i32" << " ";
    }
};

class BlockAST :public BaseAST {
    public:
    std::unique_ptr<BaseAST> stmt;

    void DumpAST() const override {
        std::cout << "BlockAST { ";
        stmt->DumpAST();
        std::cout << " }";
    }

    void Dump() const override {
        std::cout << "\%entry" << ": " << std::endl;
        stmt->Dump();
        std::cout << std::endl;
    }
};

class StmtAST:public BaseAST {
    public:
    int number;

    void DumpAST() const override {
        std::cout << "StmtAST { ";
        std::cout<<number;
        std::cout << " }";
    }

    void Dump() const override {
        std::cout << "  ret ";
        std::cout << number;
    }
};


