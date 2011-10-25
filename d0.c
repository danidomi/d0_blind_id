/*
 * include the license notice into the dynamic library to "reproduce the
 * copyright notice" automatically, so the application developer does not have
 * to care about this term
 */
const char *d0_bsd_license_notice = "\n"
"/*\n"
" * FILE:	d0.c\n"
" * AUTHOR:	Rudolf Polzer - divVerent@xonotic.org\n"
" * \n"
" * Copyright (c) 2010, Rudolf Polzer\n"
" * All rights reserved.\n"
" *\n"
" * Redistribution and use in source and binary forms, with or without\n"
" * modification, are permitted provided that the following conditions\n"
" * are met:\n"
" * 1. Redistributions of source code must retain the above copyright\n"
" *    notice, this list of conditions and the following disclaimer.\n"
" * 2. Redistributions in binary form must reproduce the above copyright\n"
" *    notice, this list of conditions and the following disclaimer in the\n"
" *    documentation and/or other materials provided with the distribution.\n"
" * 3. Neither the name of the copyright holder nor the names of contributors\n"
" *    may be used to endorse or promote products derived from this software\n"
" *    without specific prior written permission.\n"
" * \n"
" * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS'' AND\n"
" * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
" * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE\n"
" * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S) BE LIABLE\n"
" * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
" * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS\n"
" * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)\n"
" * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT\n"
" * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY\n"
" * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF\n"
" * SUCH DAMAGE.\n"
" *\n"
" * $Format:commit %H$\n"
" * $Id$\n"
" */\n";

#include "d0.h"

#include <stdlib.h>

#define MUTEX_DEBUG

void *(*d0_malloc)(size_t len) = malloc;
void (*d0_free)(void *p) = free;

#ifdef MUTEX_DEBUG
#define NUM_MUTEXES 2
#include <stdio.h>
static mutexarray[NUM_MUTEXES];
static int mutexpos = 0;
static void *dummy_createmutex(void)
{
	if(mutexpos >= NUM_MUTEXES)
	{
		printf("We don't support creating so many mutexes here\n");
		return NULL;
	}
	return &mutexarray[mutexpos++];
}
static void dummy_destroymutex(void *m)
{
	if(*(int *)m != 0)
		printf("Destroying in-use mutex\n");
	*(int *)m = -1;
}
static int dummy_lockmutex(void *m)
{
	if(*(int *)m != 0)
		printf("Locking in-use mutex\n");
	*(int *)m += 1;
	return 0;
}
static int dummy_unlockmutex(void *m)
{
	if(*(int *)m != 1)
		printf("Unlocking not-in-use mutex\n");
	*(int *)m -= 1;
	return 0;
}
#else
static void *dummy_createmutex(void)
{
	return (void *) 1; // some dummy non-NULL pointer
}
static void dummy_destroymutex(void *m)
{
}
static int dummy_lockmutex(void *m)
{
	return 0;
}
static int dummy_unlockmutex(void *m)
{
	return 0;
}
#endif

void *(*d0_createmutex)(void) = dummy_createmutex;
void (*d0_destroymutex)(void *) = dummy_destroymutex;
int (*d0_lockmutex)(void *) = dummy_lockmutex;
int (*d0_unlockmutex)(void *) = dummy_unlockmutex;
