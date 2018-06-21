; ModuleID = 'Go2LLVM module'

@g = internal global i32 0
@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.1 = private unnamed_addr constant [5 x i8] c"end\0A\00"

define void @main() {
"main entrypoint":
  store i32 55, i32* @g
  %i.addr = alloca double
  store double 3.300000e+01, double* %i.addr
  %i = load double, double* %i.addr
  %g = load i32, i32* @g
  %0 = sitofp i32 %g to double
  %binaryFAdd = fadd double %i, %0
  %binaryFAdd1 = fadd double %binaryFAdd, 3.000000e+00
  %binaryFAdd2 = fadd double %binaryFAdd1, 1.000000e+00
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), double %binaryFAdd2)
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.1, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
