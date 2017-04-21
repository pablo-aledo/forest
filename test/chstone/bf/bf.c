/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf.c */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */



/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/blowfish.h */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

#ifndef HEADER_BLOWFISH_H
#define HEADER_BLOWFISH_H

#define BF_ENCRYPT	1

/* If you make this 'unsigned int' the pointer variants will work on
 * the Alpha, otherwise they will not.  Strangly using the '8 byte'
 * BF_LONG and the default 'non-pointer' inner loop is the best configuration
 * for the Alpha */
#define BF_LONG unsigned long

#define BF_ROUNDS	16
BF_LONG key_P[BF_ROUNDS + 2];
BF_LONG key_S[4 * 256];

void BF_set_key (int len, unsigned char *data);
void BF_encrypt (BF_LONG * data, int encrypt);
void BF_cfb64_encrypt (unsigned char *in, unsigned char *out, long length,
		       unsigned char *ivec, int *num, int encrypt);

#endif
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf_local.h */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
 *
 * Always modify bf_locl.org since bf_locl.h is automatically generated from
 * it during SSLeay configuration.
 *
 * WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
 */

#undef n2l
#define n2l(c,l)        (l =((unsigned long)(*((c)++)))<<24L, \
                         l|=((unsigned long)(*((c)++)))<<16L, \
                         l|=((unsigned long)(*((c)++)))<< 8L, \
                         l|=((unsigned long)(*((c)++))))

#undef l2n
#define l2n(l,c)        (*((c)++)=(unsigned char)(((l)>>24L)&0xff), \
                         *((c)++)=(unsigned char)(((l)>>16L)&0xff), \
                         *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \
                         *((c)++)=(unsigned char)(((l)     )&0xff))

/* This will always work, even on 64 bit machines and strangly enough,
 * on the Alpha it is faster than the pointer versions (both 32 and 64
 * versions of BF_LONG) */
#define BF_ENC(LL,R,S,P) \
	LL^=P; \
	LL^=(((	S[        (R>>24L)      ] + \
		S[0x0100+((R>>16L)&0xff)])^ \
		S[0x0200+((R>> 8L)&0xff)])+ \
		S[0x0300+((R     )&0xff)])&0xffffffff;
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf_pi.h */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

