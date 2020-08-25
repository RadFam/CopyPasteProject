import QtQuick 2.6
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Rectangle {
    id: _copypasteelement
    property alias internalText: _elementNum
    //property alias internalEdit: _textarea

    color: "lightblue"
    border.color: "lightcyan"
    border.width: 5
    radius: 10

    // Area with text field
    Rectangle{
        id: _textarearect

        anchors{
            fill: _copypasteelement
            topMargin: _copypasteelement.height * 0.05
            bottomMargin: _copypasteelement.height * 0.25
            leftMargin: _copypasteelement.width * 0.05
            rightMargin: _copypasteelement.width * 0.05
        }

        color: "white"
        border.color: "lightsteelblue"
        border.width: 3
        radius: 10

        Flickable{
            id: _flkr
            width: _textarearect.width * 0.95
            height: _textarearect.height * 0.95
            anchors.centerIn: _textarearect
            contentWidth: _textarea.paintedWidth
            contentHeight: _textarea.paintedHeight
            clip: true

            function ensureVisible(r)
            {
                if (contentX >= r.x)
                    contentX = r.x;
                else if (contentX+width <= r.x+r.width)
                    contentX = r.x+r.width-width;
                if (contentY >= r.y)
                    contentY = r.y;
                else if (contentY+height <= r.y+r.height)
                    contentY = r.y+r.height-height;
            }

            TextEdit {
                id: _textarea
                width: _flkr.width

                font.pointSize: _textarearect.height * 0.1
                wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere
                focus: true
                //onVisibleChanged: if(visible) _textarea.forceActiveFocus()
                onCursorRectangleChanged: _flkr.ensureVisible(cursorRectangle)
                onEditingFinished: {
                    console.log("edit finished")
                }
            }

        }
    }

    // Button "COPY"
    Button{
        id: _copyBtn
        text: qsTr("COPY")

        anchors{
            left: _copypasteelement.left
            bottom: _copypasteelement.bottom
            top: _textarearect.bottom
            leftMargin: _copypasteelement.width * 0.05
            topMargin: _copypasteelement.height * 0.025
            bottomMargin: _copypasteelement.height * 0.05
        }

        width: _copypasteelement.width / 3

        contentItem: Text {
            text: _copyBtn.text
            color: "lightpink"
            font.pointSize: _copyBtn.height * 0.5
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle{
            color: "red"
            border.color: "lightpink"
            border.width: 3
            radius: 10
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                horizontalOffset: 3
                verticalOffset: 3
                radius: 3
                color: "gray"
            }
        } 
    }

    // Button "PASTE"
    Button{
        id: _pasteBtn
        text: qsTr("PASTE")

        anchors{
            right: _copypasteelement.right
            bottom: _copypasteelement.bottom
            top: _textarearect.bottom
            rightMargin: _copypasteelement.width * 0.05
            topMargin: _copypasteelement.height * 0.025
            bottomMargin: _copypasteelement.height * 0.05
        }

        width: _copypasteelement.width / 3

        contentItem: Text {
            text: _pasteBtn.text
            color: "palegreen"
            font.pointSize: _pasteBtn.height * 0.5
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle{
            color: "mediumseagreen"
            border.color: "palegreen"
            border.width: 3
            radius: 10
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                horizontalOffset: 3
                verticalOffset: 3
                radius: 3
                color: "gray"
            }
        }
    }

    // Square with number
    Rectangle{
        id: _elementRect

        anchors{
            bottom: _copypasteelement.bottom
            top: _textarearect.bottom
            topMargin: _copypasteelement.height * 0.025
            bottomMargin: _copypasteelement.height * 0.05
            horizontalCenter: _copypasteelement.horizontalCenter
        }

        width: _copypasteelement.width / 5
        color: "lightblue"

        Text {
            id: _elementNum
            text: qsTr("1")
            anchors.centerIn: _elementRect
            font{
                bold: true
                pointSize: _elementRect.height * 0.8
            }
            color: "lightcyan"
        }
    }
}
