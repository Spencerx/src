#	$NetBSD: Makefile,v 1.14 2016/03/23 21:38:51 christos Exp $
#

.PATH:  ${.CURDIR}/../../../../ufs/lfs

LIB=	rumpfs_lfs
COMMENT=Log-structured File System

SRCS=	lfs_alloc.c lfs_balloc.c lfs_bio.c lfs_cksum.c lfs_debug.c	\
	lfs_inode.c lfs_itimes.c lfs_pages.c lfs_rename.c lfs_rfw.c	\
	lfs_segment.c lfs_subr.c lfs_syscalls.c lfs_vfsops.c lfs_vnops.c

SRCS+=	ulfs_bmap.c ulfs_dirhash.c ulfs_extattr.c 			\
	ulfs_inode.c ulfs_lookup.c ulfs_quota.c ulfs_quota1.c		\
	ulfs_quota2.c ulfs_quota1_subr.c ulfs_quota2_subr.c		\
	ulfs_snapshot.c ulfs_vfsops.c ulfs_vnops.c


CFLAGS+=        -DLFS_KERNEL_RFW
.if ${MACHINE_ARCH} == "vax"
COPTS.lfs_inode.c+=-O0
.endif

.include <bsd.lib.mk>
.include <bsd.klinks.mk>
