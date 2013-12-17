ACLOCAL_AMFLAGS = -I src/m4
SUBDIRS = src
.PHONY: deploy

GZIP_ENV="-9n"

DOLLARCOIND_BIN=$(top_builddir)/src/dollarcoind$(EXEEXT)
DOLLARCOIN_QT_BIN=$(top_builddir)/src/qt/dollarcoin-qt$(EXEEXT)
DOLLARCOIN_WIN_INSTALLER=$(PACKAGE)-$(PACKAGE_VERSION)-win32-setup$(EXEEXT)

OSX_APP=Dollarcoin-Qt.app
OSX_DMG=Dollarcoin-Qt.dmg
OSX_DEPLOY_SCRIPT=$(top_srcdir)/contrib/macdeploy/macdeployqtplus
OSX_FANCY_PLIST=$(top_srcdir)/contrib/macdeploy/fancy.plist
OSX_INSTALLER_ICONS=$(top_srcdir)/src/qt/res/icons/dollarcoin.icns
OSX_PLIST=$(top_srcdir)/share/qt/Info.plist #not installed

WINDOWS_PACKAGING = $(top_srcdir)/share/pixmaps/dollarcoin.ico \
  $(top_srcdir)/share/pixmaps/nsis-header.bmp \
  $(top_srcdir)/share/pixmaps/nsis-wizard.bmp \
  $(top_srcdir)/doc/README_windows.txt

OSX_PACKAGING = $(OSX_DEPLOY_SCRIPT) $(OSX_FANCY_PLIST) $(OSX_INSTALLER_ICONS) \
  $(top_srcdir)/contrib/macdeploy/background.png

COVERAGE_INFO = baseline_filtered_combined.info baseline.info block_test.info \
  leveldb_baseline.info test_dollarcoin_filtered.info total_coverage.info \
  baseline_filtered.info block_test_filtered.info \
  leveldb_baseline_filtered.info test_dollarcoin_coverage.info test_dollarcoin.info

dist-hook:
	-$(MAKE) -C $(top_distdir)/src/leveldb clean
	-$(GIT) archive --format=tar HEAD -- src/version.cpp | $(AMTAR) -C $(top_distdir) -xf -

