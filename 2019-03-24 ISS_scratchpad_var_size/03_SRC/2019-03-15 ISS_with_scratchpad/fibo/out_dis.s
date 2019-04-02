
out.elf:     file format elf32-littlearm


Disassembly of section .init:

0800018c <_init>:
 800018c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800018e:	bf00      	nop

Disassembly of section .fini:

08000190 <_fini>:
 8000190:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000192:	bf00      	nop

Disassembly of section .text.main:

08000194 <main>:
int main(void)
{
 8000194:	b480      	push	{r7}
 8000196:	b087      	sub	sp, #28
 8000198:	af00      	add	r7, sp, #0
	int f1=0, f2=1, f3, i; // initialize
 800019a:	2300      	movs	r3, #0
 800019c:	617b      	str	r3, [r7, #20]
 800019e:	2301      	movs	r3, #1
 80001a0:	613b      	str	r3, [r7, #16]
	int n = 10;
 80001a2:	230a      	movs	r3, #10
 80001a4:	60bb      	str	r3, [r7, #8]

	for( i=0; i<n-2; i++)
 80001a6:	2300      	movs	r3, #0
 80001a8:	60fb      	str	r3, [r7, #12]
 80001aa:	e00a      	b.n	80001c2 <main+0x2e>
	{
		f3 = f1+f2;
 80001ac:	697a      	ldr	r2, [r7, #20]
 80001ae:	693b      	ldr	r3, [r7, #16]
 80001b0:	4413      	add	r3, r2
 80001b2:	607b      	str	r3, [r7, #4]
		f1 = f2;
 80001b4:	693b      	ldr	r3, [r7, #16]
 80001b6:	617b      	str	r3, [r7, #20]
		f2 = f3;
 80001b8:	687b      	ldr	r3, [r7, #4]
 80001ba:	613b      	str	r3, [r7, #16]
	for( i=0; i<n-2; i++)
 80001bc:	68fb      	ldr	r3, [r7, #12]
 80001be:	3301      	adds	r3, #1
 80001c0:	60fb      	str	r3, [r7, #12]
 80001c2:	68bb      	ldr	r3, [r7, #8]
 80001c4:	1e9a      	subs	r2, r3, #2
 80001c6:	68fb      	ldr	r3, [r7, #12]
 80001c8:	429a      	cmp	r2, r3
 80001ca:	dcef      	bgt.n	80001ac <main+0x18>
 80001cc:	2300      	movs	r3, #0
	}

}
 80001ce:	4618      	mov	r0, r3
 80001d0:	371c      	adds	r7, #28
 80001d2:	46bd      	mov	sp, r7
 80001d4:	f85d 7b04 	ldr.w	r7, [sp], #4
 80001d8:	4770      	bx	lr
