import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    // These QML signal are connected to the corresponding slot in the C++ side
    signal fileMenu(string action)

    // The corresponding signal in the C++ side will be connected to these QML signals
    signal openPasswordDialog(string filename)

    initialPage: mainPage

    // Application defaults, visible in all pages
    AppDefaults {
        id: appDefaults
    }

    MainPage {
        id: mainPage
    }

    // Common toolbar
    ToolBarLayout {
        id: commonTools
        visible: false
        ToolIcon {
            platformIconId: "toolbar-back"
            onClicked: pageStack.pop()
        }
    }

    // QML component loader
    Loader {
        id: myLoader
    }

    // Event handlers
    onOpenPasswordDialog: {
        myLoader.source = "Dialogs/PasswordDialog.qml"
        myLoader.item.title = filename;
        myLoader.item.show()
    }
}
