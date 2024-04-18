import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
Window {
    id:page
    width: 600
    height: 600
    visible: true
    title: qsTr("Group 5 theatre")

    //signal
    signal changeRequest(string msg)

     //slot
    function changeTitle(text){
        movieTitle = text
     }
    property string movieTitle: "test"

    Loader {
        id: pageLoader
        anchors.fill: parent
        source: "home.qml"
    }
}
