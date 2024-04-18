import QtQuick 2.15

Item {

    Image {
        id: background
        x: 0
        y: 0
        width: Window.width
        height: Window.height
        source: "Group 5 Image2.jpg"
    }
    Image {
        property int size: 80 //Variable for size.
        id: exitButton
        x:Window.width - size
        width: size
        height : size
        source: "exitButton.png"

        MouseArea{
            id:exitArea
           anchors.fill: parent // makes the area the same as the parent (exitButton)
            onClicked: {
                Qt.quit()
            }
        }


    }


    Image {
        property int length: 200
        property int margin: 50
        id: enterButton
        x:(Window.width/2)-length/2
        y:Window.height - margin -(length/2)
        width: length
        height : length/2
        source: "EnterButton.jpg"

        MouseArea{
            id:enterArea
           anchors.fill: parent //makes same size as parent.
            onClicked: {
                pageLoader.source = "movie-selector.qml"
            }
        }
    }
}
