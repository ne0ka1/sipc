# Solution 5

We implemented Dead Code Elimination, Early Common Subexpression Elimination, Inline Pass, Loop Unrolling, and Merge Functions Pass and received effective results in the conducted tests. However, Correlated Value Propagation, Superword Level Parallelism Vectorizer, and Tail Call Elimination did not show effective results for the tests we wrote due to issues from previous deliverables. Another issue was the parameters in the `run` method. At least locally, I wasn't able to use functions that had a run method with more than two parameters which slowed implementation of this deliverable. For example, Inline Pass, `InlinerPass` looks like it would work, however I got this error:

`/sw/ubuntu-22.04/llvm/14.0.6/include/llvm/Transforms/IPO/Inliner.h:102:21: note: candidate: ‘llvm::PreservedAnalyses llvm::InlinerPass::run(llvm::LazyCallGraph::SCC&, llvm::CGSCCAnalysisManager&, llvm::LazyCallGraph&, llvm::CGSCCUpdateResult&)’ 102 | PreservedAnalyses run(LazyCallGraph::SCC &C, CGSCCAnalysisManager &AM, | ^~~ /sw/ubuntu-22.04/llvm/14.0.6/include/llvm/Transforms/IPO/Inliner.h:102:21: note: candidate expects 4 arguments, 2 provided make[2]`

To resolve this issue I used a wrapper called `ModuleInlinerWrapperPass`. Not all functions had wrappers however so I spent a lot of time reading through the documentation to find applicable functions given my bug. 

Below are my results:
For each optimization we first generated the unoptimized bitcode, then the optimized bitcode and read through the files to see the differences. However, before we could do that we copied over the optimization code from the new project 5 branch and changed the `tipc.cpp` file to build tip files with five new optimizations (lu, mfp, dce, ecse, and ilp):
for the unoptimized bitcode `./bin/build.sh --do --asm optimization_tests/...`
for the optimized bitcode `./bin/build.sh (--optimization) --asm optmization_tests/..`

### Dead Code Elimination (DCE)

- **Unoptimized Bitcode**: 
  - Contains much computation and variable allocation (`alloca`) not used in the final output.
- **Optimized Bitcode**: 
  - Streamlined, removing all unnecessary allocations and computations. Variables like `a`, `c`, `d`, `e`, `f`, `g`, `h`, `unused3` are eliminated.
- **Implication**: 
  - Effectively removes redundant code, reducing compiled code size and potentially improving execution time.
- **Unoptimized Code Line Count**: 125 lines
- **Optimized Code Line Count**: 42 lines
- **Difference**: Decrease of 83 lines

### Early Common Subexpression Elimination (EarlyCSE)

- **Unoptimized Bitcode**: 
  - Contains duplicate calculations, notably the repeated multiplication `i * 5`.
- **Optimized Bitcode**: 
  - Calculates `i * 5` once and reuses the result (`reass.mul`).
- **Implication**: 
  - Successfully identifies and eliminates redundant calculations, streamlining code and potentially improving performance.
- **Unoptimized Code Line Count**: 70 lines
- **Optimized Code Line Count**: 38 lines
- **Difference**: Decrease of 32 lines

### Inline Pass

- **Unoptimized Bitcode**: 
  - The `multiplyByTwo` function is separate, with function calls made to it.
- **Optimized Bitcode**: 
  - `multiplyByTwo` is inlined; operations are performed directly in the `@_tip_main` function.
- **Implication**: 
  - Reduces function call overhead, which is significant in loops or frequently called functions.
- **Unoptimized Code Line Count**: 115 lines
- **Optimized Code Line Count**: 71 lines
- **Difference**: Decrease of 44 lines

### Loop Unrolling

- **Unoptimized Bitcode**: 
  - Simple loop structure with conditional branching and sequential execution.
- **Optimized Bitcode**: 
  - Multiple instances of the loop body executed sequentially in a single iteration.
- **Implication**: 
  - Increases code size but may improve performance by reducing loop control overhead and increasing cache efficiency.
- **Unoptimized Code Line Count**: 75 lines
- **Optimized Code Line Count**: 99 lines
- **Difference**: Increase of 24 lines

### Merge Function Pass

- **Unoptimized Bitcode**: 
  - Two separate but identical functions, `foo` and `bar`.
- **Optimized Bitcode**: 
  - Function merging demonstrated. `foo` is modified to call `bar` directly.
- **Implication**: 
  - Reduces code redundancy and size by merging identical functions, effective in scenarios with code duplication.
- **Unoptimized Code Line Count**: 95 lines
- **Optimized Code Line Count**: 40 lines
- **Difference**: Decrease of 55 lines

---

### Summary

The applied optimizations lead to significant improvements in code efficiency and size:

- **Dead Code Elimination** and **EarlyCSE** remove redundant operations.
- **Inlining** eliminates function call overhead.
- **Loop Unrolling** reduces loop control overhead.
- **Merge Function Pass** consolidates identical functions, reducing duplication.

