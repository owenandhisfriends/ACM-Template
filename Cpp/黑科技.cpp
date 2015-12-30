//λ����
//ȥ�����һλ          | (101101->10110)           | x shr 1
//������һ��0         | (101101->1011010)         | x shl 1
//������һ��1         | (101101->1011011)         | x shl 1+1
//�����һλ���1       | (101100->101101)          | x or 1
//�����һλ���0       | (101101->101100)          | x or 1-1
//���һλȡ��          | (101101->101100)          | x xor 1
//��������kλ���1      | (101001->101101,k=3)      | x or (1 shl (k-1))
//��������kλ���0      | (101101->101001,k=3)      | x and not (1 shl (k-1))
//������kλȡ��         | (101001->101101,k=3)      | x xor (1 shl (k-1))
//ȡĩ��λ              | (1101101->101)            | x and 7
//ȡĩkλ               | (1101101->1101,k=5)       | x and (1 shl k-1)
//ȡ������kλ           | (1101101->1,k=4)          | x shr (k-1) and 1
//��ĩkλ���1          | (101001->101111,k=4)      | x or (1 shl k-1)
//ĩkλȡ��             | (101001->100110,k=4)      | x xor (1 shl k-1)
//���ұ�������1���0    | (100101111->100100000)    | x and (x+1)
//�������һ��0���1    | (100101111->100111111)    | x or (x+1)
//���ұ�������0���1    | (11011000->11011111)      | x or (x-1)
//ȡ�ұ�������1         | (100101111->1111)         | (x xor (x+1)) shr 1
//ȥ�������һ��1����� | (100101000->1000)         | x and (x xor (x-1))

//builtin����
int __builtin_ffs(int x);
int __builtin_ffsll(long long);
//Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.

int __builtin_clz(unsigned int x);
int __builtin_clzll(unsigned long long);
//Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.

int __builtin_ctz(unsigned int x);
int __builtin_ctzll(unsigned long long);
//Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.

int __builtin_clrsb(int x);
int __builtin_clrsbll(long long);
//Returns the number of leading redundant sign bits in x, i.e. the number of bits following the most significant bit that are identical to it. There are no special cases for 0 or other values.

int __builtin_popcount(unsigned int x);
int __builtin_popcountll(unsigned long long);
//Returns the number of 1-bits in x.

int __builtin_parity(unsigned int x);
int __builtin_parityll(unsigned long long);
//Returns the parity of x, i.e. the number of 1-bits in x modulo 2.

uint32_t __builtin_bswap32(uint32_t x);
uint64_t __builtin_bswap64(uint64_t x);
//Returns x with the order of the bytes reversed; for example, 0xaabb becomes 0xbbaa. Byte here always means exactly 8 bits.
