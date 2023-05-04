.data
	double: .double 1.23456
	zero: .double 0.0
	
.text	
	
	li $v0,3
	ldc1 $f12, double
	syscall