const BF_LONG bf_init_P[BF_ROUNDS + 2] = {
  0x243f6a88L, 0x85a308d3L, 0x13198a2eL, 0x03707344L,
  0xa4093822L, 0x299f31d0L, 0x082efa98L, 0xec4e6c89L,
  0x452821e6L, 0x38d01377L, 0xbe5466cfL, 0x34e90c6cL,
  0xc0ac29b7L, 0xc97c50ddL, 0x3f84d5b5L, 0xb5470917L,
  0x9216d5d9L, 0x8979fb1b
};
const BF_LONG bf_init_S[4 * 256] = {
  0xd1310ba6L, 0x98dfb5acL, 0x2ffd72dbL, 0xd01adfb7L,
  0xb8e1afedL, 0x6a267e96L, 0xba7c9045L, 0xf12c7f99L,
  0x24a19947L, 0xb3916cf7L, 0x0801f2e2L, 0x858efc16L,
  0x636920d8L, 0x71574e69L, 0xa458fea3L, 0xf4933d7eL,
  0x0d95748fL, 0x728eb658L, 0x718bcd58L, 0x82154aeeL,
  0x7b54a41dL, 0xc25a59b5L, 0x9c30d539L, 0x2af26013L,
  0xc5d1b023L, 0x286085f0L, 0xca417918L, 0xb8db38efL,
  0x8e79dcb0L, 0x603a180eL, 0x6c9e0e8bL, 0xb01e8a3eL,
  0xd71577c1L, 0xbd314b27L, 0x78af2fdaL, 0x55605c60L,
  0xe65525f3L, 0xaa55ab94L, 0x57489862L, 0x63e81440L,
  0x55ca396aL, 0x2aab10b6L, 0xb4cc5c34L, 0x1141e8ceL,
  0xa15486afL, 0x7c72e993L, 0xb3ee1411L, 0x636fbc2aL,
  0x2ba9c55dL, 0x741831f6L, 0xce5c3e16L, 0x9b87931eL,
  0xafd6ba33L, 0x6c24cf5cL, 0x7a325381L, 0x28958677L,
  0x3b8f4898L, 0x6b4bb9afL, 0xc4bfe81bL, 0x66282193L,
  0x61d809ccL, 0xfb21a991L, 0x487cac60L, 0x5dec8032L,
  0xef845d5dL, 0xe98575b1L, 0xdc262302L, 0xeb651b88L,
  0x23893e81L, 0xd396acc5L, 0x0f6d6ff3L, 0x83f44239L,
  0x2e0b4482L, 0xa4842004L, 0x69c8f04aL, 0x9e1f9b5eL,
  0x21c66842L, 0xf6e96c9aL, 0x670c9c61L, 0xabd388f0L,
  0x6a51a0d2L, 0xd8542f68L, 0x960fa728L, 0xab5133a3L,
  0x6eef0b6cL, 0x137a3be4L, 0xba3bf050L, 0x7efb2a98L,
  0xa1f1651dL, 0x39af0176L, 0x66ca593eL, 0x82430e88L,
  0x8cee8619L, 0x456f9fb4L, 0x7d84a5c3L, 0x3b8b5ebeL,
  0xe06f75d8L, 0x85c12073L, 0x401a449fL, 0x56c16aa6L,
  0x4ed3aa62L, 0x363f7706L, 0x1bfedf72L, 0x429b023dL,
  0x37d0d724L, 0xd00a1248L, 0xdb0fead3L, 0x49f1c09bL,
  0x075372c9L, 0x80991b7bL, 0x25d479d8L, 0xf6e8def7L,
  0xe3fe501aL, 0xb6794c3bL, 0x976ce0bdL, 0x04c006baL,
  0xc1a94fb6L, 0x409f60c4L, 0x5e5c9ec2L, 0x196a2463L,
  0x68fb6fafL, 0x3e6c53b5L, 0x1339b2ebL, 0x3b52ec6fL,
  0x6dfc511fL, 0x9b30952cL, 0xcc814544L, 0xaf5ebd09L,
  0xbee3d004L, 0xde334afdL, 0x660f2807L, 0x192e4bb3L,
  0xc0cba857L, 0x45c8740fL, 0xd20b5f39L, 0xb9d3fbdbL,
  0x5579c0bdL, 0x1a60320aL, 0xd6a100c6L, 0x402c7279L,
  0x679f25feL, 0xfb1fa3ccL, 0x8ea5e9f8L, 0xdb3222f8L,
  0x3c7516dfL, 0xfd616b15L, 0x2f501ec8L, 0xad0552abL,
  0x323db5faL, 0xfd238760L, 0x53317b48L, 0x3e00df82L,
  0x9e5c57bbL, 0xca6f8ca0L, 0x1a87562eL, 0xdf1769dbL,
  0xd542a8f6L, 0x287effc3L, 0xac6732c6L, 0x8c4f5573L,
  0x695b27b0L, 0xbbca58c8L, 0xe1ffa35dL, 0xb8f011a0L,
  0x10fa3d98L, 0xfd2183b8L, 0x4afcb56cL, 0x2dd1d35bL,
  0x9a53e479L, 0xb6f84565L, 0xd28e49bcL, 0x4bfb9790L,
  0xe1ddf2daL, 0xa4cb7e33L, 0x62fb1341L, 0xcee4c6e8L,
  0xef20cadaL, 0x36774c01L, 0xd07e9efeL, 0x2bf11fb4L,
  0x95dbda4dL, 0xae909198L, 0xeaad8e71L, 0x6b93d5a0L,
  0xd08ed1d0L, 0xafc725e0L, 0x8e3c5b2fL, 0x8e7594b7L,
  0x8ff6e2fbL, 0xf2122b64L, 0x8888b812L, 0x900df01cL,
  0x4fad5ea0L, 0x688fc31cL, 0xd1cff191L, 0xb3a8c1adL,
  0x2f2f2218L, 0xbe0e1777L, 0xea752dfeL, 0x8b021fa1L,
  0xe5a0cc0fL, 0xb56f74e8L, 0x18acf3d6L, 0xce89e299L,
  0xb4a84fe0L, 0xfd13e0b7L, 0x7cc43b81L, 0xd2ada8d9L,
  0x165fa266L, 0x80957705L, 0x93cc7314L, 0x211a1477L,
  0xe6ad2065L, 0x77b5fa86L, 0xc75442f5L, 0xfb9d35cfL,
  0xebcdaf0cL, 0x7b3e89a0L, 0xd6411bd3L, 0xae1e7e49L,
  0x00250e2dL, 0x2071b35eL, 0x226800bbL, 0x57b8e0afL,
  0x2464369bL, 0xf009b91eL, 0x5563911dL, 0x59dfa6aaL,
  0x78c14389L, 0xd95a537fL, 0x207d5ba2L, 0x02e5b9c5L,
  0x83260376L, 0x6295cfa9L, 0x11c81968L, 0x4e734a41L,
  0xb3472dcaL, 0x7b14a94aL, 0x1b510052L, 0x9a532915L,
  0xd60f573fL, 0xbc9bc6e4L, 0x2b60a476L, 0x81e67400L,
  0x08ba6fb5L, 0x571be91fL, 0xf296ec6bL, 0x2a0dd915L,
  0xb6636521L, 0xe7b9f9b6L, 0xff34052eL, 0xc5855664L,
  0x53b02d5dL, 0xa99f8fa1L, 0x08ba4799L, 0x6e85076aL,
  0x4b7a70e9L, 0xb5b32944L, 0xdb75092eL, 0xc4192623L,
  0xad6ea6b0L, 0x49a7df7dL, 0x9cee60b8L, 0x8fedb266L,
  0xecaa8c71L, 0x699a17ffL, 0x5664526cL, 0xc2b19ee1L,
  0x193602a5L, 0x75094c29L, 0xa0591340L, 0xe4183a3eL,
  0x3f54989aL, 0x5b429d65L, 0x6b8fe4d6L, 0x99f73fd6L,
  0xa1d29c07L, 0xefe830f5L, 0x4d2d38e6L, 0xf0255dc1L,
  0x4cdd2086L, 0x8470eb26L, 0x6382e9c6L, 0x021ecc5eL,
  0x09686b3fL, 0x3ebaefc9L, 0x3c971814L, 0x6b6a70a1L,
  0x687f3584L, 0x52a0e286L, 0xb79c5305L, 0xaa500737L,
  0x3e07841cL, 0x7fdeae5cL, 0x8e7d44ecL, 0x5716f2b8L,
  0xb03ada37L, 0xf0500c0dL, 0xf01c1f04L, 0x0200b3ffL,
  0xae0cf51aL, 0x3cb574b2L, 0x25837a58L, 0xdc0921bdL,
  0xd19113f9L, 0x7ca92ff6L, 0x94324773L, 0x22f54701L,
  0x3ae5e581L, 0x37c2dadcL, 0xc8b57634L, 0x9af3dda7L,
  0xa9446146L, 0x0fd0030eL, 0xecc8c73eL, 0xa4751e41L,
  0xe238cd99L, 0x3bea0e2fL, 0x3280bba1L, 0x183eb331L,
  0x4e548b38L, 0x4f6db908L, 0x6f420d03L, 0xf60a04bfL,
  0x2cb81290L, 0x24977c79L, 0x5679b072L, 0xbcaf89afL,
  0xde9a771fL, 0xd9930810L, 0xb38bae12L, 0xdccf3f2eL,
  0x5512721fL, 0x2e6b7124L, 0x501adde6L, 0x9f84cd87L,
  0x7a584718L, 0x7408da17L, 0xbc9f9abcL, 0xe94b7d8cL,
  0xec7aec3aL, 0xdb851dfaL, 0x63094366L, 0xc464c3d2L,
  0xef1c1847L, 0x3215d908L, 0xdd433b37L, 0x24c2ba16L,
  0x12a14d43L, 0x2a65c451L, 0x50940002L, 0x133ae4ddL,
  0x71dff89eL, 0x10314e55L, 0x81ac77d6L, 0x5f11199bL,
  0x043556f1L, 0xd7a3c76bL, 0x3c11183bL, 0x5924a509L,
  0xf28fe6edL, 0x97f1fbfaL, 0x9ebabf2cL, 0x1e153c6eL,
  0x86e34570L, 0xeae96fb1L, 0x860e5e0aL, 0x5a3e2ab3L,
  0x771fe71cL, 0x4e3d06faL, 0x2965dcb9L, 0x99e71d0fL,
  0x803e89d6L, 0x5266c825L, 0x2e4cc978L, 0x9c10b36aL,
  0xc6150ebaL, 0x94e2ea78L, 0xa5fc3c53L, 0x1e0a2df4L,
  0xf2f74ea7L, 0x361d2b3dL, 0x1939260fL, 0x19c27960L,
  0x5223a708L, 0xf71312b6L, 0xebadfe6eL, 0xeac31f66L,
  0xe3bc4595L, 0xa67bc883L, 0xb17f37d1L, 0x018cff28L,
  0xc332ddefL, 0xbe6c5aa5L, 0x65582185L, 0x68ab9802L,
  0xeecea50fL, 0xdb2f953bL, 0x2aef7dadL, 0x5b6e2f84L,
  0x1521b628L, 0x29076170L, 0xecdd4775L, 0x619f1510L,
  0x13cca830L, 0xeb61bd96L, 0x0334fe1eL, 0xaa0363cfL,
  0xb5735c90L, 0x4c70a239L, 0xd59e9e0bL, 0xcbaade14L,
  0xeecc86bcL, 0x60622ca7L, 0x9cab5cabL, 0xb2f3846eL,
  0x648b1eafL, 0x19bdf0caL, 0xa02369b9L, 0x655abb50L,
  0x40685a32L, 0x3c2ab4b3L, 0x319ee9d5L, 0xc021b8f7L,
  0x9b540b19L, 0x875fa099L, 0x95f7997eL, 0x623d7da8L,
  0xf837889aL, 0x97e32d77L, 0x11ed935fL, 0x16681281L,
  0x0e358829L, 0xc7e61fd6L, 0x96dedfa1L, 0x7858ba99L,
  0x57f584a5L, 0x1b227263L, 0x9b83c3ffL, 0x1ac24696L,
  0xcdb30aebL, 0x532e3054L, 0x8fd948e4L, 0x6dbc3128L,
  0x58ebf2efL, 0x34c6ffeaL, 0xfe28ed61L, 0xee7c3c73L,
  0x5d4a14d9L, 0xe864b7e3L, 0x42105d14L, 0x203e13e0L,
  0x45eee2b6L, 0xa3aaabeaL, 0xdb6c4f15L, 0xfacb4fd0L,
  0xc742f442L, 0xef6abbb5L, 0x654f3b1dL, 0x41cd2105L,
  0xd81e799eL, 0x86854dc7L, 0xe44b476aL, 0x3d816250L,
  0xcf62a1f2L, 0x5b8d2646L, 0xfc8883a0L, 0xc1c7b6a3L,
  0x7f1524c3L, 0x69cb7492L, 0x47848a0bL, 0x5692b285L,
  0x095bbf00L, 0xad19489dL, 0x1462b174L, 0x23820e00L,
  0x58428d2aL, 0x0c55f5eaL, 0x1dadf43eL, 0x233f7061L,
  0x3372f092L, 0x8d937e41L, 0xd65fecf1L, 0x6c223bdbL,
  0x7cde3759L, 0xcbee7460L, 0x4085f2a7L, 0xce77326eL,
  0xa6078084L, 0x19f8509eL, 0xe8efd855L, 0x61d99735L,
  0xa969a7aaL, 0xc50c06c2L, 0x5a04abfcL, 0x800bcadcL,
  0x9e447a2eL, 0xc3453484L, 0xfdd56705L, 0x0e1e9ec9L,
  0xdb73dbd3L, 0x105588cdL, 0x675fda79L, 0xe3674340L,
  0xc5c43465L, 0x713e38d8L, 0x3d28f89eL, 0xf16dff20L,
  0x153e21e7L, 0x8fb03d4aL, 0xe6e39f2bL, 0xdb83adf7L,
  0xe93d5a68L, 0x948140f7L, 0xf64c261cL, 0x94692934L,
  0x411520f7L, 0x7602d4f7L, 0xbcf46b2eL, 0xd4a20068L,
  0xd4082471L, 0x3320f46aL, 0x43b7d4b7L, 0x500061afL,
  0x1e39f62eL, 0x97244546L, 0x14214f74L, 0xbf8b8840L,
  0x4d95fc1dL, 0x96b591afL, 0x70f4ddd3L, 0x66a02f45L,
  0xbfbc09ecL, 0x03bd9785L, 0x7fac6dd0L, 0x31cb8504L,
  0x96eb27b3L, 0x55fd3941L, 0xda2547e6L, 0xabca0a9aL,
  0x28507825L, 0x530429f4L, 0x0a2c86daL, 0xe9b66dfbL,
  0x68dc1462L, 0xd7486900L, 0x680ec0a4L, 0x27a18deeL,
  0x4f3ffea2L, 0xe887ad8cL, 0xb58ce006L, 0x7af4d6b6L,
  0xaace1e7cL, 0xd3375fecL, 0xce78a399L, 0x406b2a42L,
  0x20fe9e35L, 0xd9f385b9L, 0xee39d7abL, 0x3b124e8bL,
  0x1dc9faf7L, 0x4b6d1856L, 0x26a36631L, 0xeae397b2L,
  0x3a6efa74L, 0xdd5b4332L, 0x6841e7f7L, 0xca7820fbL,
  0xfb0af54eL, 0xd8feb397L, 0x454056acL, 0xba489527L,
  0x55533a3aL, 0x20838d87L, 0xfe6ba9b7L, 0xd096954bL,
  0x55a867bcL, 0xa1159a58L, 0xcca92963L, 0x99e1db33L,
  0xa62a4a56L, 0x3f3125f9L, 0x5ef47e1cL, 0x9029317cL,
  0xfdf8e802L, 0x04272f70L, 0x80bb155cL, 0x05282ce3L,
  0x95c11548L, 0xe4c66d22L, 0x48c1133fL, 0xc70f86dcL,
  0x07f9c9eeL, 0x41041f0fL, 0x404779a4L, 0x5d886e17L,
  0x325f51ebL, 0xd59bc0d1L, 0xf2bcc18fL, 0x41113564L,
  0x257b7834L, 0x602a9c60L, 0xdff8e8a3L, 0x1f636c1bL,
  0x0e12b4c2L, 0x02e1329eL, 0xaf664fd1L, 0xcad18115L,
  0x6b2395e0L, 0x333e92e1L, 0x3b240b62L, 0xeebeb922L,
  0x85b2a20eL, 0xe6ba0d99L, 0xde720c8cL, 0x2da2f728L,
  0xd0127845L, 0x95b794fdL, 0x647d0862L, 0xe7ccf5f0L,
  0x5449a36fL, 0x877d48faL, 0xc39dfd27L, 0xf33e8d1eL,
  0x0a476341L, 0x992eff74L, 0x3a6f6eabL, 0xf4f8fd37L,
  0xa812dc60L, 0xa1ebddf8L, 0x991be14cL, 0xdb6e6b0dL,
  0xc67b5510L, 0x6d672c37L, 0x2765d43bL, 0xdcd0e804L,
  0xf1290dc7L, 0xcc00ffa3L, 0xb5390f92L, 0x690fed0bL,
  0x667b9ffbL, 0xcedb7d9cL, 0xa091cf0bL, 0xd9155ea3L,
  0xbb132f88L, 0x515bad24L, 0x7b9479bfL, 0x763bd6ebL,
  0x37392eb3L, 0xcc115979L, 0x8026e297L, 0xf42e312dL,
  0x6842ada7L, 0xc66a2b3bL, 0x12754cccL, 0x782ef11cL,
  0x6a124237L, 0xb79251e7L, 0x06a1bbe6L, 0x4bfb6350L,
  0x1a6b1018L, 0x11caedfaL, 0x3d25bdd8L, 0xe2e1c3c9L,
  0x44421659L, 0x0a121386L, 0xd90cec6eL, 0xd5abea2aL,
  0x64af674eL, 0xda86a85fL, 0xbebfe988L, 0x64e4c3feL,
  0x9dbc8057L, 0xf0f7c086L, 0x60787bf8L, 0x6003604dL,
  0xd1fd8346L, 0xf6381fb0L, 0x7745ae04L, 0xd736fcccL,
  0x83426b33L, 0xf01eab71L, 0xb0804187L, 0x3c005e5fL,
  0x77a057beL, 0xbde8ae24L, 0x55464299L, 0xbf582e61L,
  0x4e58f48fL, 0xf2ddfda2L, 0xf474ef38L, 0x8789bdc2L,
  0x5366f9c3L, 0xc8b38e74L, 0xb475f255L, 0x46fcd9b9L,
  0x7aeb2661L, 0x8b1ddf84L, 0x846a0e79L, 0x915f95e2L,
  0x466e598eL, 0x20b45770L, 0x8cd55591L, 0xc902de4cL,
  0xb90bace1L, 0xbb8205d0L, 0x11a86248L, 0x7574a99eL,
  0xb77f19b6L, 0xe0a9dc09L, 0x662d09a1L, 0xc4324633L,
  0xe85a1f02L, 0x09f0be8cL, 0x4a99a025L, 0x1d6efe10L,
  0x1ab93d1dL, 0x0ba5a4dfL, 0xa186f20fL, 0x2868f169L,
  0xdcb7da83L, 0x573906feL, 0xa1e2ce9bL, 0x4fcd7f52L,
  0x50115e01L, 0xa70683faL, 0xa002b5c4L, 0x0de6d027L,
  0x9af88c27L, 0x773f8641L, 0xc3604c06L, 0x61a806b5L,
  0xf0177a28L, 0xc0f586e0L, 0x006058aaL, 0x30dc7d62L,
  0x11e69ed7L, 0x2338ea63L, 0x53c2dd94L, 0xc2c21634L,
  0xbbcbee56L, 0x90bcb6deL, 0xebfc7da1L, 0xce591d76L,
  0x6f05e409L, 0x4b7c0188L, 0x39720a3dL, 0x7c927c24L,
  0x86e3725fL, 0x724d9db9L, 0x1ac15bb4L, 0xd39eb8fcL,
  0xed545578L, 0x08fca5b5L, 0xd83d7cd3L, 0x4dad0fc4L,
  0x1e50ef5eL, 0xb161e6f8L, 0xa28514d9L, 0x6c51133cL,
  0x6fd5c7e7L, 0x56e14ec4L, 0x362abfceL, 0xddc6c837L,
  0xd79a3234L, 0x92638212L, 0x670efa8eL, 0x406000e0L,
  0x3a39ce37L, 0xd3faf5cfL, 0xabc27737L, 0x5ac52d1bL,
  0x5cb0679eL, 0x4fa33742L, 0xd3822740L, 0x99bc9bbeL,
  0xd5118e9dL, 0xbf0f7315L, 0xd62d1c7eL, 0xc700c47bL,
  0xb78c1b6bL, 0x21a19045L, 0xb26eb1beL, 0x6a366eb4L,
  0x5748ab2fL, 0xbc946e79L, 0xc6a376d2L, 0x6549c2c8L,
  0x530ff8eeL, 0x468dde7dL, 0xd5730a1dL, 0x4cd04dc6L,
  0x2939bbdbL, 0xa9ba4650L, 0xac9526e8L, 0xbe5ee304L,
  0xa1fad5f0L, 0x6a2d519aL, 0x63ef8ce2L, 0x9a86ee22L,
  0xc089c2b8L, 0x43242ef6L, 0xa51e03aaL, 0x9cf2d0a4L,
  0x83c061baL, 0x9be96a4dL, 0x8fe51550L, 0xba645bd6L,
  0x2826a2f9L, 0xa73a3ae1L, 0x4ba99586L, 0xef5562e9L,
  0xc72fefd3L, 0xf752f7daL, 0x3f046f69L, 0x77fa0a59L,
  0x80e4a915L, 0x87b08601L, 0x9b09e6adL, 0x3b3ee593L,
  0xe990fd5aL, 0x9e34d797L, 0x2cf0b7d9L, 0x022b8b51L,
  0x96d5ac3aL, 0x017da67dL, 0xd1cf3ed6L, 0x7c7d2d28L,
  0x1f9f25cfL, 0xadf2b89bL, 0x5ad6b472L, 0x5a88f54cL,
  0xe029ac71L, 0xe019a5e6L, 0x47b0acfdL, 0xed93fa9bL,
  0xe8d3c48dL, 0x283b57ccL, 0xf8d56629L, 0x79132e28L,
  0x785f0191L, 0xed756055L, 0xf7960e44L, 0xe3d35e8cL,
  0x15056dd4L, 0x88f46dbaL, 0x03a16125L, 0x0564f0bdL,
  0xc3eb9e15L, 0x3c9057a2L, 0x97271aecL, 0xa93a072aL,
  0x1b3f6d9bL, 0x1e6321f5L, 0xf59c66fbL, 0x26dcf319L,
  0x7533d928L, 0xb155fdf5L, 0x03563482L, 0x8aba3cbbL,
  0x28517711L, 0xc20ad9f8L, 0xabcc5167L, 0xccad925fL,
  0x4de81751L, 0x3830dc8eL, 0x379d5862L, 0x9320f991L,
  0xea7a90c2L, 0xfb3e7bceL, 0x5121ce64L, 0x774fbe32L,
  0xa8b6e37eL, 0xc3293d46L, 0x48de5369L, 0x6413e680L,
  0xa2ae0810L, 0xdd6db224L, 0x69852dfdL, 0x09072166L,
  0xb39a460aL, 0x6445c0ddL, 0x586cdecfL, 0x1c20c8aeL,
  0x5bbef7ddL, 0x1b588d40L, 0xccd2017fL, 0x6bb4e3bbL,
  0xdda26a7eL, 0x3a59ff45L, 0x3e350a44L, 0xbcb4cdd5L,
  0x72eacea8L, 0xfa6484bbL, 0x8d6612aeL, 0xbf3c6f47L,
  0xd29be463L, 0x542f5d9eL, 0xaec2771bL, 0xf64e6370L,
  0x740e0d8dL, 0xe75b1357L, 0xf8721671L, 0xaf537d5dL,
  0x4040cb08L, 0x4eb4e2ccL, 0x34d2466aL, 0x0115af84L,
  0xe1b00428L, 0x95983a1dL, 0x06b89fb4L, 0xce6ea048L,
  0x6f3f3b82L, 0x3520ab82L, 0x011a1d4bL, 0x277227f8L,
  0x611560b1L, 0xe7933fdcL, 0xbb3a792bL, 0x344525bdL,
  0xa08839e1L, 0x51ce794bL, 0x2f32c9b7L, 0xa01fbac9L,
  0xe01cc87eL, 0xbcc7d1f6L, 0xcf0111c3L, 0xa1e8aac7L,
  0x1a908749L, 0xd44fbd9aL, 0xd0dadecbL, 0xd50ada38L,
  0x0339c32aL, 0xc6913667L, 0x8df9317cL, 0xe0b12b4fL,
  0xf79e59b7L, 0x43f5bb3aL, 0xf2d519ffL, 0x27d9459cL,
  0xbf97222cL, 0x15e6fc2aL, 0x0f91fc71L, 0x9b941525L,
  0xfae59361L, 0xceb69cebL, 0xc2a86459L, 0x12baa8d1L,
  0xb6c1075eL, 0xe3056a0cL, 0x10d25065L, 0xcb03a442L,
  0xe0ec6e0eL, 0x1698db3bL, 0x4c98a0beL, 0x3278e964L,
  0x9f1f9532L, 0xe0d392dfL, 0xd3a0342bL, 0x8971f21eL,
  0x1b0a7441L, 0x4ba3348cL, 0xc5be7120L, 0xc37632d8L,
  0xdf359f8dL, 0x9b992f2eL, 0xe60b6f47L, 0x0fe3f11dL,
  0xe54cda54L, 0x1edad891L, 0xce6279cfL, 0xcd3e7e6fL,
  0x1618b166L, 0xfd2c1d05L, 0x848fd2c5L, 0xf6fb2299L,
  0xf523f357L, 0xa6327623L, 0x93a83531L, 0x56cccd02L,
  0xacf08162L, 0x5a75ebb5L, 0x6e163697L, 0x88d273ccL,
  0xde966292L, 0x81b949d0L, 0x4c50901bL, 0x71c65614L,
  0xe6c6c7bdL, 0x327a140aL, 0x45e1d006L, 0xc3f27b9aL,
  0xc9aa53fdL, 0x62a80f00L, 0xbb25bfe2L, 0x35bdd2f6L,
  0x71126905L, 0xb2040222L, 0xb6cbcf7cL, 0xcd769c2bL,
  0x53113ec0L, 0x1640e3d3L, 0x38abbd60L, 0x2547adf0L,
  0xba38209cL, 0xf746ce76L, 0x77afa1c5L, 0x20756060L,
  0x85cbfe4eL, 0x8ae88dd8L, 0x7aaaf9b0L, 0x4cf9aa7eL,
  0x1948c25cL, 0x02fb8a8cL, 0x01c36ae4L, 0xd6ebe1f9L,
  0x90d4f869L, 0xa65cdea0L, 0x3f09252dL, 0xc208e69fL,
  0xb74e6132L, 0xce77e25bL, 0x578fdfe3L, 0x3ac372e6L
};
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf_skey.c */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

