/*****************************************************************************
 * Alpine Terrain Renderer
 * Copyright (C) 2023 Adam Celarek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Universal

Rectangle {
    property SearchResults search_results

    id: search
    color: "#AAFFFFFF"
    radius: 100
    Layout.fillWidth: true
    height: 48
    TextField {
        anchors {
            fill: parent
            leftMargin: 6
            rightMargin: 6
        }
        id: search_input
        placeholderText: "City or Mountain.."
        background: Rectangle{ color: "#00FFFFFF" }
        verticalAlignment: TextInput.AlignVCenter
        visible: parent.visible
        font.pointSize: 24
//                    font.weight: Font.ExtraBold
        font.family: "Source Sans 3"
    }
    Button {
        id: search_button
        anchors {
            top: search_input.top
            bottom: search_input.bottom
            right: search_input.right
        }

        text: ""
        icon.source: "icons/search.svg"
        background: Rectangle { color: "#00FFFFFF" }
        onClicked: {
            search_input.accepted()
        }
    }

}
