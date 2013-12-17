include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = dollarcoin-qt
noinst_LIBRARIES = libdollarcoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# dollarcoin qt core #
QT_TS = locale/dollarcoin_ach.ts \
  locale/dollarcoin_af_ZA.ts \
  locale/dollarcoin_ar.ts \
  locale/dollarcoin_be_BY.ts \
  locale/dollarcoin_bg.ts \
  locale/dollarcoin_bs.ts \
  locale/dollarcoin_ca_ES.ts \
  locale/dollarcoin_ca.ts \
  locale/dollarcoin_cs.ts \
  locale/dollarcoin_cy.ts \
  locale/dollarcoin_da.ts \
  locale/dollarcoin_de.ts \
  locale/dollarcoin_de_AT.ts \
  locale/dollarcoin_el_GR.ts \
  locale/dollarcoin_en.ts \
  locale/dollarcoin_eo.ts \
  locale/dollarcoin_es_CL.ts \
  locale/dollarcoin_es.ts \
  locale/dollarcoin_et.ts \
  locale/dollarcoin_eu_ES.ts \
  locale/dollarcoin_fa_IR.ts \
  locale/dollarcoin_fa.ts \
  locale/dollarcoin_fi.ts \
  locale/dollarcoin_fr_CA.ts \
  locale/dollarcoin_fr.ts \
  locale/dollarcoin_gl.ts \
  locale/dollarcoin_gu_IN.ts \
  locale/dollarcoin_he.ts \
  locale/dollarcoin_hi_IN.ts \
  locale/dollarcoin_hr.ts \
  locale/dollarcoin_hu.ts \
  locale/dollarcoin_id_ID.ts \
  locale/dollarcoin_it.ts \
  locale/dollarcoin_ja.ts \
  locale/dollarcoin_kk_KZ.ts \
  locale/dollarcoin_ko_KR.ts \
  locale/dollarcoin_la.ts \
  locale/dollarcoin_lt.ts \
  locale/dollarcoin_lv_LV.ts \
  locale/dollarcoin_ms_MY.ts \
  locale/dollarcoin_nb.ts \
  locale/dollarcoin_nl.ts \
  locale/dollarcoin_pl.ts \
  locale/dollarcoin_pt_BR.ts \
  locale/dollarcoin_pt_PT.ts \
  locale/dollarcoin_ro_RO.ts \
  locale/dollarcoin_ru.ts \
  locale/dollarcoin_sk.ts \
  locale/dollarcoin_sl_SI.ts \
  locale/dollarcoin_sq.ts \
  locale/dollarcoin_sr.ts \
  locale/dollarcoin_sv.ts \
  locale/dollarcoin_th_TH.ts \
  locale/dollarcoin_tr.ts \
  locale/dollarcoin_uk.ts \
  locale/dollarcoin_vi.ts \
  locale/dollarcoin_vi_VN.ts \
  locale/dollarcoin_zh_CN.ts \
  locale/dollarcoin_zh_TW.ts

QT_FORMS_UI = forms/aboutdialog.ui forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui forms/overviewpage.ui forms/receiverequestdialog.ui \
  forms/receivecoinsdialog.ui \
  forms/rpcconsole.ui forms/sendcoinsdialog.ui forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui forms/transactiondescdialog.ui

QT_MOC_CPP = moc_aboutdialog.cpp moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp moc_askpassphrasedialog.cpp \
  moc_dollarcoinaddressvalidator.cpp moc_dollarcoinamountfield.cpp \
  moc_dollarcoingui.cpp moc_dollarcoinunits.cpp moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp moc_editaddressdialog.cpp moc_guiutil.cpp \
  moc_intro.cpp moc_macdockiconhandler.cpp moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp moc_overviewpage.cpp moc_paymentserver.cpp \
  moc_receiverequestdialog.cpp moc_qvalidatedlineedit.cpp moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_rpcconsole.cpp moc_sendcoinsdialog.cpp moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp moc_splashscreen.cpp moc_trafficgraphwidget.cpp moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp moc_transactionview.cpp moc_walletframe.cpp \
  moc_walletmodel.cpp moc_walletview.cpp

DOLLARCOIN_MM = macdockiconhandler.mm macnotificationhandler.mm

QT_MOC = intro.moc overviewpage.moc rpcconsole.moc

QT_QRC_CPP = qrc_dollarcoin.cpp
QT_QRC = dollarcoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

