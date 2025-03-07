/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS For Embedded Optimization.                                                      *
* Copyright (C) 2019 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* The 2-Clause BSD License                                                                        *
*                                                                                                 *
* Redistribution and use in source and binary forms, with or without                              *
* modification, are permitted provided that the following conditions are met:                     *
*                                                                                                 *
* 1. Redistributions of source code must retain the above copyright notice, this                  *
*    list of conditions and the following disclaimer.                                             *
* 2. Redistributions in binary form must reproduce the above copyright notice,                    *
*    this list of conditions and the following disclaimer in the documentation                    *
*    and/or other materials provided with the distribution.                                       *
*                                                                                                 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND                 *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED                   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                          *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR                 *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                    *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND                     *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT                      *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS                   *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                    *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "../include/blasfeo_stdlib.h"
#include "../include/blasfeo_v_aux_ext_dep.h"

#if 0
#include <malloc.h>
#endif


#ifdef EXT_DEP_MALLOC
/* creates a zero matrix given the size in bytes */
void v_zeros(void **ptrA, int size)
	{
	// allocate memory
	blasfeo_malloc(ptrA, size);
	// zero memory
	int i;
	double *dA = (double *) *ptrA;
	for(i=0; i<size/8; i++) dA[i] = 0.0;
	char *cA = (char *) dA;
	i *= 8;
	for(; i<size; i++) cA[i] = 0;
	return;
	}
#endif


#ifdef EXT_DEP_MALLOC
/* creates a zero matrix aligned to a cache line given the size in bytes */
void v_zeros_align(void **ptrA, int size)
	{
	// allocate memory
	blasfeo_malloc_align(ptrA, size);
	// zero allocated memory
	int i;
	double *dA = (double *) *ptrA;
	for(i=0; i<size/8; i++) dA[i] = 0.0;
	char *cA = (char *) dA;
	i *= 8;
	for(; i<size; i++) cA[i] = 0;
	return;
	}
#endif


#ifdef EXT_DEP_MALLOC
/* frees matrix */
void v_free(void *pA)
	{
	blasfeo_free( pA );
	}
#endif


#ifdef EXT_DEP_MALLOC
/* frees aligned matrix */
void v_free_align(void *pA)
	{
	blasfeo_free_align(pA);
	}
#endif


#ifdef EXT_DEP_MALLOC
/* creates a zero matrix given the size in bytes */
void c_zeros(char **ptrA, int size)
	{
	// allocate memory
	blasfeo_malloc((void **) ptrA, size);
	// zero memory
	int i;
	double *dA = (double *) *ptrA;
	for(i=0; i<size/8; i++) dA[i] = 0.0;
	char *cA = (char *) dA;
	i *= 8;
	for(; i<size; i++) cA[i] = 0;
	return;
	}
#endif


#ifdef EXT_DEP_MALLOC
/* creates a zero matrix aligned to a cache line given the size in bytes */
void c_zeros_align(char **ptrA, int size)
	{
	// allocate memory
	blasfeo_malloc_align((void **) ptrA, size);
	// zero allocated memory
	int i;
	double *dA = (double *) *ptrA;
	for(i=0; i<size/8; i++) dA[i] = 0.0;
	char *cA = (char *) dA;
	i *= 8;
	for(; i<size; i++) cA[i] = 0;
	return;
	}
#endif


#ifdef EXT_DEP_MALLOC
/* frees matrix */
void c_free(char *pA)
	{
	blasfeo_free( pA );
	}
#endif


#ifdef EXT_DEP_MALLOC
/* frees aligned matrix */
void c_free_align(char *pA)
	{
	blasfeo_free_align(pA);
	}
#endif
