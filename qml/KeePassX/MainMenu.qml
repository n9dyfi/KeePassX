import QtQuick 1.1
import com.nokia.meego 1.0

Menu {

    MenuLayout {

        MenuItem {
            text: qsTr("File")
            onClicked: {
                menuFileClicked("MenuFile.qml")
            }
        }

        MenuItem {
            text: qsTr("Entries")
            onClicked: {
                menuEntriesClicked("MenuEntries.qml")
            }
        }

        MenuItem {
            text: qsTr("Groups")
            onClicked: {
                menuGroupsClicked("MenuGroups.qml")
            }
        }

        MenuItem {
            text: qsTr("View")
            onClicked: {
                menuViewClicked("MenuView.qml")
            }
        }

        MenuItem {
            text: qsTr("Extras")
            onClicked: {
                menuExtrasClicked("MenuExtras.qml")
            }
        }

        MenuItem {
            text: qsTr("Help")
            onClicked: {
                menuHelpClicked("MenuHelp.qml")
            }
        }
    }
}
