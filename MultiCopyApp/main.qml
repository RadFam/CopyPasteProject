import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root

    visible: true
    width: 360
    height: 1000
    title: qsTr("COPY/PASTE")

    WorkBoard{
        anchors.fill: parent
    }
}