DOLLARCOIN_QT_H  = aboutdialog.h addressbookpage.h addresstablemodel.h \
  askpassphrasedialog.h dollarcoinaddressvalidator.h dollarcoinamountfield.h \
  dollarcoingui.h dollarcoinunits.h clientmodel.h coincontroldialog.h coincontroltreewidget.h csvmodelwriter.h \
  editaddressdialog.h guiconstants.h guiutil.h intro.h macdockiconhandler.h \
  macnotificationhandler.h monitoreddatamapper.h notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h overviewpage.h paymentrequestplus.h paymentserver.h \
  receivecoinsdialog.h \
  receiverequestdialog.h qvalidatedlineedit.h qvaluecombobox.h rpcconsole.h \
  sendcoinsdialog.h sendcoinsentry.h signverifymessagedialog.h splashscreen.h \
  trafficgraphwidget.h transactiondescdialog.h transactiondesc.h transactionfilterproxy.h \
  transactionrecord.h transactiontablemodel.h transactionview.h walletframe.h \
  walletmodel.h walletmodeltransaction.h walletview.h

RES_ICONS = res/icons/dollarcoin.png res/icons/address-book.png \
  res/icons/quit.png res/icons/send.png res/icons/toolbar.png \
  res/icons/connect0_16.png res/icons/connect1_16.png \
  res/icons/connect2_16.png res/icons/connect3_16.png \
  res/icons/connect4_16.png res/icons/transaction0.png \
  res/icons/transaction2.png res/icons/clock1.png res/icons/clock2.png \
  res/icons/clock3.png res/icons/clock4.png res/icons/clock5.png \
  res/icons/configure.png res/icons/receive.png res/icons/editpaste.png \
  res/icons/editcopy.png res/icons/add.png res/icons/dollarcoin_testnet.png \
  res/icons/toolbar_testnet.png res/icons/edit.png res/icons/history.png \
  res/icons/overview.png res/icons/export.png res/icons/synced.png \
  res/icons/remove.png res/icons/tx_mined.png res/icons/tx_input.png \
  res/icons/tx_output.png res/icons/tx_inout.png res/icons/lock_closed.png \
  res/icons/lock_open.png res/icons/key.png res/icons/filesave.png \
  res/icons/qrcode.png res/icons/debugwindow.png res/icons/dollarcoin.ico \
  res/icons/dollarcoin_testnet.ico

DOLLARCOIN_QT_CPP = aboutdialog.cpp addressbookpage.cpp \
  addresstablemodel.cpp askpassphrasedialog.cpp dollarcoinaddressvalidator.cpp \
  dollarcoinamountfield.cpp dollarcoin.cpp dollarcoingui.cpp \
  dollarcoinunits.cpp clientmodel.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  csvmodelwriter.cpp editaddressdialog.cpp \
  guiutil.cpp intro.cpp monitoreddatamapper.cpp notificator.cpp \
  openuridialog.cpp \
  optionsdialog.cpp optionsmodel.cpp overviewpage.cpp paymentrequestplus.cpp \
  paymentserver.cpp qvalidatedlineedit.cpp qvaluecombobox.cpp \
  receivecoinsdialog.cpp receiverequestdialog.cpp \
  rpcconsole.cpp sendcoinsdialog.cpp sendcoinsentry.cpp \
  signverifymessagedialog.cpp splashscreen.cpp trafficgraphwidget.cpp transactiondesc.cpp \
  transactiondescdialog.cpp transactionfilterproxy.cpp transactionrecord.cpp \
  transactiontablemodel.cpp transactionview.cpp walletframe.cpp \
  walletmodel.cpp walletmodeltransaction.cpp walletview.cpp

RES_IMAGES = res/images/about.png res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = res/movies/update_spinner.mng

DOLLARCOIN_RC = res/dollarcoin-qt-res.rc

libdollarcoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libdollarcoinqt_a_SOURCES = $(DOLLARCOIN_QT_CPP) $(DOLLARCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libdollarcoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libdollarcoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

if TARGET_DARWIN
  libdollarcoinqt_a_SOURCES += $(DOLLARCOIN_MM)
endif
if TARGET_WINDOWS
  libdollarcoinqt_a_SOURCES += $(DOLLARCOIN_RC)
endif
#

# dollarcoin-qt binary #
dollarcoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
dollarcoin_qt_SOURCES = dollarcoin.cpp
dollarcoin_qt_LDADD = libdollarcoinqt.a $(LIBDOLLARCOIN_SERVER) $(LIBDOLLARCOIN_CLI) $(LIBDOLLARCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

dollarcoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/dollarcoinstrings.cpp

translate: dollarcoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(DOLLARCOIN_QT_CPP) $(DOLLARCOIN_QT_H) $(DOLLARCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@$(LUPDATE) $^ -locations relative -no-obsolete -ts locale/dollarcoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && $(RCC) -name dollarcoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
