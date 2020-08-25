import QtQuick 2.6
import CopyPaste 1.0

ListView {
    id: root

    //model: WorkModel {}
    interactive: false

    delegate: CopyPasteElement{
        id: _baseElement

        width: root.width
        height: root.height / 5

        //internalText.text: number
    }

    CopyPasteController_qml{
        id: _cpController;
    }

    Component.onCompleted: {
        root.model = _cpController.getModel();
    }
}
