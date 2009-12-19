# Makefile

ROOT	= ./

include Makefile.inc

DEMO	= HelloDemo ConsoleDemo DialogDemo SdiDemo MdiDemo ATLWinDemo

#--------------------------------------------------------------------------

ifneq ("$(MAKECMDGOALS)", "help")
  ifneq ("$(MAKECMDGOALS)", "all")
    ifneq ("$(MAKECMDGOALS)", "clean")

$(MAKECMDGOALS):
	@$(MAKE) --directory=Source $(MAKECMDGOALS)
	@for d in $(DEMO:%=Demo/%); \
	do \
		$(MAKE) --directory=$$d $(MAKECMDGOALS); \
	done

    endif
  endif
endif

#--------------------------------------------------------------------------
