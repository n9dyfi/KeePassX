import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.1

Page {

    signal pageOpenRequested(string page)
    signal menuCancelled

    onPageOpenRequested: {
        pageStack.push(Qt.resolvedUrl(page));
    }

    onMenuCancelled: {
        pageStack.pop()
    }

Header {
    id: header
    headerText: "File"
}

tools: commonTools

// page contents starts here

ListView {
    id: menuFileView
    anchors.top: header.bottom
    width: parent.width-appDefaults.cDEFAULT_MARGIN
    height: parent.height - header.height - appDefaults.cDEFAULT_MARGIN // - menuFileTools.height;
    x: appDefaults.cDEFAULT_MARGIN
    spacing: -30
    clip: true
    model: menuFileModel

    delegate:  ListDelegate {
        Image {
            source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
        titleColor: (enable)?"black":"grey"
        onClicked: {
            if(enable) {
                fileMenu(page)
                //pageOpenRequested(page)
            }
        }
    }
}
ScrollDecorator {
    flickableItem: menuFileView
}
}
