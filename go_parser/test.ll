; ModuleID = 'Go2LLVM module'

@g = internal global i64 0
@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  store i64 55, i64* @g
  %g = load i64, i64* @g
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i64 %g)
  %x.addr = alloca i64
  br i1 false, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  store i64 5, i64* %x.addr
  br label %merge10

else:                                             ; preds = %"main entrypoint"
  %x = load i64, i64* %x.addr
  %binaryCmp = icmp eq i64 %x, 1
  br i1 %binaryCmp, label %if1, label %else2

if1:                                              ; preds = %else
  store i64 6, i64* %x.addr
  br label %merge9

else2:                                            ; preds = %else
  %x3 = load i64, i64* %x.addr
  %binarySub = sub i64 %x3, 1
  %g4 = load i64, i64* @g
  %binarySub5 = sub i64 %g4, 56
  %binaryCmp6 = icmp eq i64 %binarySub, %binarySub5
  br i1 %binaryCmp6, label %if7, label %else8

if7:                                              ; preds = %else2
  store i64 7, i64* %x.addr
  br label %merge

else8:                                            ; preds = %else2
  store i64 8, i64* %x.addr
  br label %merge

merge:                                            ; preds = %else8, %if7
  br label %merge9

merge9:                                           ; preds = %merge, %if1
  br label %merge10

merge10:                                          ; preds = %merge9, %if
  %x11 = load i64, i64* %x.addr
  %call_printf12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.1, i32 0, i32 0), i64 %x11)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