void
bf_memcpy (BF_LONG * s1, const BF_LONG * s2, int n)
{
  BF_LONG *p1;
  const BF_LONG *p2;

  p1 = s1;
  p2 = s2;

  while (n-- > 0)
    {
      *p1 = *p2;
      p1++;
      p2++;
    }
}

void
BF_set_key (int len, unsigned char *data)
{
  int i;
  BF_LONG *p, ri, in[2];
  unsigned char *d, *end;

  bf_memcpy (key_P, bf_init_P, BF_ROUNDS + 2);
  bf_memcpy (key_S, bf_init_S, 4 * 256);
  p = key_P;

  if (len > ((BF_ROUNDS + 2) * 4))
    len = (BF_ROUNDS + 2) * 4;

  d = data;
  end = &(data[len]);
  for (i = 0; i < (BF_ROUNDS + 2); i++)
    {
      ri = *(d++);
      if (d >= end)
	d = data;

      ri <<= 8;
      ri |= *(d++);
      if (d >= end)
	d = data;

      ri <<= 8;
      ri |= *(d++);
      if (d >= end)
	d = data;

      ri <<= 8;
      ri |= *(d++);
      if (d >= end)
	d = data;

      p[i] ^= ri;
    }

  in[0] = 0L;
  in[1] = 0L;
  for (i = 0; i < (BF_ROUNDS + 2); i += 2)
    {
      BF_encrypt (in, BF_ENCRYPT);
      p[i] = in[0];
      p[i + 1] = in[1];
    }

  p = key_S;
  for (i = 0; i < 4 * 256; i += 2)
    {
      BF_encrypt (in, BF_ENCRYPT);
      p[i] = in[0];
      p[i + 1] = in[1];
    }

}
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf_cfb64.c */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
/* The input and output encrypted as though 64bit cfb mode is being
 * used.  The extra state information to record how much of the
 * 64bit block we have used is contained in *num;
 */

void
BF_cfb64_encrypt (in, out, length, ivec, num, encrypt)
     unsigned char *in;
     unsigned char *out;
     long length;
     unsigned char *ivec;
     int *num;
     int encrypt;
{
  register BF_LONG v0, v1, t;
  register int n;
  register long l;
  BF_LONG ti[2];
  unsigned char *iv, c, cc;

  n = *num;
  l = length;
  iv = (unsigned char *) ivec;
  if (encrypt)
    {
      while (l--)
	{
	  if (n == 0)
	    {
	      n2l (iv, v0);
	      ti[0] = v0;
	      n2l (iv, v1);
	      ti[1] = v1;
	      BF_encrypt ((unsigned long *) ti, BF_ENCRYPT);
	      iv = (unsigned char *) ivec;
	      t = ti[0];
	      l2n (t, iv);
	      t = ti[1];
	      l2n (t, iv);

	      iv = (unsigned char *) ivec;
	    }
	  c = *(in++) ^ iv[n];
	  *(out++) = c;
	  iv[n] = c;
	  n = (n + 1) & 0x07;
	}
    }
  else
    {
      while (l--)
	{
	  if (n == 0)
	    {
	      n2l (iv, v0);
	      ti[0] = v0;
	      n2l (iv, v1);
	      ti[1] = v1;
	      BF_encrypt ((unsigned long *) ti, BF_ENCRYPT);
	      iv = (unsigned char *) ivec;
	      t = ti[0];
	      l2n (t, iv);
	      t = ti[1];
	      l2n (t, iv);
	      iv = (unsigned char *) ivec;
	    }
	  cc = *(in++);
	  c = iv[n];
	  iv[n] = cc;
	  *(out++) = c ^ cc;
	  n = (n + 1) & 0x07;
	}
    }
  v0 = v1 = ti[0] = ti[1] = t = c = cc = 0;
  *num = n;
}
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/* crypto/bf/bf_enc.c */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
/* Blowfish as implemented from 'Blowfish: Springer-Verlag paper'
 * (From LECTURE NOTES IN COIMPUTER SCIENCE 809, FAST SOFTWARE ENCRYPTION,
 * CAMBRIDGE SECURITY WORKSHOP, CAMBRIDGE, U.K., DECEMBER 9-11, 1993)
 */

void
BF_encrypt (data, encrypt)
     BF_LONG *data;
     int encrypt;
{
  register BF_LONG l, r, *p, *s;
  p = key_P;
  s = &(key_S[0]);
  l = data[0];
  r = data[1];

  if (encrypt)
    {
      l ^= p[0];

      BF_ENC (r, l, s, p[1]);
      BF_ENC (l, r, s, p[2]);
      BF_ENC (r, l, s, p[3]);
      BF_ENC (l, r, s, p[4]);
      BF_ENC (r, l, s, p[5]);
      BF_ENC (l, r, s, p[6]);
      BF_ENC (r, l, s, p[7]);
      BF_ENC (l, r, s, p[8]);
      BF_ENC (r, l, s, p[9]);
      BF_ENC (l, r, s, p[10]);
      BF_ENC (r, l, s, p[11]);
      BF_ENC (l, r, s, p[12]);
      BF_ENC (r, l, s, p[13]);
      BF_ENC (l, r, s, p[14]);
      BF_ENC (r, l, s, p[15]);
      BF_ENC (l, r, s, p[16]);
      r ^= p[BF_ROUNDS + 1];
    }
  else
    {
      l ^= p[BF_ROUNDS + 1];
      BF_ENC (r, l, s, p[16]);
      BF_ENC (l, r, s, p[15]);
      BF_ENC (r, l, s, p[14]);
      BF_ENC (l, r, s, p[13]);
      BF_ENC (r, l, s, p[12]);
      BF_ENC (l, r, s, p[11]);
      BF_ENC (r, l, s, p[10]);
      BF_ENC (l, r, s, p[9]);
      BF_ENC (r, l, s, p[8]);
      BF_ENC (l, r, s, p[7]);
      BF_ENC (r, l, s, p[6]);
      BF_ENC (l, r, s, p[5]);
      BF_ENC (r, l, s, p[4]);
      BF_ENC (l, r, s, p[3]);
      BF_ENC (r, l, s, p[2]);
      BF_ENC (l, r, s, p[1]);
      r ^= p[0];
    }
  data[1] = l & 0xffffffff;
  data[0] = r & 0xffffffff;
}


