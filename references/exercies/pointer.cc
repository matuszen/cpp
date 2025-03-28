void foo(const int &x) {
  int y = x;
}

int main() {
  int x;
  foo(x);
}

// Output:
// The reference is not optimized out
// 
// main()
// leaq	-12(%rbp), %rax
// movq	%rax, %rdi
// call	_Z3fooRKi
//
// foo()
// movq	%rdi, -24(%rbp)
// movq	-24(%rbp), %rax
// movl	(%rax), %eax
// movl	%eax, -4(%rbp)