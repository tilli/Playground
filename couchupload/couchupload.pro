TARGET = CouchUpload
TEMPLATE = lib

DEFINES += COUCHUPLOAD_LIBRARY

# CouchUpload files

SOURCES += couchuploadplugin.cpp

HEADERS += couchuploadplugin.h\
        couchupload_global.h\
        couchuploadconstants.h

OTHER_FILES = CouchUpload.pluginspec


# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$(QTC_SOURCE)
isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=/home/tilli/QtSDK/qt-creator-2.3.0-src

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=/home/tilli/QtSDK/QtCreator

PROVIDER = stilli

include($$QTCREATOR_SOURCES/src/qtcreatorplugin.pri)
include($$QTCREATOR_SOURCES/src/plugins/coreplugin/coreplugin.pri)

LIBS += -L$$IDE_PLUGIN_PATH/Nokia -lProjectExplorer

