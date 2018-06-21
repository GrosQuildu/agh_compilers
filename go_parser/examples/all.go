package examples

/*
** multiline comment
*/

// external functions
func sin(a float) float
func puts(a *int8) int32
func printf(a *int8, ...) int32

// func1 declaration
func func1(a int) int;

func func2(a int32, b, c float) float {
	return a+b+c;
}

func func3(counter int) {
	if counter > 0 {
		func3(counter-1);
	}
	printf("func3, counter %d\n", counter);
	return;
}

func main() {

	// basic variables
	var var1 int = 5;
	var var2 int7331 = 4444
	var var3 float = -66.11;
	var var4 float128 = 1234;
	printf("vars: %d, %d, %f, %a\n", var1, var2, var3, var4);

	// hex/oct
	var var5 int = 0x123;
	var var6 int = 0123;
	printf("vars2: %x %d\n", var5, var6);

	// pointers
	var ptr1 *int = &var1;
	*ptr1 = 66;
	printf("ptr: %d, %d\n", *ptr1, var1);
	// ptr1 = &var2; // can't do that, pointers' types must be exact

	// arithmetic
	puts("\narithmetic:");
	printf("%d\n", (1+2*341/4)%100 << 2 >> 1 & (11 | 2222 ^ 1));
	printf("%f\n", (1.1+2*341/4)%100.2);
	puts("");

	// branches
	puts("\nbranches:");
	if 12 == 12 {
		puts("12 == 12");
	}
	if 12 ==13 {
		puts("12 ==13");
	} else if 12 == 14 {
		puts("12 ==14");
	} else {
		puts("12 -> else");
	}

	if (12*2) >= 0 {
		puts("var1*var2*var3 <= 0");
	}

	// functions
	puts("\nfunctions:");
	var f1Input int = 0x515551111111111112835135512318263;
	var f1Result int = func1(f1Input);
	printf("f1(%d): %d\n", f1Input, f1Result)
	printf("f2(%d,%f,%f): %f\n", 1, 2.0, 3.0, func2(1,2.0,3));


	// recursion
	puts("\nrecursion:");
	func3(4);


	// scopes
	// scopes are defined by {}, for example
	{
		var a int = 1;
		{
			// var a = 2; // can't redeclare
			var b int = 2;
		}
		var b int = 3;  // that's ok, b from previous block is out of the current scope
	}

	// casting
	// auto-casting is supported, in ambiguous situations best possible casting is chosen
	// except on declarations (with 'var'), right-hand-side is always casted to variable in this situations
	// if casting loose precision, warning is shown
	var precFloat float = 123;
	var precInt int = precFloat;  // warning
	var precFloatSmall int8 = precInt // warning
	var precFloatBig float128 = precFloat; // no warning

	// string formating
	puts("string formatting:");
	puts("\x41\x42\x20");

	// statements ending
	// may be with newline or with semicolon ;

	puts("end");
	return;
}


// func1 definition
func func1(a int) int {
	return a / 12;
}