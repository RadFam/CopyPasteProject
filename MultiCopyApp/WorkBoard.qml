import QtQuick 2.6
import QtQuick.Controls 2.0
import CopyPaste 1.0

ListView {
    id: root

    model: CopyPasteModel_qml {
        id: _modelObject
    }

    /*
    delegate: SimpleDelegate {
    text: root.model.display
    }
    */

    delegate: CopyPasteElement{
        id: _baseElement

        width: root.width
        height: root.height / 5

        internalEdit.text: model.display
        internalEdit.onTextChanged: model.edit = internalEdit.text

        internalText.text: index+1

        internalPaste.onPressed: {
            backgrPaste.state = "PRESSED"
        }
        internalPaste.onReleased: {
            backgrPaste.state = "RELEASED"
            _modelObject.getClipboardData(index)
        }

        internalCopy.onPressed: {
            backgrCopy.state = "PRESSED"
        }
        internalCopy.onReleased: {
            backgrCopy.state = "RELEASED"
            _modelObject.setClipboardData(index)
        }

        //internalCopy.onClicked: _modelObject.setClipboardData(index)
        //internalPaste.onClicked: _modelObject.getClipboardData(index)
    }


    CopyPasteController_qml{
        id: _cpController;
    }

    /*Component.onCompleted: {
        //root.model = _cpController.getModel();
        root.model = CopyPasteModel_qml
    }*/

    //onClipChanged: _baseElement.internalEdit.text = clipboardString;

    Shortcut{
        sequence: "Ctrl+1"
        onActivated: _modelObject.getClipboardData(0)
    }
    Shortcut{
        sequence: "Ctrl+2"
        onActivated: _modelObject.getClipboardData(1)
    }
    Shortcut{
        sequence: "Ctrl+3"
        onActivated: _modelObject.getClipboardData(2)
    }
    Shortcut{
        sequence: "Ctrl+4"
        onActivated: _modelObject.getClipboardData(3)
    }
    Shortcut{
        sequence: "Ctrl+5"
        onActivated: _modelObject.getClipboardData(4)
    }
    Shortcut{
        sequence: "Alt+1"
        onActivated: _modelObject.setClipboardData(0)
    }
    Shortcut{
        sequence: "Alt+2"
        onActivated: _modelObject.setClipboardData(1)
    }
    Shortcut{
        sequence: "Alt+3"
        onActivated: _modelObject.setClipboardData(2)
    }
    Shortcut{
        sequence: "Alt+4"
        onActivated: _modelObject.setClipboardData(3)
    }
    Shortcut{
        sequence: "Alt+5"
        onActivated: _modelObject.setClipboardData(4)
    }

}
