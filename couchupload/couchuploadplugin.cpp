#include "couchuploadplugin.h"
#include "couchuploadconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QtGui/QAction>
#include <QtGui/QMessageBox>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>

#include <QtCore/QtPlugin>

#include <projectexplorer/session.h>
#include <projectexplorer/project.h>
#include <projectexplorer/projectexplorer.h>

using namespace CouchUpload::Internal;
using namespace ProjectExplorer;

CouchUploadPlugin::CouchUploadPlugin()
{
    // Create your members
}

CouchUploadPlugin::~CouchUploadPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool CouchUploadPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // connect to other plugins' signals
    // "In the initialize method, a plugin can be sure that the plugins it
    //  depends on have initialized their members."

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)
    Core::ActionManager *am = Core::ICore::instance()->actionManager();

    QAction *action = new QAction(tr("CouchUpload action"), this);
    Core::Command *cmd = am->registerAction(action, Constants::ACTION_ID,
                         Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

    Core::ActionContainer *menu = am->createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("CouchUpload"));
    menu->addAction(cmd);
    am->actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void CouchUploadPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // "In the extensionsInitialized method, a plugin can be sure that all
    //  plugins that depend on it are completely initialized."
}

ExtensionSystem::IPlugin::ShutdownFlag CouchUploadPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void CouchUploadPlugin::triggerAction()
{
    ProjectExplorerPlugin *plugin = ProjectExplorerPlugin::instance();
    Project *p = plugin->currentProject();
    if (p) {
        QStringList files = p->files(Project::ExcludeGeneratedFiles);
        QString foo = files.join(";");
        QMessageBox::information(0, "CouchUpload", foo);
    } else {
        QMessageBox::information(0, "CouchUpload", "No active project");
    }
}

Q_EXPORT_PLUGIN2(CouchUpload, CouchUploadPlugin)

