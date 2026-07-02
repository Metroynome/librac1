all: clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscu
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.v200.pal
	$(MAKE) -f ${CURDIR}/Makefile.v200.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	
clean:
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.v200.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	rm -f -r lib/

install: clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscu install
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal install
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.v200.pal install
	$(MAKE) -f ${CURDIR}/Makefile.v200.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj install
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	
