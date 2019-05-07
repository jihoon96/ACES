	.syntax unified
	.cpu cortex-m4
	.thumb

.global g_vectors // g_vector prototype
.global Reset_Handler

	.section	.isr_vector,"a",%progbits
	.type		g_vectors, %object // inserted in object code
	.size		g_vectors, .-g_vectors

g_vectors: 
	.word	_estack //_estack
	.word	Reset_Handler
	.word	0 // NMI_Handler
	.word	0 // HardFault_Handler
	.word	0 // MemManage_Handler
	.word	0 // BusFault_Handler
	.word 	0 // UsageFault_Handler
	.word 	0
	.word	0
	.word	0
	.word	0
	.word	0 // SVC_Handler
	.word	0 // DebugMon_Handler
	.word	0
	.word	0 // PenSV_Handler
	.word	SysTick_Handler
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0


Reset_Handler:
	bl main

SysTick_Handler:

/*NMI_Handler:
	subroutine here
*/