import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
Item {
    Rectangle
    {
        id:movieSelectorBackground
        width :Window.width
        height: Window.height
        color : "#94d2e3"
    }

    Image{
        id:pageTitle
        x:0
        width: movieSelectorBackground.width
        source: "Movie Selector text.png"

    }

    Image {
        id: exitButton2
        property int size: 80
        x: movieSelectorBackground.width - size
        y: movieSelectorBackground.height - size
        width: size
        height: size
        source: "exitButton.png"

        MouseArea{
            id:exitArea2
            anchors.fill: parent // makes the area the same as the parent (exitButton)
            onClicked: {
                Qt.quit()
            }
        }
    }

    Image {
        id: backButton
        property int size: 80
        source: "back button.png"
        x:0
        y:movieSelectorBackground.height-size
        width: size
        height: size

        MouseArea{
            id:backArea
            anchors.fill: parent
            onClicked: {
                pageLoader.source = "home.qml"
            }
    }
    }


     TextField{
        id:textField
        anchors.centerIn: parent
        placeholderText:"enter a number"
        width: 200
        font.pixelSize: 20
        }

     Image {
         id:clickeMeButton
         x:movieSelectorBackground.width/2 - 150
         y:textField.y + 50
         width: 300
         height: 150
         source: "click-me-button-flat.png"

         MouseArea{
             anchors.fill: parent
             onClicked: {
                 page.changeRequest(textField.text)
             }
         }
        }

     Image {
        id: ticket
        x:movieSelectorBackground.width/2 - 150
        y:textField.y - 150
        width: 300
        height: 150
        source: "admisson ticket.jpg"
        Text{
            text: movieTitle
            anchors.centerIn: parent
            font.pixelSize: 20
        }

     }
}

