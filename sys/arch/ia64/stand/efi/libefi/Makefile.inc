#	$NetBSD: Makefile.inc,v 1.7 2018/06/13 16:04:55 christos Exp $
#
#	Configuration variables (default values are below):
#
#	S	must be set to the top of the 'sys' tree.
#	EFIDST	may be set to the location of the directory where library
#		objects are to be built.  Defaults to ${.OBJDIR}/lib/efi.
#	EFIMISCCPPFLAGS
#		Miscellaneous cpp flags to be passed to the library's Makefile
#		when building.
#	EFIMISCMAKEFLAGS
#		Miscellaneous flags to be passed to the library's Makefile when
#		building.  See library's Makefile for more details about
#		supported flags and their default values.

# Default values:
EFIDST?=		${.OBJDIR}/efi/libefi

EFIDIR?=		$S/arch/ia64/stand/efi/libefi
EFILIB=			${EFIDST}/libefi.a

EFIMAKE= \
	cd ${EFIDIR} && MAKEOBJDIRPREFIX= && unset MAKEOBJDIRPREFIX && \
	    MAKEOBJDIR=${EFIDST} ${MAKE} \
	    CC=${CC:q} CFLAGS=${CFLAGS:q} \
	    AS=${AS:q} AFLAGS=${AFLAGS:q} \
	    LD=${LD:q} STRIP=${STRIP:q} \
	    MACHINE=${MACHINE} MACHINE_ARCH=${MACHINE_ARCH:q} \
	    EFICPPFLAGS=${CPPFLAGS:S@^-I.@-I../../.@g:q} \
	    EFIMISCCPPFLAGS=${EFIMISCCPPFLAGS:q} \
	    ${EFIMISCMAKEFLAGS}

${EFILIB}:		.NOTMAIN __always_make_efilib
	@echo making sure the efi library is up to date...
	@${EFIMAKE} libefi.a

clean:			.NOTMAIN cleanefilib
cleanefilib:		.NOTMAIN
	@echo cleaning the efi library objects
	@if [ -d "${EFIDST}" ]; then ${EFIMAKE} clean; fi

cleandir distclean:	.NOTMAIN cleandirefilib
cleandirefilib:		.NOTMAIN
	@echo cleandiring the efi library objects
	@if [ -d "${EFIDST}" ]; then ${EFIMAKE} cleandir; fi
	-rm -rf efi

dependall depend:	.NOTMAIN dependefilib
dependefilib:		.NOTMAIN __always_make_efilib
	@echo depending the efi library objects
	@${EFIMAKE} depend

__always_make_efilib:	.NOTMAIN
	@mkdir -p ${EFIDST}