/*
+--------------------------------------------------------------------------+
| * Test Vectors (added for CHStone)                                       |
|     in_key : input data                                                  |
|     out_key : expected output data                                       |
+--------------------------------------------------------------------------+
*/
#define KEYSIZE 5200
const unsigned char in_key[KEYSIZE] = {
  75, 117, 114, 116, 86, 111, 110, 110, 101, 103, 117, 116, 115, 67, 111, 109,
  109, 101, 110, 99, 101, 109, 101, 110, 116, 65, 100, 100, 114, 101, 115,
  115, 97, 116, 77, 73, 84, 76, 97, 100,
  105, 101, 115, 97, 110, 100, 103, 101, 110, 116, 108, 101, 109, 101, 110,
  111, 102, 116, 104, 101, 99, 108, 97, 115, 115, 111, 102, 57, 55, 87, 101,
  97, 114, 115, 117, 110, 115, 99, 114, 101,
  101, 110, 73, 102, 73, 99, 111, 117, 108, 100, 111, 102, 102, 101, 114, 121,
  111, 117, 111, 110, 108, 121, 111, 110, 101, 116, 105, 112, 102, 111, 114,
  116, 104, 101, 102, 117, 116, 117, 114, 101,
  115, 117, 110, 115, 99, 114, 101, 101, 110, 119, 111, 117, 108, 100, 98,
  101, 105, 116, 84, 104, 101, 108, 111, 110, 103, 116, 101, 114, 109, 98,
  101, 110, 101, 102, 105, 116, 115, 111, 102, 115,
  117, 110, 115, 99, 114, 101, 101, 110, 104, 97, 118, 101, 98, 101, 101, 110,
  112, 114, 111, 118, 101, 100, 98, 121, 115, 99, 105, 101, 110, 116, 105,
  115, 116, 115, 119, 104, 101, 114, 101, 97,
  115, 116, 104, 101, 114, 101, 115, 116, 111, 102, 109, 121, 97, 100, 118,
  105, 99, 101, 104, 97, 115, 110, 111, 98, 97, 115, 105, 115, 109, 111,
  114, 101, 114, 101, 108, 105, 97, 98, 108, 101,
  116, 104, 97, 110, 109, 121, 111, 119, 110, 109, 101, 97, 110, 100, 101,
  114, 105, 110, 103, 101, 120, 112, 101, 114, 105, 101, 110, 99, 101, 73,
  119, 105, 108, 108, 100, 105, 115, 112, 101, 110,
  115, 101, 116, 104, 105, 115, 97, 100, 118, 105, 99, 101, 110, 111, 119, 69,
  110, 106, 111, 121, 116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100,
  98, 101, 97, 117, 116, 121, 111, 102, 121,
  111, 117, 114, 121, 111, 117, 116, 104, 79, 104, 110, 101, 118, 101, 114,
  109, 105, 110, 100, 89, 111, 117, 119, 105, 108, 108, 110, 111, 116, 117,
  110, 100, 101, 114, 115, 116, 97, 110, 100, 116,
  104, 101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121,
  111, 102, 121, 111, 117, 114, 121, 111, 117, 116, 104, 117, 110, 116, 105,
  108, 116, 104, 101, 121, 118, 101, 102, 97,
  100, 101, 100, 66, 117, 116, 116, 114, 117, 115, 116, 109, 101, 105, 110,
  50, 48, 121, 101, 97, 114, 115, 121, 111, 117, 108, 108, 108, 111, 111,
  107, 98, 97, 99, 107, 97, 116, 112, 104, 111,
  116, 111, 115, 111, 102, 121, 111, 117, 114, 115, 101, 108, 102, 97, 110,
  100, 114, 101, 99, 97, 108, 108, 105, 110, 97, 119, 97, 121, 121, 111,
  117, 99, 97, 110, 116, 103, 114, 97, 115, 112,
  110, 111, 119, 104, 111, 119, 109, 117, 99, 104, 112, 111, 115, 115, 105,
  98, 105, 108, 105, 116, 121, 108, 97, 121, 98, 101, 102, 111, 114, 101,
  121, 111, 117, 97, 110, 100, 104, 111, 119, 102,
  97, 98, 117, 108, 111, 117, 115, 121, 111, 117, 114, 101, 97, 108, 108, 121,
  108, 111, 111, 107, 101, 100, 89, 111, 117, 97, 114, 101, 110, 111, 116,
  97, 115, 102, 97, 116, 97, 115, 121, 111,
  117, 105, 109, 97, 103, 105, 110, 101, 68, 111, 110, 116, 119, 111, 114,
  114, 121, 97, 98, 111, 117, 116, 116, 104, 101, 102, 117, 116, 117, 114,
  101, 79, 114, 119, 111, 114, 114, 121, 98, 117,
  116, 107, 110, 111, 119, 116, 104, 97, 116, 75, 117, 114, 116, 86, 111, 110,
  110, 101, 103, 117, 75, 117, 114, 116, 86, 111, 110, 110, 101, 103, 117,
  116, 115, 67, 111, 109, 109, 101, 110, 99,
  101, 109, 101, 110, 116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77, 73,
  84, 76, 97, 100, 105, 101, 115, 97, 110, 100, 103, 101, 110, 116, 108,
  101, 109, 101, 110, 111, 102, 116, 104, 101,
  99, 108, 97, 115, 115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117, 110,
  115, 99, 114, 101, 101, 110, 73, 102, 73, 99, 111, 117, 108, 100, 111,
  102, 102, 101, 114, 121, 111, 117, 111, 110,
  108, 121, 111, 110, 101, 116, 105, 112, 102, 111, 114, 116, 104, 101, 102,
  117, 116, 117, 114, 101, 115, 117, 110, 115, 99, 114, 101, 101, 110, 119,
  111, 117, 108, 100, 98, 101, 105, 116, 84, 104,
  101, 108, 111, 110, 103, 116, 101, 114, 109, 98, 101, 110, 101, 102, 105,
  116, 115, 111, 102, 115, 117, 110, 115, 99, 114, 101, 101, 110, 104, 97,
  118, 101, 98, 101, 101, 110, 112, 114, 111, 118,
  101, 100, 98, 121, 115, 99, 105, 101, 110, 116, 105, 115, 116, 115, 119,
  104, 101, 114, 101, 97, 115, 116, 104, 101, 114, 101, 115, 116, 111, 102,
  109, 121, 97, 100, 118, 105, 99, 101, 104, 97,
  115, 110, 111, 98, 97, 115, 105, 115, 109, 111, 114, 101, 114, 101, 108,
  105, 97, 98, 108, 101, 116, 104, 97, 110, 109, 121, 111, 119, 110, 109,
  101, 97, 110, 100, 101, 114, 105, 110, 103, 101,
  120, 112, 101, 114, 105, 101, 110, 99, 101, 73, 119, 105, 108, 108, 100,
  105, 115, 112, 101, 110, 115, 101, 116, 104, 105, 115, 97, 100, 118, 105,
  99, 101, 110, 111, 119, 69, 110, 106, 111, 121,
  116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116,
  121, 111, 102, 121, 111, 117, 114, 121, 111, 117, 116, 104, 79, 104, 110,
  101, 118, 101, 114, 109, 105, 110, 100, 89,
  111, 117, 119, 105, 108, 108, 110, 111, 116, 117, 110, 100, 101, 114, 115,
  116, 97, 110, 100, 116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100,
  98, 101, 97, 117, 116, 121, 111, 102, 121, 111,
  117, 114, 121, 111, 117, 116, 104, 117, 110, 116, 105, 108, 116, 104, 101,
  121, 118, 101, 102, 97, 100, 101, 100, 66, 117, 116, 116, 114, 117, 115,
  116, 109, 101, 105, 110, 50, 48, 121, 101, 97,
  114, 115, 121, 111, 117, 108, 108, 108, 111, 111, 107, 98, 97, 99, 107, 97,
  116, 112, 104, 111, 116, 111, 115, 111, 102, 121, 111, 117, 114, 115, 101,
  108, 102, 97, 110, 100, 114, 101, 99, 97,
  108, 108, 105, 110, 97, 119, 97, 121, 121, 111, 117, 99, 97, 110, 116, 103,
  114, 97, 115, 112, 110, 111, 119, 104, 111, 119, 109, 117, 99, 104, 112,
  111, 115, 115, 105, 98, 105, 108, 105, 116,
  121, 108, 97, 121, 98, 101, 102, 111, 114, 101, 121, 111, 117, 97, 110, 100,
  104, 111, 119, 102, 97, 98, 117, 108, 111, 117, 115, 121, 111, 117, 114,
  101, 97, 108, 108, 121, 108, 111, 111, 107,
  101, 100, 89, 111, 117, 97, 114, 101, 110, 111, 116, 97, 115, 102, 97, 116,
  97, 115, 121, 111, 117, 105, 109, 97, 103, 105, 110, 101, 68, 111, 110,
  116, 119, 111, 114, 114, 121, 97, 98, 111,
  117, 116, 116, 104, 101, 102, 117, 116, 117, 114, 101, 79, 114, 119, 111,
  114, 114, 121, 98, 117, 116, 107, 110, 111, 119, 116, 104, 97, 116, 75,
  117, 114, 116, 86, 111, 110, 110, 101, 103, 117,
  116, 115, 67, 111, 109, 109, 101, 110, 99, 101, 109, 101, 110, 116, 65, 100,
  100, 114, 101, 115, 115, 97, 116, 77, 73, 84, 76, 97, 100, 105, 101, 115,
  97, 110, 100, 103, 101, 110, 116, 108,
  101, 109, 101, 110, 111, 102, 116, 104, 101, 99, 108, 97, 115, 115, 111,
  102, 57, 55, 87, 101, 97, 114, 115, 117, 110, 115, 99, 114, 101, 101, 110,
  73, 102, 73, 99, 111, 117, 108, 100, 111,
  102, 102, 101, 114, 121, 111, 117, 111, 110, 108, 121, 111, 110, 101, 116,
  105, 112, 102, 111, 114, 116, 104, 101, 102, 117, 116, 117, 114, 101, 115,
  117, 110, 115, 99, 114, 101, 101, 110, 119, 111,
  117, 108, 100, 98, 101, 105, 116, 84, 104, 101, 108, 111, 110, 103, 116,
  101, 114, 109, 98, 101, 110, 101, 102, 105, 116, 115, 111, 102, 115, 117,
  110, 115, 99, 114, 101, 101, 110, 104, 97, 118,
  101, 98, 101, 101, 110, 112, 114, 111, 118, 101, 100, 98, 121, 115, 99, 105,
  101, 110, 116, 105, 115, 116, 115, 119, 104, 101, 114, 101, 97, 115, 116,
  104, 101, 114, 101, 115, 116, 111, 102, 109,
  121, 97, 100, 118, 105, 99, 101, 104, 97, 115, 110, 111, 98, 97, 115, 105,
  115, 109, 111, 114, 101, 114, 101, 108, 105, 97, 98, 108, 101, 116, 104,
  97, 110, 109, 121, 111, 119, 110, 109, 101,
  97, 110, 100, 101, 114, 105, 110, 103, 101, 120, 112, 101, 114, 105, 101,
  110, 99, 101, 73, 119, 105, 108, 108, 100, 105, 115, 112, 101, 110, 115,
  101, 116, 104, 105, 115, 97, 100, 118, 105, 99,
  101, 110, 111, 119, 69, 110, 106, 111, 121, 116, 104, 101, 112, 111, 119,
  101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121, 111, 102, 121, 111,
  117, 114, 121, 111, 117, 116, 104, 79, 104, 110,
  101, 118, 101, 114, 109, 105, 110, 100, 89, 111, 117, 119, 105, 108, 108,
  110, 111, 116, 117, 110, 100, 101, 114, 115, 116, 97, 110, 100, 116, 104,
  101, 112, 111, 119, 101, 114, 97, 110, 100, 98,
  101, 97, 117, 116, 121, 111, 102, 121, 111, 117, 114, 121, 111, 117, 116,
  104, 117, 110, 116, 105, 108, 116, 104, 101, 121, 118, 101, 102, 97, 100,
  101, 100, 66, 117, 116, 116, 114, 117, 115, 116,
  109, 101, 105, 110, 50, 48, 121, 101, 97, 114, 115, 121, 111, 117, 108, 108,
  108, 111, 111, 107, 98, 97, 99, 107, 97, 116, 112, 104, 111, 116, 111,
  115, 111, 102, 121, 111, 117, 114, 115, 101,
  108, 102, 97, 110, 100, 114, 101, 99, 97, 108, 108, 105, 110, 97, 119, 97,
  121, 121, 111, 117, 99, 97, 110, 116, 103, 114, 97, 115, 112, 110, 111,
  119, 104, 111, 119, 109, 117, 99, 104, 112,
  111, 115, 115, 105, 98, 105, 108, 105, 116, 121, 108, 97, 121, 98, 101, 102,
  111, 114, 101, 121, 111, 117, 97, 110, 100, 104, 111, 119, 102, 97, 98,
  117, 108, 111, 117, 115, 121, 111, 117, 114,
  101, 97, 108, 108, 121, 108, 111, 111, 107, 101, 100, 89, 111, 117, 97, 114,
  101, 110, 111, 116, 97, 115, 102, 97, 116, 97, 115, 121, 111, 117, 105,
  109, 97, 103, 105, 110, 101, 68, 111, 110,
  116, 119, 111, 114, 114, 121, 97, 98, 111, 117, 116, 116, 104, 101, 102,
  117, 116, 117, 114, 101, 79, 114, 119, 111, 114, 114, 121, 98, 117, 116,
  107, 110, 111, 119, 116, 104, 97, 116, 75, 117,
  114, 116, 86, 111, 110, 110, 101, 103, 117, 116, 115, 67, 111, 109, 109,
  101, 110, 99, 101, 109, 101, 110, 116, 65, 100, 100, 114, 101, 115, 115,
  97, 116, 77, 73, 84, 76, 97, 100, 105, 101,
  115, 97, 110, 100, 103, 101, 110, 116, 108, 101, 109, 101, 110, 111, 102,
  116, 104, 101, 99, 108, 97, 115, 115, 111, 102, 57, 55, 87, 101, 97, 114,
  115, 117, 110, 115, 99, 114, 101, 101, 110,
  73, 102, 73, 99, 111, 117, 108, 100, 111, 102, 102, 101, 114, 121, 111, 117,
  111, 110, 108, 121, 111, 110, 101, 116, 105, 112, 102, 111, 114, 116, 104,
  101, 102, 117, 116, 117, 114, 101, 115, 117,
  110, 115, 99, 114, 101, 101, 110, 119, 111, 117, 108, 100, 98, 101, 105,
  116, 84, 104, 101, 108, 111, 110, 103, 116, 101, 114, 109, 98, 101, 110,
  101, 102, 105, 116, 115, 111, 102, 115, 117, 110,
  115, 99, 114, 101, 101, 110, 104, 97, 118, 101, 98, 101, 101, 110, 112, 114,
  111, 118, 101, 100, 98, 121, 115, 99, 105, 101, 110, 116, 105, 115, 116,
  115, 119, 104, 101, 114, 101, 97, 115, 116,
  104, 101, 114, 101, 115, 116, 111, 102, 109, 121, 97, 100, 118, 105, 99,
  101, 104, 97, 115, 110, 111, 98, 97, 115, 105, 115, 109, 111, 114, 101,
  114, 101, 108, 105, 97, 98, 108, 101, 116, 104,
  97, 110, 109, 121, 111, 119, 110, 109, 101, 97, 110, 100, 101, 114, 105,
  110, 103, 101, 120, 112, 101, 114, 105, 101, 110, 99, 101, 73, 119, 105,
  108, 108, 100, 105, 115, 112, 101, 110, 115, 101,
  116, 104, 105, 115, 97, 100, 118, 105, 99, 101, 110, 111, 119, 69, 110, 106,
  111, 121, 116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101,
  97, 117, 116, 121, 111, 102, 121, 111, 117,
  114, 121, 111, 117, 116, 104, 79, 104, 110, 101, 118, 101, 114, 109, 105,
  110, 100, 89, 111, 117, 119, 105, 108, 108, 110, 111, 116, 117, 110, 100,
  101, 114, 115, 116, 97, 110, 100, 116, 104, 101,
  112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121, 111, 102,
  121, 111, 117, 114, 121, 111, 117, 116, 104, 117, 110, 116, 105, 108, 116,
  104, 101, 121, 118, 101, 102, 97, 100, 101,
  100, 66, 117, 116, 116, 114, 117, 115, 116, 109, 101, 105, 110, 50, 48, 121,
  101, 97, 114, 115, 121, 111, 117, 108, 108, 108, 111, 111, 107, 98, 97,
  99, 107, 97, 116, 112, 104, 111, 116, 111,
  115, 111, 102, 121, 111, 117, 114, 115, 101, 108, 102, 97, 110, 100, 114,
  101, 99, 97, 108, 108, 105, 110, 97, 119, 97, 121, 121, 111, 117, 99, 97,
  110, 116, 103, 114, 97, 115, 112, 110, 111,
  119, 104, 111, 119, 109, 117, 99, 104, 112, 111, 115, 115, 105, 98, 105,
  108, 105, 116, 121, 108, 97, 121, 98, 101, 102, 111, 114, 101, 121, 111,
  117, 97, 110, 100, 104, 111, 119, 102, 97, 98,
  117, 108, 111, 117, 115, 121, 111, 117, 114, 101, 97, 108, 108, 121, 108,
  111, 111, 107, 101, 100, 89, 111, 117, 97, 114, 101, 110, 111, 116, 97,
  115, 102, 97, 116, 97, 115, 121, 111, 117, 105,
  109, 97, 103, 105, 110, 101, 68, 111, 110, 116, 119, 111, 114, 114, 121, 97,
  98, 111, 117, 116, 116, 104, 101, 102, 117, 116, 117, 114, 101, 79, 114,
  119, 111, 114, 114, 121, 75, 117, 114, 116,
  86, 111, 110, 110, 101, 103, 117, 116, 115, 67, 111, 109, 109, 101, 110, 99,
  101, 109, 101, 110, 116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77,
  73, 84, 76, 97, 100, 105, 101, 115, 97,
  110, 100, 103, 101, 110, 116, 108, 101, 109, 101, 110, 111, 102, 116, 104,
  101, 99, 108, 97, 115, 115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117,
  110, 115, 99, 114, 101, 101, 110, 73, 102,
  73, 99, 111, 117, 108, 100, 111, 102, 102, 101, 114, 121, 111, 117, 111,
  110, 108, 121, 111, 110, 101, 116, 105, 112, 102, 111, 114, 116, 104, 101,
  102, 117, 116, 117, 114, 101, 115, 117, 110, 115,
  99, 114, 101, 101, 110, 119, 111, 117, 108, 100, 98, 101, 105, 116, 84, 104,
  101, 108, 111, 110, 103, 116, 101, 114, 109, 98, 101, 110, 101, 102, 105,
  116, 115, 111, 102, 115, 117, 110, 115, 99,
  114, 101, 101, 110, 104, 97, 118, 101, 98, 101, 101, 110, 112, 114, 111,
  118, 101, 100, 98, 121, 115, 99, 105, 101, 110, 116, 105, 115, 116, 115,
  119, 104, 101, 114, 101, 97, 115, 116, 104, 101,
  114, 101, 115, 116, 111, 102, 109, 121, 97, 100, 118, 105, 99, 101, 104, 97,
  115, 110, 111, 98, 97, 115, 105, 115, 109, 111, 114, 101, 114, 101, 108,
  105, 97, 98, 108, 101, 116, 104, 97, 110,
  109, 121, 111, 119, 110, 109, 101, 97, 110, 100, 101, 114, 105, 110, 103,
  101, 120, 112, 101, 114, 105, 101, 110, 99, 101, 73, 119, 105, 108, 108,
  100, 105, 115, 112, 101, 110, 115, 101, 116, 104,
  105, 115, 97, 100, 118, 105, 99, 101, 110, 111, 119, 69, 110, 106, 111, 121,
  116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117,
  116, 121, 111, 102, 121, 111, 117, 114, 121,
  111, 117, 116, 104, 79, 104, 110, 101, 118, 101, 114, 109, 105, 110, 100,
  89, 111, 117, 119, 105, 108, 108, 110, 111, 116, 117, 110, 100, 101, 114,
  115, 116, 97, 110, 100, 116, 104, 101, 112, 111,
  119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121, 111, 102, 121, 111,
  117, 114, 121, 111, 117, 116, 104, 117, 110, 116, 105, 108, 116, 104, 101,
  121, 118, 101, 102, 97, 100, 101, 100, 66,
  117, 116, 116, 114, 117, 115, 116, 109, 101, 105, 110, 50, 48, 121, 101, 97,
  114, 115, 121, 111, 117, 108, 108, 108, 111, 111, 107, 98, 97, 99, 107,
  97, 116, 112, 104, 111, 116, 111, 115, 111,
  102, 121, 111, 117, 114, 115, 101, 108, 102, 97, 110, 100, 114, 101, 99, 97,
  108, 108, 105, 110, 97, 119, 97, 121, 121, 111, 117, 99, 97, 110, 116,
  103, 114, 97, 115, 112, 110, 111, 119, 104,
  111, 119, 109, 117, 99, 104, 112, 111, 115, 115, 105, 98, 105, 108, 105,
  116, 121, 108, 97, 121, 98, 101, 102, 111, 114, 101, 121, 111, 117, 97,
  110, 100, 104, 111, 119, 102, 97, 98, 117, 108,
  111, 117, 115, 121, 111, 117, 114, 101, 97, 108, 108, 121, 108, 111, 111,
  107, 101, 100, 89, 111, 117, 97, 114, 101, 110, 111, 116, 97, 115, 102,
  97, 116, 97, 115, 121, 111, 117, 105, 109, 97,
  103, 105, 110, 101, 68, 111, 110, 116, 119, 111, 114, 114, 121, 97, 98, 111,
  117, 116, 116, 104, 101, 102, 117, 116, 117, 114, 101, 79, 114, 119, 111,
  114, 114, 121, 98, 117, 116, 107, 110, 111,
  119, 116, 104, 97, 116, 75, 117, 114, 116, 86, 111, 110, 110, 101, 103, 117,
  75, 117, 114, 116, 86, 111, 110, 110, 101, 103, 117, 116, 115, 67, 111,
  109, 109, 101, 110, 99, 101, 109, 101, 110,
  116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77, 73, 84, 76, 97, 100,
  105, 101, 115, 97, 110, 100, 103, 101, 110, 116, 108, 101, 109, 101, 110,
  111, 102, 116, 104, 101, 99, 108, 97, 115,
  115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117, 110, 115, 99, 114, 101,
  101, 110, 73, 102, 73, 99, 111, 117, 108, 100, 111, 102, 102, 101, 114,
  121, 111, 117, 111, 110, 108, 121, 111, 110,
  101, 116, 105, 112, 102, 111, 114, 116, 104, 101, 102, 117, 116, 117, 114,
  101, 115, 117, 110, 115, 99, 114, 101, 101, 110, 119, 111, 117, 108, 100,
  98, 101, 105, 116, 84, 104, 101, 108, 111, 110,
  103, 116, 101, 114, 109, 98, 101, 110, 101, 102, 105, 116, 115, 111, 102,
  115, 117, 110, 115, 99, 114, 101, 101, 110, 104, 97, 118, 101, 98, 101,
  101, 110, 112, 114, 111, 118, 101, 100, 98, 121,
  115, 99, 105, 101, 110, 116, 105, 115, 116, 115, 119, 104, 101, 114, 101,
  97, 115, 116, 104, 101, 114, 101, 115, 116, 111, 102, 109, 121, 97, 100,
  118, 105, 99, 101, 104, 97, 115, 110, 111, 98,
  97, 115, 105, 115, 109, 111, 114, 101, 114, 101, 108, 105, 97, 98, 108, 101,
  116, 104, 97, 110, 109, 121, 111, 119, 110, 109, 101, 97, 110, 100, 101,
  114, 105, 110, 103, 101, 120, 112, 101, 114,
  105, 101, 110, 99, 101, 73, 119, 105, 108, 108, 100, 105, 115, 112, 101,
  110, 115, 101, 116, 104, 105, 115, 97, 100, 118, 105, 99, 101, 110, 111,
  119, 69, 110, 106, 111, 121, 116, 104, 101, 112,
  111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121, 111, 102, 121,
  111, 117, 114, 121, 111, 117, 116, 104, 79, 104, 110, 101, 118, 101, 114,
  109, 105, 110, 100, 89, 111, 117, 119, 105,
  108, 108, 110, 111, 116, 117, 110, 100, 101, 114, 115, 116, 97, 110, 100,
  116, 104, 101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117,
  116, 121, 111, 102, 121, 111, 117, 114, 121, 111,
  117, 116, 104, 117, 110, 116, 105, 108, 116, 104, 101, 121, 118, 101, 102,
  97, 100, 101, 100, 66, 117, 116, 116, 114, 117, 115, 116, 109, 101, 105,
  110, 50, 48, 121, 101, 97, 114, 115, 121, 111,
  117, 108, 108, 108, 111, 111, 107, 98, 97, 99, 107, 97, 116, 112, 104, 111,
  116, 111, 115, 111, 102, 121, 111, 117, 114, 115, 101, 108, 102, 97, 110,
  100, 114, 101, 99, 97, 108, 108, 105, 110,
  97, 119, 97, 121, 121, 111, 117, 99, 97, 110, 116, 103, 114, 97, 115, 112,
  110, 111, 119, 104, 111, 119, 109, 117, 99, 104, 112, 111, 115, 115, 105,
  98, 105, 108, 105, 116, 121, 108, 97, 121,
  98, 101, 102, 111, 114, 101, 121, 111, 117, 97, 110, 100, 104, 111, 119,
  102, 97, 98, 117, 108, 111, 117, 115, 121, 111, 117, 114, 101, 97, 108,
  108, 121, 108, 111, 111, 107, 101, 100, 89, 111,
  117, 97, 114, 101, 110, 111, 116, 97, 115, 102, 97, 116, 97, 115, 121, 111,
  117, 105, 109, 97, 103, 105, 110, 101, 68, 111, 110, 116, 119, 111, 114,
  114, 121, 97, 98, 111, 117, 116, 116, 104,
  101, 102, 117, 116, 117, 114, 101, 79, 114, 119, 111, 114, 114, 121, 98,
  117, 116, 107, 110, 111, 119, 116, 104, 97, 116, 75, 117, 114, 116, 86,
  111, 110, 110, 101, 103, 117, 116, 115, 67, 111,
  109, 109, 101, 110, 99, 101, 109, 101, 110, 116, 65, 100, 100, 114, 101,
  115, 115, 97, 116, 77, 73, 84, 76, 97, 100, 105, 101, 115, 97, 110, 100,
  103, 101, 110, 116, 108, 101, 109, 101, 110,
  111, 102, 116, 104, 101, 99, 108, 97, 115, 115, 111, 102, 57, 55, 87, 101,
  97, 114, 115, 117, 110, 115, 99, 114, 101, 101, 110, 73, 102, 73, 99, 111,
  117, 108, 100, 111, 102, 102, 101, 114,
  121, 111, 117, 111, 110, 108, 121, 111, 110, 101, 116, 105, 112, 102, 111,
  114, 116, 104, 101, 102, 117, 116, 117, 114, 101, 115, 117, 110, 115, 99,
  114, 101, 101, 110, 119, 111, 117, 108, 100, 98,
  101, 105, 116, 84, 104, 101, 108, 111, 110, 103, 116, 101, 114, 109, 98,
  101, 110, 101, 102, 105, 116, 115, 111, 102, 115, 117, 110, 115, 99, 114,
  101, 101, 110, 104, 97, 118, 101, 98, 101, 101,
  110, 112, 114, 111, 118, 101, 100, 98, 121, 115, 99, 105, 101, 110, 116,
  105, 115, 116, 115, 119, 104, 101, 114, 101, 97, 115, 116, 104, 101, 114,
  101, 115, 116, 111, 102, 109, 121, 97, 100, 118,
  105, 99, 101, 104, 97, 115, 110, 111, 98, 97, 115, 105, 115, 109, 111, 114,
  101, 114, 101, 108, 105, 97, 98, 108, 101, 116, 104, 97, 110, 109, 121,
  111, 119, 110, 109, 101, 97, 110, 100, 101,
  114, 105, 110, 103, 101, 120, 112, 101, 114, 105, 101, 110, 99, 101, 73,
  119, 105, 108, 108, 100, 105, 115, 112, 101, 110, 115, 101, 116, 104, 105,
  115, 97, 100, 118, 105, 99, 101, 110, 111, 119,
  69, 110, 106, 111, 121, 116, 104, 101, 112, 111, 119, 101, 114, 97, 110,
  100, 98, 101, 97, 117, 116, 121, 111, 102, 121, 111, 117, 114, 121, 111,
  117, 116, 104, 79, 104, 110, 101, 118, 101, 114,
  109, 105, 110, 100, 89, 111, 117, 119, 105, 108, 108, 110, 111, 116, 117,
  110, 100, 101, 114, 115, 116, 97, 110, 100, 116, 104, 101, 112, 111, 119,
  101, 114, 97, 110, 100, 98, 101, 97, 117, 116,
  121, 111, 102, 121, 111, 117, 114, 121, 111, 117, 116, 104, 117, 110, 116,
  105, 108, 116, 104, 101, 121, 118, 101, 102, 97, 100, 101, 100, 66, 117,
  116, 116, 114, 117, 115, 116, 109, 101, 105, 110,
  50, 48, 121, 101, 97, 114, 115, 121, 111, 117, 108, 108, 108, 111, 111, 107,
  98, 97, 99, 107, 97, 116, 112, 104, 111, 116, 111, 115, 111, 102, 121,
  111, 117, 114, 115, 101, 108, 102, 97, 110,
  100, 114, 101, 99, 97, 108, 108, 105, 110, 97, 119, 97, 121, 121, 111, 117,
  99, 97, 110, 116, 103, 114, 97, 115, 112, 110, 111, 119, 104, 111, 119,
  109, 117, 99, 104, 112, 111, 115, 115, 105,
  98, 105, 108, 105, 116, 121, 108, 97, 121, 98, 101, 102, 111, 114, 101, 121,
  111, 117, 97, 110, 100, 104, 111, 119, 102, 97, 98, 117, 108, 111, 117,
  115, 121, 111, 117, 114, 101, 97, 108, 108,
  121, 108, 111, 111, 107, 101, 100, 89, 111, 117, 97, 114, 101, 110, 111,
  116, 97, 115, 102, 97, 116, 97, 115, 121, 111, 117, 105, 109, 97, 103,
  105, 110, 101, 68, 111, 110, 116, 119, 111, 114,
  114, 121, 97, 98, 111, 117, 116, 116, 104, 101, 102, 117, 116, 117, 114,
  101, 79, 114, 119, 111, 114, 114, 121, 98, 117, 116, 107, 110, 111, 119,
  116, 104, 97, 116, 75, 117, 114, 116, 86, 111,
  110, 110, 101, 103, 117, 116, 115, 67, 111, 109, 109, 101, 110, 99, 101,
  109, 101, 110, 116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77, 73, 84,
  76, 97, 100, 105, 101, 115, 97, 110, 100,
  103, 101, 110, 116, 108, 101, 109, 101, 110, 111, 102, 116, 104, 101, 99,
  108, 97, 115, 115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117, 110, 115,
  99, 114, 101, 101, 110, 73, 102, 73, 99,
  111, 117, 108, 100, 111, 102, 102, 101, 114, 121, 111, 117, 111, 110, 108,
  121, 111, 110, 101, 116, 105, 112, 102, 111, 114, 116, 104, 101, 102, 117,
  116, 117, 114, 101, 115, 117, 110, 115, 99, 114,
  101, 101, 110, 119, 111, 117, 108, 100, 98, 101, 105, 116, 84, 104, 101,
  108, 111, 110, 103, 116, 101, 114, 109, 98, 101, 110, 101, 102, 105, 116,
  115, 111, 102, 115, 117, 110, 115, 99, 114, 101,
  101, 110, 104, 97, 118, 101, 98, 101, 101, 110, 112, 114, 111, 118, 101,
  100, 98, 121, 115, 99, 105, 101, 110, 116, 105, 115, 116, 115, 119, 104,
  101, 114, 101, 97, 115, 116, 104, 101, 114, 101,
  115, 116, 111, 102, 109, 121, 97, 100, 118, 105, 99, 101, 104, 97, 115, 110,
  111, 98, 97, 115, 105, 115, 109, 111, 114, 101, 114, 101, 108, 105, 97,
  98, 108, 101, 116, 104, 97, 110, 109, 121,
  111, 119, 110, 109, 101, 97, 110, 100, 101, 114, 105, 110, 103, 101, 120,
  112, 101, 114, 105, 101, 110, 99, 101, 73, 119, 105, 108, 108, 100, 105,
  115, 112, 101, 110, 115, 101, 116, 104, 105, 115,
  97, 100, 118, 105, 99, 101, 110, 111, 119, 69, 110, 106, 111, 121, 116, 104,
  101, 112, 111, 119, 101, 114, 97, 110, 100, 98, 101, 97, 117, 116, 121,
  111, 102, 121, 111, 117, 114, 121, 111, 117,
  116, 104, 79, 104, 110, 101, 118, 101, 114, 109, 105, 110, 100, 89, 111,
  117, 119, 105, 108, 108, 110, 111, 116, 117, 110, 100, 101, 114, 115, 116,
  97, 110, 100, 116, 104, 101, 112, 111, 119, 101,
  114, 97, 110, 100, 98, 101, 97, 117, 116, 121, 111, 102, 121, 111, 117, 114,
  121, 111, 117, 116, 104, 117, 110, 116, 105, 108, 116, 104, 101, 121, 118,
  101, 102, 97, 100, 101, 100, 66, 117, 116,
  116, 114, 117, 115, 116, 109, 101, 105, 110, 50, 48, 121, 101, 97, 114, 115,
  121, 111, 117, 108, 108, 108, 111, 111, 107, 98, 97, 99, 107, 97, 116,
  112, 104, 111, 116, 111, 115, 111, 102, 121,
  111, 117, 114, 115, 101, 108, 102, 97, 110, 100, 114, 101, 99, 97, 108, 108,
  105, 110, 97, 119, 97, 121, 121, 111, 117, 99, 97, 110, 116, 103, 114, 97,
  115, 112, 110, 111, 119, 104, 111, 119,
  109, 117, 99, 104, 112, 111, 115, 115, 105, 98, 105, 108, 105, 116, 121,
  108, 97, 121, 98, 101, 102, 111, 114, 101, 121, 111, 117, 97, 110, 100,
  104, 111, 119, 102, 97, 98, 117, 108, 111, 117,
  115, 121, 111, 117, 114, 101, 97, 108, 108, 121, 108, 111, 111, 107, 101,
  100, 89, 111, 117, 97, 114, 101, 110, 111, 116, 97, 115, 102, 97, 116, 97,
  115, 121, 111, 117, 105, 109, 97, 103, 105,
  110, 101, 68, 111, 110, 116, 119, 111, 114, 114, 121, 97, 98, 111, 117, 116,
  116, 104, 101, 102, 117, 116, 117, 114, 101, 79, 114, 119, 111, 114, 114,
  121, 98, 117, 116, 107, 110, 111, 119, 116,
  104, 97, 116, 116, 115, 67, 111, 109, 109, 101, 110, 99, 101, 109, 101, 110,
  116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77, 73, 84, 76, 97, 100,
  105, 101, 115, 97, 110, 100, 103, 101,
  110, 116, 108, 101, 109, 101, 110, 111, 102, 116, 104, 101, 99, 108, 97,
  115, 115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117, 110, 115, 99, 114,
  101, 101, 110, 73, 102, 73, 99, 111, 117,
  108, 100, 111, 102, 102, 101, 114, 121, 111, 117, 111, 110, 108, 121, 111,
  110, 101, 116, 105, 112, 102, 111, 114, 116, 104, 101, 102, 117, 116, 117,
  114, 101, 75, 117, 114, 116, 86, 111, 110, 110,
  101, 103, 117, 116, 115, 67, 111, 109, 109, 101, 110, 99, 101, 109, 101,
  110, 116, 65, 100, 100, 114, 101, 115, 115, 97, 116, 77, 73, 84, 76, 97,
  100, 105, 101, 115, 97, 110, 100, 103, 101,
  110, 116, 108, 101, 109, 101, 110, 111, 102, 116, 104, 101, 99, 108, 97,
  115, 115, 111, 102, 57, 55, 87, 101, 97, 114, 115, 117, 110, 115, 99, 114,
  101, 101, 110, 73, 102, 73, 99, 111, 117,
  108, 100, 111, 102, 102, 101, 114, 121, 111, 117, 111, 110, 108, 121, 111,
  110, 101, 116, 105, 112, 102, 111, 114, 116, 104, 101, 102, 117, 116, 117,
  114, 101, 115, 117, 110, 115, 99, 114, 101, 101,
  110, 119, 111, 117, 108, 100, 98, 101, 105, 116, 84, 104, 101, 108, 111,
  110, 103, 116, 101, 114, 109, 98, 101, 110, 101, 102, 105, 116, 115, 111,
  102, 115, 117, 110, 115, 99, 114, 101, 101, 110,
  104, 97, 118, 101, 98, 101, 101, 110, 112, 114, 111, 118, 101, 100, 98, 121,
  115, 99, 105, 101, 110, 116, 105, 115, 116, 115, 119, 104, 101, 114, 101,
  97, 115, 116, 104, 101, 114, 101, 115, 116
};

