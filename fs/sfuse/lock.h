/*
 * Copyright (c) 1997-2007 Erez Zadok <ezk@cs.stonybrook.edu>
 * Copyright (c) 2001-2007 Stony Brook University
 *
 * For specific licensing information, see the COPYING file distributed with
 * this package, or get one from
 * ftp://ftp.filesystems.org/pub/fistgen/COPYING.
 *
 * This Copyright notice must be kept intact and distributed with all
 * fistgen sources INCLUDING sources generated by fistgen.
 */
/*
 * File: fistgen/templates/Linux-2.6/lock.h
 */

#ifndef __FIST_LOCK_H_
#define __FIST_LOCK_H_

#ifdef __KERNEL__

/* 2.6.16 changed the inode semaphore into a mutex. The following functions
 * wrap the semaphore/mutex locking & unlocking code
 */

static inline void lock_inode(struct inode * i)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,16)
	down(&i->i_sem);
#else
	mutex_lock(&i->i_mutex);
#endif /* version >= 2.6.16 */
}

static inline void unlock_inode(struct inode * i)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,16)
	up(&i->i_sem);
#else
	mutex_unlock(&i->i_mutex);
#endif /* version >= 2.6.16 */
}

#endif /* not __KERNEL__ */

#endif /* not __FIST_LOCK_H_ */