; ModuleID = 'Go2LLVM module'

@g = internal global i32 0
@global_str = private unnamed_addr constant [4 x i8] c"ok\0A\00"
@global_str.1 = private unnamed_addr constant [3 x i8] c"2\0A\00"
@global_str.2 = private unnamed_addr constant [3 x i8] c"3\0A\00"
@global_str.3 = private unnamed_addr constant [4 x i8] c"%f\0A\00"
@global_str.4 = private unnamed_addr constant [5 x i8] c"end\0A\00"

define void @main() {
"main entrypoint":
  store i32 55, i32* @g
  %i.addr = alloca double
  store double 3.300000e+01, double* %i.addr
  %i = load double, double* %i.addr
  %binaryFAdd = fadd double 1.000000e+00, %i
  %binaryFCmp = fcmp oeq double %binaryFAdd, 3.300000e+01
  br i1 %binaryFCmp, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0))
  br label %merge9

else:                                             ; preds = %"main entrypoint"
  %i1 = load double, double* %i.addr
  %binaryFMul = fmul double %i1, 3.000000e+00
  %binaryFMul2 = fmul double %binaryFMul, 3.000000e+00
  %g = load i32, i32* @g
  %0 = sitofp i32 %g to double
  %binaryFMul3 = fmul double %binaryFMul2, %0
  %binaryFCmp4 = fcmp oeq double %binaryFMul3, 1.633500e+04
  br i1 %binaryFCmp4, label %if5, label %else7

if5:                                              ; preds = %else
  %call_printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_str.1, i32 0, i32 0))
  br label %merge

else7:                                            ; preds = %else
  %call_printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_str.2, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else7, %if5
  br label %merge9

merge9:                                           ; preds = %merge, %if
  %i10 = load double, double* %i.addr
  %binaryFMul11 = fmul double %i10, 3.000000e+00
  %binaryFMul12 = fmul double %binaryFMul11, 3.000000e+00
  %g13 = load i32, i32* @g
  %1 = sitofp i32 %g13 to double
  %binaryFMul14 = fmul double %binaryFMul12, %1
  %call_printf15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.3, i32 0, i32 0), double %binaryFMul14)
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.4, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
