# sipc

This is a compiler from SIP to LLVM bitcode, extended from the [tipc](https://github.com/matthewbdwyer/tipc) project.
SIP is a "Simple Imperative Programming" language.
Linking the compiled bitcode with the [runtime library](https://github.com/ne0kai/sipc/tree/main/rtlib) routines and standard libraries will produce an executable.

Essentially, SIP extends TIP with:
1. New data types (Boolean, arrays)
2. New expressions (relational, ternary, array)
3. New statements (inc/dec, for)

The detailed work done is recorded in [report](https://github.com/ne0kai/sipc/tree/main/report).

Acknowledgments: Thanks to CS-4620 Fall 2023 course staff at University of Virginia for providing project description, `tipc` codebase and grading.
Thanks to my teammate for the collaboration in development.
