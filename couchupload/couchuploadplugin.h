#ifndef COUCHUPLOAD_H
#define COUCHUPLOAD_H

#include "couchupload_global.h"

#include <extensionsystem/iplugin.h>

namespace CouchUpload {
namespace Internal {

class CouchUploadPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT

public:
    CouchUploadPlugin();
    ~CouchUploadPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void triggerAction();
};

} // namespace Internal
} // namespace CouchUpload

#endif // COUCHUPLOAD_H

