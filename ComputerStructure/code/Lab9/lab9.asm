		lui 	$a0, 0xe000
		#addi	$a0, $a0, 0x00000060
		add	$s0, $0, $0
		addi	$s1, $0, 0x0000005c
		addi	$s2, $0, 28 #第一个循环的界
		addi	$s3, $0, 32

		#初始化输出20183086
		addi	$s4, $0, 32 #store address
		add	$t7, $0, $0 #暂存保存的数据
		addi	$t8, $0, -4 #作为取数据的索引。初始化为-4
start:		addi	$t8, $t8, 4
		sll	$t7, $t7, 4
		lw	$t9, 0($t8)
		or	$t7, $t7, $t9
		bne	$t8, $s2, start #t8 == 28,说明已经取到最后一个数字
		sw	$t7, 0($s4) #20183086进入[32]
		addi	$s4, $s4, 4 #store address == 36

		add	$t0, $0, $0	# i = 0
outloop:	beq	$t0, $s2, print
		addi	$t1, $t0, 4	# j = i + 4
		addi	$t0, $t0, 4
inloop:		beq	$t1, $s3, outloop
		lw	$t3, -4($t0)	# $t3 = a[i]
		lw	$t4, 0($t1)	# $t4 = a[j]
		slt	$t2, $t3, $t4	# if (a[i] < a[j]) swap
		addi	$t1, $t1, 4
		beq	$t2, $0, inloop
		sw	$t3, -4($t1)
		sw	$t4, -4($t0)

		#交换完之后需要存储新的
		addi	$t8, $0, -4 #作为取数据的索引。初始化为-4
store:		addi	$t8, $t8, 4
		sll	$t7, $t7, 4
		lw	$t9, 0($t8)
		or	$t7, $t7, $t9
		bne	$t8, $s2, store #t8 == 28,说明已经取到最后一个数字
		sw	$t7, 0($s4) 
		addi	$s4, $s4, 4 #store address == 36	
		j	inloop
		
print:		addi	$t5, $s3, -4    #28
printloop:	addi	$t5, $t5, 4	# at first 32...
		lw	$t6, 0($t5)
		sw	$t6, 0($a0)
		bne	$t5, $s1, printloop
		j	print
	