const unsigned char out_key[KEYSIZE] = {
  5, 140, 229, 49, 55, 247, 179, 22, 234, 116, 197, 105, 104, 250, 30, 106,
  253, 124, 41, 105, 239, 252, 189, 239, 182, 63, 187, 140, 239, 253, 142,
  216, 26, 137, 170, 225, 52, 248, 13, 173, 77, 52, 249, 67, 194, 246, 207,
  5, 77, 17, 170, 24, 33, 72, 252, 9, 28, 7, 33, 144, 57, 125, 250, 143, 48,
  87, 203, 193, 205, 203, 207, 202, 214, 135, 56, 19, 76, 251, 100, 122,
  141, 135, 103, 210, 173, 79, 109, 16, 204, 155, 2, 12, 35, 122, 247, 66,
  212, 30, 183, 207, 142, 201, 255, 49, 229, 209, 56, 213, 171, 232, 181,
  122, 62, 42, 75, 53, 136, 234, 3, 44, 18, 8, 134, 160, 193, 222, 92, 151,
  93, 238, 76, 67, 186, 145, 29, 184, 214, 173, 178, 49, 41, 251, 128, 185,
  191, 49, 112, 223, 252, 85, 219, 95, 68, 104, 210, 3, 19, 55, 127, 76, 74,
  12, 180, 22, 124, 252, 46, 170, 55, 0, 55, 202, 144, 232, 179, 200, 201,
  206, 37, 219, 195, 98, 77, 154, 157, 22, 39, 169, 66, 87, 204, 150, 25,
  81, 214, 145, 163, 154, 166, 220, 26, 93, 42, 35, 1, 143, 178, 133, 3, 11,
  53, 184, 8, 143, 207, 230, 43, 188, 71, 56, 56, 241, 230, 126, 180, 101,
  134, 122, 171, 217, 173, 221, 56, 46, 166, 240, 159, 29, 181, 228, 119,
  240, 208, 10, 188, 164, 1, 57, 74, 15, 9, 138, 82, 251, 149, 246, 57, 28,
  70, 243, 168, 144, 194, 107, 213, 112, 103, 186, 175, 59, 187, 250, 90,
  239, 73, 230, 133, 173, 195, 92, 211, 142, 163, 226, 184, 237, 115, 57,
  16, 17, 43, 188, 186, 133, 165, 50, 195, 19, 68, 36, 153, 178, 15, 52, 85,
  52, 123, 93, 125, 86, 36, 138, 53, 59, 161, 161, 26, 178, 203, 228, 27,
  37, 140, 67, 236, 7, 182, 88, 71, 139, 228, 22, 15, 147, 220, 18, 132,
  111, 13, 249, 40, 1, 111, 5, 140, 38, 107, 6, 249, 230, 130, 71, 178, 81,
  39, 40, 28, 217, 216, 118, 159, 228, 208, 121, 10, 56, 105, 11, 1, 167,
  105, 64, 209, 44, 86, 191, 237, 254, 101, 25, 126, 161, 37, 54, 12, 87,
  156, 150, 155, 69, 52, 112, 234, 143, 149, 41, 15, 45, 211, 165, 189, 162,
  137, 166, 188, 175, 128, 224, 32, 153, 128, 190, 169, 130, 127, 191, 238,
  223, 146, 155, 177, 142, 176, 78, 229, 52, 96, 141, 119, 223, 36, 10, 24,
  15, 245, 128, 7, 196, 106, 100, 30, 32, 63, 132, 88, 133, 250, 195, 137,
  34, 92, 219, 20, 117, 81, 216, 181, 116, 241, 78, 131, 178, 34, 138, 206,
  10, 144, 51, 210, 108, 111, 122, 116, 49, 213, 152, 232, 228, 20, 245,
  122, 212, 225, 173, 190, 152, 21, 61, 61, 179, 173, 71, 110, 38, 7, 198,
  157, 153, 207, 87, 17, 42, 42, 215, 18, 208, 90, 172, 157, 23, 46, 37,
  166, 218, 65, 25, 136, 173, 85, 149, 105, 54, 20, 218, 6, 65, 184, 239,
  46, 38, 157, 68, 240, 228, 117, 224, 19, 153, 3, 34, 233, 47, 57, 103, 79,
  17, 208, 223, 92, 30, 111, 127, 61, 205, 212, 232, 5, 207, 107, 158, 81,
  192, 135, 67, 75, 60, 118, 68, 51, 30, 200, 176, 187, 62, 1, 100, 173, 63,
  118, 31, 108, 139, 138, 248, 233, 81, 244, 36, 241, 231, 58, 154, 201,
  110, 9, 39, 86, 227, 73, 60, 61, 40, 80, 195, 224, 187, 55, 154, 72, 104,
  218, 60, 253, 248, 216, 90, 44, 213, 78, 177, 148, 76, 244, 57, 170, 1,
  166, 75, 206, 123, 166, 206, 135, 221, 33, 130, 26, 148, 148, 224, 117,
  56, 75, 151, 50, 90, 49, 4, 48, 255, 147, 42, 183, 58, 76, 131, 16, 109,
  222, 86, 85, 134, 253, 209, 74, 17, 220, 238, 82, 200, 140, 89, 210, 117,
  174, 180, 68, 6, 163, 9, 249, 249, 51, 124, 182, 53, 6, 61, 39, 190, 10,
  40, 63, 207, 92, 189, 30, 69, 49, 8, 233, 116, 121, 80, 149, 169, 72, 164,
  203, 152, 71, 201, 169, 144, 205, 83, 10, 214, 213, 0, 147, 32, 62, 91,
  162, 164, 160, 211, 196, 159, 166, 9, 73, 221, 79, 117, 116, 20, 103, 112,
  80, 147, 226, 205, 25, 108, 210, 61, 163, 46, 57, 102, 185, 126, 3, 6, 27,
  118, 139, 113, 67, 62, 4, 242, 88, 152, 95, 92, 142, 233, 139, 34, 177,
  244, 130, 12, 4, 83, 29, 168, 171, 15, 70, 115, 216, 36, 218, 106, 213,
  92, 215, 215, 43, 155, 200, 77, 198, 68, 37, 255, 215, 62, 154, 52, 251,
  198, 148, 55, 207, 79, 99, 243, 135, 43, 64, 204, 179, 106, 144, 78, 120,
  94, 233, 160, 200, 92, 191, 50, 43, 129, 229, 168, 194, 48, 131, 78, 228,
  163, 157, 96, 175, 203, 189, 205, 81, 238, 82, 61, 84, 84, 111, 217, 163,
  7, 18, 77, 156, 41, 209, 47, 10, 250, 58, 236, 187, 248, 212, 131, 60, 52,
  126, 180, 113, 207, 135, 112, 192, 190, 177, 68, 171, 77, 219, 253, 105,
  12, 157, 222, 32, 159, 92, 185, 88, 192, 113, 39, 18, 77, 215, 112, 223,
  114, 128, 102, 42, 219, 15, 127, 23, 114, 152, 125, 254, 12, 52, 78, 242,
  74, 130, 125, 138, 18, 44, 152, 12, 236, 117, 194, 83, 192, 255, 109, 223,
  237, 31, 203, 170, 40, 188, 90, 46, 196, 124, 243, 153, 127, 247, 116,
  174, 67, 233, 199, 148, 111, 68, 60, 78, 196, 119, 159, 218, 85, 112, 9,
  20, 70, 168, 77, 46, 26, 39, 19, 10, 172, 159, 135, 10, 126, 25, 133, 207,
  193, 32, 153, 125, 101, 51, 85, 78, 78, 76, 145, 186, 102, 249, 78, 182,
  138, 224, 17, 207, 21, 205, 50, 139, 223, 5, 196, 78, 254, 239, 82, 129,
  222, 22, 146, 245, 178, 205, 169, 168, 138, 147, 24, 111, 69, 94, 113,
  190, 157, 82, 233, 87, 134, 149, 253, 91, 161, 128, 45, 254, 81, 75, 102,
  26, 154, 159, 73, 163, 198, 6, 27, 84, 136, 165, 116, 190, 234, 17, 160,
  0, 237, 120, 150, 252, 123, 174, 238, 136, 29, 226, 211, 20, 86, 104, 122,
  135, 241, 17, 229, 207, 122, 66, 137, 164, 26, 1, 90, 106, 143, 182, 69,
  160, 186, 10, 231, 57, 79, 226, 209, 186, 123, 82, 231, 228, 66, 239, 214,
  104, 200, 97, 1, 229, 102, 128, 77, 105, 54, 118, 58, 85, 36, 239, 133,
  35, 4, 208, 141, 19, 177, 172, 108, 109, 158, 39, 67, 70, 48, 175, 212,
  181, 75, 50, 248, 98, 94, 161, 124, 249, 187, 158, 137, 78, 35, 142, 90,
  130, 113, 121, 63, 37, 75, 93, 174, 22, 116, 115, 105, 215, 221, 147, 117,
  40, 142, 38, 105, 43, 154, 169, 39, 80, 46, 54, 6, 153, 143, 248, 193,
  110, 232, 77, 140, 97, 20, 122, 253, 82, 80, 205, 249, 140, 168, 142, 2,
  223, 155, 128, 75, 248, 75, 168, 70, 113, 130, 196, 104, 101, 111, 182,
  38, 250, 55, 24, 156, 73, 175, 78, 54, 10, 2, 142, 253, 206, 4, 203, 177,
  223, 95, 231, 45, 12, 123, 121, 237, 149, 191, 49, 93, 82, 157, 85, 85,
  150, 34, 241, 236, 87, 9, 188, 172, 151, 95, 88, 0, 96, 233, 215, 130,
  247, 157, 10, 30, 153, 249, 198, 159, 188, 47, 80, 175, 219, 171, 55, 172,
  214, 231, 54, 88, 50, 87, 113, 84, 10, 35, 170, 122, 95, 172, 73, 224, 97,
  98, 40, 154, 135, 94, 138, 109, 51, 189, 149, 176, 52, 157, 107, 24, 24,
  29, 162, 83, 20, 228, 197, 163, 163, 238, 110, 166, 213, 132, 35, 170, 64,
  242, 159, 44, 95, 224, 242, 254, 122, 158, 181, 214, 216, 224, 3, 35, 116,
  226, 246, 19, 248, 231, 154, 189, 72, 33, 31, 169, 34, 204, 99, 76, 10,
  53, 126, 52, 168, 112, 187, 51, 173, 10, 102, 170, 247, 18, 78, 234, 54,
  211, 165, 112, 68, 85, 113, 248, 165, 90, 95, 20, 73, 121, 40, 238, 115,
  29, 127, 223, 179, 252, 77, 107, 41, 233, 119, 239, 75, 208, 61, 188, 201,
  35, 230, 215, 3, 203, 141, 124, 210, 180, 252, 0, 244, 148, 190, 96, 45,
  218, 234, 120, 143, 136, 0, 63, 71, 215, 9, 233, 27, 226, 29, 255, 112,
  64, 236, 165, 65, 39, 106, 34, 34, 251, 252, 188, 32, 22, 248, 150, 68,
  92, 9, 7, 51, 205, 132, 0, 6, 163, 147, 64, 96, 168, 207, 235, 109, 138,
  29, 14, 222, 104, 141, 97, 183, 117, 142, 38, 24, 192, 54, 206, 104, 2,
  60, 14, 77, 234, 182, 41, 16, 192, 3, 11, 212, 104, 224, 47, 27, 103, 213,
  167, 183, 122, 62, 130, 179, 122, 238, 33, 222, 93, 207, 238, 117, 105,
  121, 98, 103, 89, 63, 132, 168, 32, 102, 244, 240, 17, 11, 169, 78, 167,
  247, 253, 226, 174, 213, 116, 125, 99, 26, 104, 54, 38, 252, 208, 135,
  176, 93, 10, 29, 99, 217, 155, 198, 41, 244, 42, 99, 20, 233, 212, 193,
  175, 27, 123, 120, 187, 155, 167, 14, 70, 225, 203, 18, 129, 59, 177, 135,
  0, 253, 4, 127, 159, 55, 87, 215, 194, 208, 4, 233, 94, 45, 130, 213, 231,
  90, 204, 99, 90, 41, 166, 93, 8, 26, 16, 124, 14, 31, 133, 16, 184, 128,
  209, 178, 247, 223, 211, 9, 126, 96, 26, 86, 43, 126, 17, 122, 13, 90,
  107, 153, 193, 86, 38, 19, 217, 117, 72, 241, 184, 164, 142, 164, 169,
  236, 226, 114, 169, 22, 230, 168, 113, 128, 3, 166, 49, 94, 71, 45, 161,
  32, 77, 164, 126, 197, 226, 131, 188, 176, 114, 127, 31, 162, 200, 168,
  107, 131, 88, 62, 248, 72, 131, 225, 113, 146, 189, 252, 104, 148, 17, 54,
  60, 191, 206, 161, 113, 85, 201, 26, 201, 124, 23, 145, 134, 18, 187, 143,
  35, 246, 74, 116, 43, 37, 104, 247, 250, 47, 59, 251, 147, 96, 205, 207,
  132, 202, 97, 188, 169, 134, 15, 95, 186, 31, 156, 183, 0, 241, 131, 134,
  0, 60, 150, 147, 59, 17, 154, 73, 245, 18, 60, 180, 181, 113, 199, 143,
  96, 162, 197, 249, 64, 37, 174, 217, 48, 23, 125, 141, 213, 227, 250, 139,
  194, 76, 234, 22, 185, 238, 114, 88, 11, 63, 8, 88, 218, 81, 49, 31, 214,
  212, 61, 39, 191, 199, 97, 63, 47, 94, 252, 197, 2, 95, 243, 50, 151, 254,
  53, 244, 196, 57, 60, 48, 84, 14, 85, 210, 163, 49, 214, 71, 191, 159,
  239, 165, 66, 155, 85, 240, 92, 90, 58, 120, 18, 203, 188, 80, 38, 188,
  177, 112, 176, 104, 159, 214, 211, 49, 92, 122, 65, 176, 56, 70, 32, 153,
  69, 12, 137, 199, 159, 70, 242, 180, 60, 116, 235, 100, 88, 250, 67, 225,
  104, 129, 73, 155, 170, 100, 123, 243, 47, 17, 10, 137, 184, 62, 3, 243,
  52, 244, 147, 118, 184, 23, 7, 22, 68, 206, 41, 167, 203, 166, 226, 214,
  179, 243, 249, 22, 118, 224, 103, 56, 56, 6, 246, 47, 40, 107, 192, 56,
  21, 52, 166, 220, 103, 219, 84, 210, 20, 25, 86, 38, 177, 157, 192, 163,
  67, 170, 96, 42, 119, 203, 205, 140, 216, 235, 228, 138, 42, 179, 125, 73,
  112, 199, 180, 38, 159, 100, 92, 144, 158, 240, 183, 206, 42, 240, 206,
  246, 182, 64, 57, 73, 102, 164, 229, 140, 89, 219, 234, 99, 169, 110, 124,
  93, 187, 91, 5, 197, 88, 41, 1, 66, 146, 14, 130, 112, 190, 28, 17, 121,
  217, 113, 31, 235, 205, 164, 192, 101, 248, 130, 49, 57, 239, 87, 6, 117,
  129, 118, 61, 213, 219, 48, 69, 113, 183, 50, 63, 154, 227, 103, 129, 67,
  113, 152, 247, 179, 81, 136, 234, 96, 146, 93, 139, 195, 107, 218, 150,
  43, 129, 31, 83, 57, 171, 234, 11, 90, 70, 168, 0, 210, 130, 61, 110, 215,
  251, 161, 61, 146, 115, 154, 161, 173, 138, 66, 246, 61, 16, 80, 74, 118,
  103, 144, 216, 219, 112, 55, 213, 48, 245, 201, 240, 77, 95, 231, 217,
  204, 206, 52, 227, 247, 58, 129, 101, 231, 39, 179, 187, 66, 114, 90, 193,
  69, 203, 202, 252, 98, 130, 146, 161, 54, 73, 171, 169, 201, 24, 125, 17,
  232, 185, 65, 27, 212, 225, 142, 96, 83, 23, 141, 91, 154, 161, 82, 253,
  250, 154, 50, 85, 221, 27, 181, 168, 115, 243, 249, 24, 229, 154, 136,
  115, 110, 22, 215, 166, 63, 19, 19, 201, 187, 59, 84, 17, 129, 112, 146,
  99, 19, 176, 207, 119, 11, 221, 214, 6, 22, 135, 225, 145, 116, 61, 101,
  128, 86, 218, 210, 110, 98, 19, 196, 117, 248, 198, 13, 150, 109, 30, 110,
  52, 63, 220, 170, 214, 226, 98, 151, 123, 196, 233, 165, 198, 142, 75, 5,
  188, 241, 159, 34, 56, 101, 61, 61, 208, 140, 179, 25, 137, 133, 126, 176,
  166, 24, 206, 133, 61, 93, 128, 255, 216, 97, 7, 51, 251, 48, 77, 208,
  139, 158, 187, 216, 216, 159, 10, 114, 243, 31, 248, 81, 160, 119, 189,
  223, 75, 79, 45, 13, 135, 193, 229, 247, 146, 241, 114, 63, 65, 34, 103,
  96, 197, 5, 15, 228, 45, 208, 200, 201, 149, 74, 46, 99, 182, 201, 143,
  184, 44, 158, 59, 55, 53, 10, 249, 119, 8, 239, 174, 244, 168, 15, 150,
  65, 182, 186, 50, 9, 197, 176, 240, 243, 177, 181, 82, 251, 12, 35, 244,
  23, 158, 62, 152, 43, 237, 51, 211, 29, 207, 90, 156, 11, 80, 199, 193,
  116, 230, 151, 152, 253, 244, 86, 155, 8, 246, 184, 99, 43, 64, 196, 93,
  91, 169, 5, 237, 2, 58, 208, 89, 225, 206, 31, 28, 145, 32, 74, 48, 19,
  51, 198, 183, 239, 52, 216, 188, 152, 93, 110, 140, 45, 146, 49, 31, 172,
  117, 50, 8, 68, 204, 3, 219, 117, 40, 195, 232, 179, 200, 186, 120, 55, 1,
  98, 168, 120, 112, 182, 218, 222, 77, 113, 255, 189, 0, 145, 88, 72, 199,
  87, 204, 105, 46, 188, 77, 77, 183, 21, 86, 50, 217, 195, 10, 215, 29,
  174, 155, 62, 219, 72, 127, 181, 80, 179, 177, 175, 56, 213, 65, 60, 99,
  177, 55, 13, 205, 246, 35, 202, 103, 215, 113, 109, 185, 87, 185, 90, 1,
  74, 88, 149, 187, 230, 81, 3, 135, 170, 73, 70, 113, 118, 183, 250, 209,
  208, 248, 17, 196, 36, 188, 128, 185, 49, 134, 150, 109, 195, 14, 193,
  142, 43, 5, 117, 148, 15, 44, 146, 145, 162, 124, 202, 239, 125, 205, 130,
  189, 221, 253, 171, 73, 36, 127, 35, 12, 230, 153, 159, 37, 227, 82, 188,
  226, 108, 182, 130, 61, 109, 126, 142, 254, 243, 43, 88, 172, 30, 193,
  120, 152, 144, 252, 40, 31, 19, 181, 118, 27, 67, 167, 254, 242, 98, 87,
  192, 22, 173, 173, 129, 9, 112, 118, 90, 142, 175, 41, 80, 198, 23, 17,
  83, 197, 163, 252, 4, 122, 249, 125, 71, 27, 87, 71, 25, 237, 131, 144,
  189, 244, 140, 222, 11, 95, 136, 166, 112, 88, 4, 27, 250, 7, 221, 159,
  118, 34, 181, 112, 11, 64, 222, 95, 71, 127, 210, 89, 11, 73, 127, 217,
  215, 250, 135, 223, 224, 155, 28, 210, 170, 127, 45, 124, 148, 155, 124,
  131, 63, 122, 133, 21, 47, 147, 36, 189, 176, 145, 73, 8, 31, 197, 138,
  43, 160, 163, 46, 72, 48, 26, 56, 171, 138, 52, 22, 183, 191, 234, 107,
  230, 202, 87, 255, 108, 172, 132, 164, 154, 136, 200, 85, 131, 4, 188,
  106, 1, 213, 42, 49, 221, 70, 222, 112, 99, 71, 105, 206, 13, 103, 223,
  37, 104, 36, 97, 253, 149, 222, 81, 232, 233, 228, 223, 136, 123, 201, 10,
  51, 175, 80, 168, 198, 238, 40, 161, 113, 170, 46, 144, 194, 218, 152, 80,
  2, 228, 221, 68, 191, 91, 81, 21, 216, 68, 156, 117, 145, 88, 111, 241,
  201, 33, 158, 35, 245, 69, 140, 162, 43, 108, 46, 119, 69, 224, 121, 136,
  77, 60, 118, 219, 151, 147, 79, 161, 234, 193, 46, 216, 223, 241, 235, 15,
  227, 27, 71, 234, 235, 163, 143, 130, 106, 244, 202, 23, 222, 185, 52,
  109, 150, 43, 81, 68, 218, 162, 175, 76, 165, 133, 232, 172, 104, 240,
  226, 134, 16, 186, 202, 60, 42, 91, 209, 128, 4, 255, 126, 156, 142, 240,
  143, 224, 240, 6, 99, 63, 215, 74, 71, 57, 18, 25, 69, 147, 86, 156, 252,
  157, 227, 171, 157, 16, 97, 101, 77, 70, 218, 212, 50, 68, 151, 107, 173,
  140, 221, 186, 217, 39, 38, 23, 217, 75, 251, 73, 178, 6, 226, 9, 187,
  228, 75, 198, 93, 191, 180, 26, 29, 61, 215, 135, 0, 236, 65, 44, 44, 178,
  24, 2, 98, 92, 151, 250, 68, 45, 196, 178, 174, 95, 57, 217, 88, 109, 163,
  237, 97, 202, 146, 231, 39, 197, 27, 242, 111, 191, 11, 209, 2, 157, 4,
  26, 53, 147, 250, 142, 66, 205, 77, 230, 84, 149, 54, 61, 20, 212, 64, 63,
  241, 99, 236, 186, 120, 28, 46, 209, 123, 254, 86, 98, 0, 138, 191, 2,
  182, 250, 179, 66, 223, 193, 128, 255, 15, 99, 4, 10, 178, 133, 157, 14,
  32, 203, 42, 221, 160, 7, 178, 47, 76, 139, 131, 108, 252, 88, 144, 41,
  19, 219, 168, 209, 248, 193, 129, 87, 178, 121, 56, 132, 81, 36, 95, 30,
  94, 242, 77, 224, 115, 59, 208, 142, 175, 107, 199, 192, 102, 148, 26, 36,
  167, 213, 108, 105, 185, 99, 180, 100, 172, 163, 239, 248, 232, 54, 169,
  182, 252, 134, 84, 112, 66, 26, 26, 83, 143, 162, 198, 214, 2, 238, 137,
  195, 165, 17, 35, 221, 8, 101, 32, 60, 84, 138, 142, 102, 241, 35, 254,
  168, 190, 110, 62, 58, 48, 228, 105, 219, 58, 159, 176, 162, 226, 32, 85,
  218, 125, 124, 221, 39, 175, 59, 247, 110, 182, 130, 30, 74, 16, 141, 232,
  113, 203, 141, 234, 42, 90, 251, 56, 93, 1, 155, 255, 4, 61, 67, 16, 45,
  233, 195, 74, 14, 148, 118, 247, 224, 170, 141, 226, 83, 190, 209, 90, 52,
  225, 120, 201, 238, 76, 205, 12, 56, 42, 84, 122, 94, 236, 24, 124, 135,
  162, 216, 144, 5, 231, 108, 160, 33, 196, 99, 2, 253, 175, 57, 59, 5, 5,
  229, 22, 241, 38, 124, 184, 65, 82, 96, 211, 145, 15, 28, 127, 144, 231,
  172, 111, 184, 251, 71, 214, 144, 96, 120, 141, 128, 86, 97, 84, 138, 124,
  170, 163, 19, 11, 182, 182, 109, 254, 119, 233, 73, 111, 148, 9, 76, 180,
  118, 20, 29, 186, 3, 239, 245, 179, 123, 131, 15, 203, 215, 64, 58, 103,
  141, 29, 1, 206, 182, 168, 211, 118, 152, 246, 68, 115, 160, 39, 15, 34,
  137, 174, 170, 139, 118, 205, 18, 166, 228, 84, 142, 89, 177, 201, 13,
  163, 68, 179, 220, 63, 186, 100, 26, 205, 147, 241, 125, 188, 114, 166,
  168, 214, 101, 148, 64, 255, 32, 213, 2, 39, 51, 54, 98, 73, 189, 113, 14,
  105, 86, 224, 105, 177, 50, 53, 137, 173, 153, 113, 215, 6, 112, 129, 113,
  254, 98, 74, 119, 15, 247, 114, 237, 165, 134, 247, 227, 116, 181, 89,
  189, 44, 82, 7, 197, 140, 154, 123, 157, 101, 147, 57, 162, 143, 248, 143,
  130, 105, 154, 245, 198, 109, 38, 139, 206, 255, 170, 63, 33, 132, 120,
  225, 213, 29, 186, 168, 204, 124, 239, 196, 135, 24, 6, 101, 214, 62, 42,
  239, 45, 29, 249, 186, 168, 116, 84, 54, 130, 98, 170, 116, 128, 114, 163,
  19, 211, 28, 142, 7, 105, 152, 188, 17, 41, 9, 40, 31, 137, 69, 98, 99,
  209, 80, 30, 210, 31, 112, 147, 223, 106, 65, 74, 102, 16, 105, 32, 209,
  115, 183, 70, 46, 253, 79, 186, 27, 17, 53, 145, 57, 16, 18, 249, 21, 170,
  9, 110, 191, 115, 34, 71, 119, 189, 22, 154, 231, 154, 248, 11, 228, 71,
  198, 15, 26, 224, 38, 25, 169, 76, 164, 50, 170, 185, 112, 186, 131, 212,
  191, 1, 32, 168, 92, 20, 231, 64, 167, 193, 191, 176, 62, 89, 182, 142,
  23, 3, 83, 15, 121, 74, 177, 116, 92, 88, 175, 236, 69, 253, 16, 29, 223,
  197, 138, 120, 154, 185, 221, 48, 133, 126, 27, 237, 128, 103, 148, 210,
  131, 95, 107, 23, 46, 56, 167, 145, 190, 69, 86, 188, 247, 95, 173, 187,
  35, 43, 163, 180, 201, 209, 192, 209, 145, 82, 43, 252, 82, 23, 13, 182,
  165, 210, 194, 92, 116, 250, 100, 67, 159, 132, 149, 100, 137, 84, 28,
  207, 105, 13, 61, 46, 125, 9, 113, 107, 194, 192, 145, 215, 180, 70, 27,
  25, 232, 220, 143, 29, 64, 188, 208, 11, 5, 217, 195, 95, 11, 226, 99,
  226, 202, 117, 107, 141, 55, 47, 110, 185, 198, 214, 148, 177, 209, 150,
  115, 19, 201, 205, 173, 240, 126, 174, 139, 213, 215, 4, 20, 93, 40, 108,
  184, 252, 100, 117, 54, 120, 127, 71, 164, 252, 248, 73, 134, 43, 50, 223,
  72, 139, 146, 185, 113, 37, 173, 162, 140, 210, 36, 197, 16, 159, 116,
  146, 212, 97, 129, 248, 252, 137, 148, 96, 130, 108, 207, 41, 123, 207,
  247, 99, 253, 174, 13, 172, 214, 186, 194, 207, 255, 160, 146, 197, 250,
  218, 110, 193, 19, 126, 76, 99, 88, 109, 50, 133, 187, 206, 116, 15, 209,
  124, 81, 188, 88, 28, 239, 241, 68, 71, 30, 125, 130, 30, 163, 109, 156,
  140, 112, 238, 93, 40, 208, 8, 228, 161, 227, 255, 189, 175, 5, 196, 237,
  181, 101, 119, 83, 186, 137, 212, 113, 131, 49, 155, 122, 115, 159, 54,
  15, 118, 9, 86, 194, 205, 140, 33, 3, 2, 8, 209, 31, 160, 5, 26, 29, 179,
  252, 153, 210, 92, 242, 83, 22, 96, 77, 61, 123, 228, 118, 67, 79, 2, 24,
  232, 6, 212, 50, 214, 184, 47, 24, 75, 218, 160, 190, 132, 42, 190, 85,
  178, 230, 70, 209, 83, 40, 150, 176, 134, 124, 95, 64, 234, 163, 212, 96,
  199, 78, 199, 173, 26, 35, 27, 118, 73, 145, 184, 139, 43, 35, 76, 147,
  177, 162, 94, 229, 98, 171, 14, 46, 208, 6, 112, 65, 174, 229, 128, 49,
  29, 201, 75, 48, 215, 137, 188, 236, 13, 212, 21, 119, 253, 188, 78, 111,
  121, 178, 2, 90, 201, 58, 247, 93, 183, 16, 138, 238, 202, 46, 77, 40, 28,
  186, 126, 229, 217, 198, 190, 166, 118, 52, 100, 235, 95, 215, 152, 60,
  22, 123, 235, 208, 48, 195, 127, 216, 189, 98, 138, 170, 244, 222, 121,
  203, 204, 165, 17, 105, 49, 91, 184, 121, 158, 51, 149, 156, 199, 28, 160,
  162, 7, 203, 60, 123, 240, 151, 247, 50, 224, 222, 134, 205, 115, 72, 108,
  1, 46, 27, 124, 178, 175, 222, 19, 123, 65, 53, 77, 88, 82, 193, 241, 10,
  101, 131, 207, 118, 110, 113, 49, 17, 170, 118, 1, 15, 99, 195, 210, 237,
  181, 230, 52, 59, 177, 115, 59, 235, 209, 57, 128, 200, 222, 8, 111, 7,
  77, 244, 9, 109, 251, 236, 126, 225, 19, 96, 91, 89, 98, 39, 224, 173, 70,
  143, 68, 105, 177, 253, 12, 92, 79, 88, 206, 36, 131, 100, 187, 83, 223,
  162, 171, 84, 29, 69, 232, 111, 240, 37, 4, 142, 117, 49, 86, 204, 217,
  36, 58, 36, 14, 110, 221, 16, 25, 187, 243, 29, 69, 19, 77, 43, 10, 81,
  35, 229, 229, 56, 247, 67, 129, 100, 210, 148, 41, 239, 233, 71, 138, 191,
  3, 74, 15, 159, 223, 60, 201, 210, 159, 75, 30, 216, 131, 177, 171, 63,
  243, 189, 39, 156, 255, 115, 181, 240, 9, 216, 184, 228, 203, 135, 242,
  108, 108, 167, 18, 50, 171, 23, 139, 149, 232, 41, 184, 38, 216, 232, 103,
  50, 116, 146, 141, 187, 204, 60, 249, 140, 13, 13, 105, 140, 113, 184,
  121, 234, 199, 32, 171, 19, 246, 192, 99, 194, 54, 160, 95, 177, 99, 92,
  180, 157, 84, 10, 127, 141, 252, 62, 59, 139, 84, 155, 77, 212, 14, 91,
  176, 163, 216, 2, 156, 228, 233, 33, 150, 223, 181, 194, 96, 50, 46, 77,
  160, 238, 166, 35, 0, 180, 8, 126, 15, 94, 8, 10, 38, 95, 85, 133, 163,
  151, 19, 253, 34, 103, 42, 122, 214, 221, 45, 138, 213, 160, 207, 94, 118,
  33, 129, 192, 22, 161, 183, 211, 192, 141, 206, 197, 141, 46, 254, 124,
  75, 232, 26, 175, 77, 184, 238, 26, 89, 141, 118, 139, 73, 181, 113, 225,
  249, 132, 108, 8, 9, 207, 153, 76, 233, 21, 53, 169, 217, 101, 134, 227,
  215, 199, 229, 87, 31, 234, 39, 17, 136, 196, 90, 14, 77, 253, 208, 19,
  229, 43, 254, 2, 113, 83, 70, 76, 39, 39, 71, 135, 1, 178, 143, 91, 205,
  28, 102, 87, 226, 70, 75, 174, 75, 163, 126, 86, 62, 65, 135, 139, 132,
  134, 62, 92, 186, 0, 3, 87, 253, 109, 166, 56, 186, 124, 224, 49, 171, 32,
  239, 46, 163, 105, 168, 243, 142, 111, 100, 207, 208, 8, 112, 94, 145, 30,
  25, 113, 225, 69, 233, 223, 242, 33, 197, 204, 3, 84, 51, 189, 88, 153,
  88, 61, 135, 22, 226, 177, 222, 149, 70, 166, 199, 39, 103, 175, 198, 18,
  183, 119, 92, 85, 53, 170, 105, 116, 97, 211, 71, 207, 5, 107, 245, 154,
  212, 3, 134, 206, 43, 122, 224, 195, 26, 189, 26, 215, 179, 199, 18, 252,
  178, 101, 185, 194, 169, 155, 177, 136, 211, 180, 234, 88, 224, 23, 219,
  175, 50, 35, 74, 241, 147, 108, 127, 110, 211, 241, 159, 208, 233, 194,
  169, 5, 116, 155, 160, 122, 144, 98, 200, 215, 49, 9, 131, 140, 124, 155,
  82, 222, 231, 224, 203, 65, 115, 94, 200, 113, 140, 192, 125, 35, 167,
  131, 152, 158, 65, 193, 57, 81, 172, 232, 45, 184, 65, 58, 12, 211, 106,
  227, 253, 78, 175, 84, 208, 243, 113, 100, 64, 105, 39, 245, 223, 115,
  252, 106, 79, 192, 166, 25, 149, 141, 240, 215, 189, 183, 193, 74, 191,
  115, 80, 98, 25, 182, 1, 164, 156, 11, 19, 71, 109, 217, 109, 255, 1, 216,
  241, 149, 113, 74, 90, 43, 10, 200, 231, 40, 73, 231, 71, 206, 127, 243,
  159, 186, 171, 57, 116, 9, 90, 16, 50, 170, 7, 5, 80, 60, 128, 74, 68,
  178, 98, 246, 112, 186, 72, 226, 183, 192, 4, 57, 30, 221, 49, 203, 237,
  3, 37, 253, 47, 199, 202, 40, 56, 101, 177, 150, 211, 151, 165, 103, 235,
  211, 209, 137, 48, 3, 46, 6, 198, 36, 167, 251, 190, 73, 214, 8, 208, 249,
  5, 7, 245, 169, 195, 230, 116, 108, 129, 180, 55, 109, 203, 124, 11, 179,
  45, 168, 54, 20, 54, 230, 253, 127, 195, 122, 236, 175, 164, 205, 245, 77,
  195, 114, 11, 195, 143, 245, 123, 232, 241, 92, 213, 199, 27, 170, 230,
  32, 66, 175, 127, 90, 147, 1, 233, 76, 20, 229, 86, 126, 167, 191, 216,
  117, 85, 248, 188, 214, 233, 139, 85, 194, 8, 214, 157, 235, 168, 178, 35,
  192, 177, 124, 140, 70, 212, 118, 116, 122, 237, 20, 105, 229, 14, 177,
  231, 201, 99, 140, 97, 104, 26, 226, 67, 233, 25, 176, 52, 80, 136, 220,
  144, 204, 192, 104, 0, 152, 83, 175, 255, 123, 40, 116, 20, 191, 79, 68,
  61, 224, 212, 76, 214, 190, 234, 87, 66, 224, 51, 187, 102, 40, 48, 155,
  106, 216, 105, 212, 109, 233, 114, 120, 225, 157, 130, 13, 58, 44, 111,
  223, 211, 69, 108, 65, 17, 213, 188, 75, 197, 242, 40, 74, 33, 98, 9, 18,
  204, 193, 122, 100, 206, 204, 189, 243, 173, 71, 110, 230, 243, 103, 165,
  99, 18, 87, 209, 183, 34, 195, 2, 199, 193, 182, 151, 146, 107, 202, 166,
  222, 79, 196, 141, 89, 197, 254, 184, 16, 52, 3, 216, 9, 53, 77, 29, 222,
  128, 148, 43, 117, 43, 166, 59, 153, 207, 153, 90, 211, 120, 255, 110, 91,
  98, 130, 171, 149, 92, 43, 179, 43, 26, 185, 15, 7, 16, 93, 111, 85, 162,
  32, 143, 14, 0, 173, 1, 70, 197, 216, 170, 231, 142, 174, 238, 209, 32,
  22, 228, 208, 39, 98, 15, 50, 13, 69, 220, 169, 208, 68, 64, 101, 209,
  117, 175, 93, 212, 253, 73, 75, 249, 1, 53, 180, 94, 123, 82, 168, 32, 65,
  138, 136, 252, 90, 66, 193, 185, 60, 248, 172, 161, 228, 128, 130, 110,
  118, 92, 198, 57, 51, 83, 82, 240, 65, 116, 148, 223, 206, 148, 124, 109,
  54, 202, 28, 169, 202, 100, 27, 235, 237, 49, 50, 188, 72, 88, 186, 97,
  40, 18, 81, 157, 120, 109, 193, 46, 3, 80, 53, 182, 31, 214, 165, 32, 151,
  94, 4, 113, 78, 220, 205, 36, 133, 237, 151, 1, 50, 160, 63, 210, 65, 84,
  148, 88, 33, 14, 208, 92, 174, 117, 164, 181, 197, 155, 238, 144, 246, 26,
  12, 208, 60, 58, 95, 121, 105, 133, 29, 64, 24, 41, 221, 184, 39, 77, 169,
  113, 139, 160, 37, 232, 100, 83, 184, 209, 4, 53, 48, 235, 62, 103, 247,
  21, 56, 60, 109, 154, 76, 6, 93, 94, 69, 19, 75, 204, 65, 9, 223, 116,
  251, 245, 114, 21, 244, 247, 46, 152, 61, 215, 105, 247, 45, 61, 11, 115,
  163, 17, 55, 206, 54, 15, 173, 115, 127, 12, 2, 62, 227, 160, 3, 42, 253,
  55, 165, 149, 2, 231, 134, 121, 66, 79, 25, 123, 217, 139, 173, 87, 232,
  232, 94, 148, 169, 166, 32, 36, 158, 203, 141, 145, 26, 124, 178, 84, 239,
  23, 204, 104, 198, 186, 144, 151, 81, 151, 236, 130, 249, 72, 85, 103,
  109, 183, 120, 149, 45, 62, 90, 238, 145, 34, 109, 209, 126, 129, 207,
  129, 76, 92, 184, 58, 121, 107, 49, 39, 74, 160, 210, 35
};

#define N 40

int
blowfish_main ()
{
  unsigned char ukey[8];
  unsigned char indata[N];
  unsigned char outdata[N];
  unsigned char ivec[8];
  int num;
  int i, j, k, l;
  int encordec;
  int check;

  num = 0;
  k = 0;
  l = 0;
  encordec = 1;
  check = 0;
  for (i = 0; i < 8; i++)
    {
      ukey[i] = 0;
      ivec[i] = 0;
    }
  BF_set_key (8, ukey);
  i = 0;
  while (k < KEYSIZE)
    {
      while (k < KEYSIZE && i < N)
	indata[i++] = in_key[k++];

      BF_cfb64_encrypt (indata, outdata, i, ivec, &num, encordec);

      for (j = 0; j < i; j++)
	check += (outdata[j] != out_key[l++]);

      i = 0;
    }
  return check;
}

int
main ()
{
  int main_result;

      main_result = 0;
      main_result = blowfish_main ();


      return main_result;
    }
