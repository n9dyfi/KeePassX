import QtQuick 1.1
import com.nokia.meego 1.0

// Toolbar for the Edit page
ToolBar {
    anchors.bottom: parent.bottom
    tools:
        ToolBarLayout {
        // Menu button
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (mainMenu.status === DialogStatus.Closed) ?
                           mainMenu.open() : mainMenu.close()
        }
    }
}
