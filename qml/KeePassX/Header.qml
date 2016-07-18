import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    property alias headerText: titleLabel.text
    property alias infoTopText: infoTop.text
    property alias infoBottomText: infoBottom.text
    property bool singleLineHeader: true

    property string headerFontFamily : appDefaults.cFONT_FAMILY
    property int headerFontSize : appDefaults.cFONT_SIZE_LARGE
    property int infoTopFontSize: appDefaults.cFONT_SIZE_SMALL
    property int infoBottomFontSize: appDefaults.cFONT_SIZE_TINY

    // header dimensions
    height: appDefaults.cHEADER_HEIGHT
    width: parent.width

    // Header background image
    Image {
        id: titleImage
        height: parent.height
        width: parent.width
        source: appDefaults.cVIEW_HEADER
    }

    // Define the label styling
    LabelStyle {
        id: labelStyle
        textColor: "white"
        fontFamily: headerFontFamily
        fontPixelSize: headerFontSize
    }
    LabelStyle {
        id: infoTopStyle
        textColor: "white"
        fontFamily: headerFontFamily
        fontPixelSize: infoTopFontSize
    }
    LabelStyle {
        id: infoBottomStyle
        textColor: "black"
        fontFamily: headerFontFamily
        fontPixelSize: infoBottomFontSize
    }

    // Header text
    Label {
        id: titleLabel
        platformStyle: labelStyle
        visible: singleLineHeader
        anchors {
            top:parent.top; topMargin:appDefaults.cHEADER_TOP_SPACING
            left:parent.left; leftMargin:appDefaults.cDEFAULT_MARGIN
        }
    }
    Label {
        id: infoTop
        platformStyle: infoTopStyle
        visible: !singleLineHeader
        anchors {
            bottom: infoBottom.top
            left:parent.left; leftMargin:appDefaults.cDEFAULT_MARGIN
        }
    }
    Label {
        id: infoBottom
        platformStyle: infoBottomStyle
        visible: !singleLineHeader
        anchors {
            bottom:parent.bottom; bottomMargin:appDefaults.cHEADER_REDUCED_BOTTOM_SPACING;
            left:parent.left; leftMargin:appDefaults.cDEFAULT_MARGIN
        }
    }
}
