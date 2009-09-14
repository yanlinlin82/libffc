# Makefile
ROOT	= ./

include Makefile.inc

.PHONY: all
.PHONY: clean

DEMO	= HelloDemo ConsoleDemo DialogDemo SdiDemo MdiDemo

all:
	@$(MAKE) --directory=Source
	@for d in $(DEMO:%=Demo/%); \
	do \
		$(MAKE) --directory=$$d; \
	done

clean:
	@$(MAKE) --directory=Source clean
	@for d in $(DEMO:%=Demo/%); \
	do \
		$(MAKE) --directory=$$d clean; \
	done
	rm -vrf $(TMP_DIR) $(LIB_DIR) $(OUT_DIR)

