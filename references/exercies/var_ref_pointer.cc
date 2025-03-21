int main() {
  int i = 1;
  int &&r = 1;
  int *p = &i;
}

// Observations:
//
// 1. Without optimizations (-O0):
//    - All variables (`i`, `r`, `p`) are present in the assembler output.
//    - `r` is treated as a separate entity bound to the temporary value `1`.
//
// 2. With optimizations (-O2):
//    - If `r` and `p` are unused, they are optimized out.
//    - Only `i` remains in the assembler output if it is used.
//
// 3. Difference between `i` and `r`:
//    - `i` is a regular variable stored in memory.
//    - `r` is an rvalue reference bound to a temporary value.
//    - Both hold the same value (`1`) in this program.
