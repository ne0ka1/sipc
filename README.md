# sipc 编译器

`sipc` 项目是一个 SIP 语言的编译器，基于 [tipc](https://github.com/matthewbdwyer/tipc) 项目扩展开发。
[TIP](https://github.com/cs-au-dk/TIP/) 是用于静态代码分析研究的一种命令式编程语言，SIP 在其基础上增加了一些新的语言特性。

此编译器能够将 SIP 代码生成 [LLVM](https://llvm.org) 位代码，并可与标准库和运行时库 ([rtlib](rtlib)) 链接生成可执行文件。

## 🎯 项目目标

SIP 在 TIP 语言基础上增加了以下功能：
- **新数据类型**：布尔类型、数组。
- **新表达式**：关系表达式、三元表达式、数组表达式。
- **新语句**：自增/自减 (`++`, `--`) 及 `for` 循环。

## 📦 项目结构

`sipc` 编译器遵循经典设计，由以下四部分组成：

- [前端](src/frontend)：处理解析、AST（抽象语法树）构建、格式化输出。
- [语义分析](src/semantic)：执行类型检查、符号解析，确保 SIP 代码合法。
- [代码生成](src/codegen)：将 AST 转换为 LLVM 位代码，生成`.bc`文件。
- [优化](src/optimizer)：运行数个 LLVM 优化遍以提升位代码。

## 📚 致谢

本项目由是弗吉尼亚大学 (University of Virginia) CS-4620 课程（2023 年秋季学期）的一部分。特别感谢课程团队提供的项目描述、原始 `tipc` 代码库及评分支持。
