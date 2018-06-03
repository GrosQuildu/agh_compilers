; ModuleID = 'Go2LLVM module'

define void @main() {
"main entrypoint":
  %call_test1 = call i32 @test1(i32 3)
  %i.addr = alloca i32
  store i32 %call_test1, i32* %i.addr
  ret void
}

define i32 @test1(i32 %a) {
"test1 entrypoint":
  %a.addr = alloca i32
  store i32 %a, i32* %a.addr
  ret i32 4
}
