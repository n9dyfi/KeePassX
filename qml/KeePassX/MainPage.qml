import QtQuick 1.1
import com.nokia.meego 1.0
//import com.nokia.extras 1.1


Page {

    signal menuFileClicked(string page)
    signal menuEntriesClicked(string page)
    signal menuGroupsClicked(string page)
    signal menuViewClicked(string page)
    signal menuExtrasClicked(string page)
    signal menuHelpClicked(string page)

    // Instantiate the Header component (defined in Header.qml)
    Header {
        id: header
        headerText: "KeePassX"
    }

    // Instantiate the Tools component (defined in EditTools.qml)
    MainTools{
        id: commonTools
    }

    // Instantiate the MainMenu component (defined in MainMenu.qml)
    MainMenu {
        id: mainMenu
    }

    // Event handlers
    onMenuFileClicked: {
        pageStack.push(Qt.resolvedUrl(page));
    }

}
