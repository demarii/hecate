INCLUDES = -I$(top_srcdir)/src
SUBDIRS = src 
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = autogen.sh

docdir = $(prefix)/doc/hecate
dist_doc_DATA = README COPYING AUTHORS NEWS

etcdir = $(sysconfdir)
dist_etc_DATA = hecate.conf

docs:
	@echo "running doxygen..."
	@doxygen hecate.dox
	@echo "documentation is in doc/."
	
dist-hook:
	@if test -d "$(srcdir)/.git"; \
        then \
                echo Creating ChangeLog && \
                ( cd "$(top_srcdir)" && \
                  echo '# Generated by Makefile. Do not edit.'; echo; \
                  $(top_srcdir)/missing --run git log --decorate --pretty=oneline --abbrev-commit --all ) > ChangeLog.tmp \
                && mv -f ChangeLog.tmp $(distdir)/ChangeLog \
                || ( rm -f ChangeLog.tmp ; \
                     echo Failed to generate ChangeLog >&2 ); \
        else \
                echo A git clone is required to generate a ChangeLog >&2; \
        fi