distcheck-hook:
	$(MKDIR_P) $(top_distdir)/_build/src/leveldb
	cp -rf $(top_srcdir)/src/leveldb/* $(top_distdir)/_build/src/leveldb/
	-$(MAKE) -C $(top_distdir)/_build/src/leveldb clean

distcleancheck:
	@:

$(DOLLARCOIN_WIN_INSTALLER): $(DOLLARCOIND_BIN) $(DOLLARCOIN_QT_BIN)
	$(MAKE) distdir
	$(MKDIR_P) $(top_builddir)/release
	$(INSTALL_STRIP_PROGRAM) $(top_builddir)/src/dollarcoind$(EXEEXT) $(top_builddir)/release
	$(INSTALL_STRIP_PROGRAM) $(top_builddir)/src/qt/dollarcoin-qt$(EXEEXT) $(top_builddir)/release
	@test -f $(MAKENSIS) && $(MAKENSIS) $(top_builddir)/share/setup.nsi || \
	  echo error: could not build $@

$(DOLLARCOIND_BIN):
	make -C $(top_srcdir)/src dollarcoind$(EXEEXT)

$(DOLLARCOIN_QT_BIN):
	make -C $(top_srcdir)/src/qt dollarcoin-qt$(EXEEXT)


$(OSX_APP)/Contents/PkgInfo:
	$(MKDIR_P) $(@D)
	@echo "APPL????" > $@

$(OSX_APP)/Contents/Resources/empty.lproj:
	$(MKDIR_P) $(@D)
	@touch $@

$(OSX_APP)/Contents/Info.plist: $(OSX_PLIST)
	$(MKDIR_P) $(@D)
	$(INSTALL) $< $@

$(OSX_APP)/Contents/Resources/dollarcoin.icns: $(OSX_INSTALLER_ICONS)
	$(MKDIR_P) $(@D)
	$(INSTALL) $< $@

$(OSX_APP)/Contents/MacOS/Dollarcoin-Qt: $(DOLLARCOIN_QT_BIN)
	$(MKDIR_P) $(@D)
	$(INSTALL_STRIP_PROGRAM)  $< $@

OSX_APP_BUILT=$(OSX_APP)/Contents/PkgInfo $(OSX_APP)/Contents/Resources/empty.lproj \
  $(OSX_APP)/Contents/Resources/dollarcoin.icns $(OSX_APP)/Contents/Info.plist \
  $(OSX_APP)/Contents/MacOS/Dollarcoin-Qt

$(OSX_DMG): $(OSX_APP_BUILT) $(OSX_PACKAGING)
	$(OSX_DEPLOY_SCRIPT) $(OSX_APP) -add-qt-tr da,de,es,hu,ru,uk,zh_CN,zh_TW -dmg -fancy $(OSX_FANCY_PLIST) -verbose 2


if TARGET_DARWIN
appbundle: $(OSX_APP_BUILT)
deploy: $(OSX_DMG)
endif
if TARGET_WINDOWS
deploy: $(DOLLARCOIN_WIN_INSTALLER)
endif

if USE_LCOV

baseline.info:
	$(LCOV) -c -i -d $(abs_builddir)/src -o $@

baseline_filtered.info: baseline.info
	$(LCOV) -r $< "/usr/include/*" -o $@

leveldb_baseline.info: baseline_filtered.info
	$(LCOV) -c -i -d $(abs_builddir)/src/leveldb -b $(abs_builddir)/src/leveldb -o $@

leveldb_baseline_filtered.info: leveldb_baseline.info
	$(LCOV) -r $< "/usr/include/*" -o $@

baseline_filtered_combined.info: leveldb_baseline_filtered.info baseline_filtered.info
	$(LCOV) -a leveldb_baseline_filtered.info -a baseline_filtered.info -o $@

test_dollarcoin.info: baseline_filtered_combined.info
	$(MAKE) -C src/ check
	$(LCOV) -c -d $(abs_builddir)/src -t test_dollarcoin -o $@
	$(LCOV) -z -d $(abs_builddir)/src
	$(LCOV) -z -d $(abs_builddir)/src/leveldb

test_dollarcoin_filtered.info: test_dollarcoin.info
	$(LCOV) -r $< "/usr/include/*" -o $@

block_test.info: test_dollarcoin_filtered.info
	$(MKDIR_P) qa/tmp
	-@TIMEOUT=15 qa/pull-tester/run-dollarcoind-for-test.sh $(JAVA) -jar $(JAVA_COMPARISON_TOOL) qa/tmp/compTool 0
	$(LCOV) -c -d $(abs_builddir)/src --t DollarcoinJBlockTest -o $@
	$(LCOV) -z -d $(abs_builddir)/src
	$(LCOV) -z -d $(abs_builddir)/src/leveldb

block_test_filtered.info: block_test.info
	$(LCOV) -r $< "/usr/include/*" -o $@

test_dollarcoin_coverage.info: baseline_filtered_combined.info test_dollarcoin_filtered.info
	$(LCOV) -a baseline_filtered.info -a leveldb_baseline_filtered.info -a test_dollarcoin_filtered.info -o $@

total_coverage.info:  baseline_filtered_combined.info test_dollarcoin_filtered.info block_test_filtered.info
	$(LCOV) -a baseline_filtered.info -a leveldb_baseline_filtered.info -a test_dollarcoin_filtered.info -a block_test_filtered.info -o $@ | $(GREP) "\%" | $(AWK) '{ print substr($$3,2,50) "/" $$5 }' > coverage_percent.txt

test_dollarcoin.coverage/.dirstamp:  test_dollarcoin_coverage.info
	$(GENHTML) -s $< -o $(@D)
	@touch $@

total.coverage/.dirstamp: total_coverage.info
	$(GENHTML) -s $< -o $(@D)
	@touch $@

cov: test_dollarcoin.coverage/.dirstamp total.coverage/.dirstamp

endif

if USE_COMPARISON_TOOL
check-local:
	$(MKDIR_P) qa/tmp
	@qa/pull-tester/run-dollarcoind-for-test.sh $(JAVA) -jar $(JAVA_COMPARISON_TOOL) qa/tmp/compTool $(COMPARISON_TOOL_REORG_TESTS)
endif

EXTRA_DIST = $(top_srcdir)/share/genbuild.sh qa/pull-tester/pull-tester.sh $(WINDOWS_PACKAGING) $(OSX_PACKAGING)

CLEANFILES = $(OSX_DMG) $(OSX_APP) $(DOLLARCOIN_WIN_INSTALLER)

.INTERMEDIATE: $(COVERAGE_INFO)

clean-local:
	rm -rf test_dollarcoin.coverage/ total.coverage/
