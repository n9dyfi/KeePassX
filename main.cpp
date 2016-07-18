#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"

// App specific headers
#include <QDeclarativeItem>
#include <QtDeclarative/QDeclarativeContext>
#include "menufilemodel.h"

#include "main.h"
#include "mainwindow.h"
#include "keepassx.h"

using namespace std;

// Global variables, defined as extern in keepassx.h

KpxConfig *config;
QString AppDir;
QString HomeDir;
QString DataDir;
QString PluginLoadError;
QString DetailViewTemplate;
#if 0  // N9
bool EventOccurred;
bool EventOccurredBlock = false;
#endif
QPixmap* EntryIcons;
IIconTheme* IconLoader=NULL;

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;

    MenuFileModel *menufilemodel;

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/KeePassX/main.qml"));
    viewer.showExpanded();

    // get the QML root object for signal-slot connections
    QObject *qml = viewer.rootObject();
    new MainWindow(qml, &viewer);

    menufilemodel = new MenuFileModel(&viewer);
    viewer.rootContext()->setContextProperty("menuFileModel",menufilemodel);

    return app->exec();

}
