
define void @flow(i32, i32, i32) {
	%a = alloca i32
	store i32 %0, i32* %a
	%b = alloca i32
	store i32 %1, i32* %b
	%c = alloca i32
	store i32 %2, i32* %c
	%4 = load i32, i32* %a
	%5 = icmp sgt i32 %4, 0
	br i1 %5, label %then1, label %else1
then1:
	%6 = load i32, i32* %b
	%7 = icmp sgt i32 %6, 0
	br i1 %7, label %then2, label %else2
then2:
	%8 = load i32, i32* %c
	%9 = icmp sgt i32 %8, 0
	br i1 %9, label %then3, label %else3
then3:
	%10 = call i32 @puts(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.1, i32 0, i32 0))
	br label %ifcont3
else3:
	%11 = call i32 @puts(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i32 0, i32 0))
	br label %ifcont3
ifcont3:
	br label %ifcont2
else2:
	%12 = load i32, i32* %c
	%13 = icmp sgt i32 %12, 0
	br i1 %13, label %then4, label %else4
then4:
	%14 = call i32 @puts(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i32 0, i32 0))
	br label %ifcont4
else4:
	%15 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.4, i32 0, i32 0))
	br label %ifcont4
ifcont4:
	br label %ifcont2
ifcont2:
	br label %ifcont1
else1:
	%16 = load i32, i32* %b
	%17 = icmp sgt i32 %16, 0
	br i1 %17, label %then5, label %else5
then5:
	%18 = load i32, i32* %c
	%19 = icmp sgt i32 %18, 0
	br i1 %19, label %then6, label %else6
then6:
	%20 = call i32 @puts(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.5, i32 0, i32 0))
	br label %ifcont6
else6:
	%21 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.6, i32 0, i32 0))
	br label %ifcont6
ifcont6:
	br label %ifcont5
else5:
	%22 = load i32, i32* %c
	%23 = icmp sgt i32 %22, 0
	br i1 %23, label %then7, label %else7
then7:
	%24 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.7, i32 0, i32 0))
	br label %ifcont7
else7:
	%25 = call i32 @puts(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.8, i32 0, i32 0))
	br label %ifcont7
ifcont7:
	br label %ifcont5
ifcont5:
	br label %ifcont1
ifcont1:
	ret void
}

define i32 @main(i32, i8**) {
	%3 = sub i32 0, 1
	%4 = sub i32 0, 1
	%5 = sub i32 0, 1
	call void @flow(i32 %3, i32 %4, i32 %5)
	ret i32 0
}
@.str.1 = private unnamed_addr constant [6 x i8] c"all p\00"
@.str.2 = private unnamed_addr constant [6 x i8] c"c not\00"
@.str.3 = private unnamed_addr constant [6 x i8] c"b not\00"
@.str.4 = private unnamed_addr constant [12 x i8] c"b and c not\00"
@.str.5 = private unnamed_addr constant [6 x i8] c"a not\00"
@.str.6 = private unnamed_addr constant [12 x i8] c"a and c not\00"
@.str.7 = private unnamed_addr constant [12 x i8] c"a and b not\00"
@.str.8 = private unnamed_addr constant [8 x i8] c"all not\00"
declare dso_local i32 @puts(i8*)
