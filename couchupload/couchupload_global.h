#ifndef COUCHUPLOAD_GLOBAL_H
#define COUCHUPLOAD_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(COUCHUPLOAD_LIBRARY)
#  define COUCHUPLOADSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COUCHUPLOADSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COUCHUPLOAD_GLOBAL_H

