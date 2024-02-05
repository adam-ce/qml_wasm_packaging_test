#############################################################################
# Alpine Terrain Renderer
# Copyright (C) 2023 Adam Celarek <family name at cg tuwien ac at>
# Copyright (C) 2023 Gerald Kimmersdorfer
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#############################################################################

project(qml_wasm_packaging_test LANGUAGES CXX)
cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL Network Quick QuickControls2 LinguistTools Svg Charts)

qt_add_executable(alpineapp
    main.cpp
    RenderThreadNotifier.h RenderThreadNotifier.cpp
    HotReloader.h HotReloader.cpp
    AppSettings.h AppSettings.cpp
)

qt_add_qml_module(alpineapp
    URI app
    VERSION 1.0
    RESOURCE_PREFIX /qt/qml
    QML_FILES
        main_loader.qml
        Main.qml
        About.qml
        SearchBox.qml
        SearchResults.qml
        Settings.qml
        Coordinates.qml
        StatsWindow.qml
        GeneralSettings.qml
        GlSettings.qml
        FloatingActionButtonGroup.qml
        components/LabledSlider.qml
        components/LabledRangeSlider.qml
        components/ColorPicker.qml
        components/PageDrawer.qml
        components/CheckGroup.qml
        components/SettingsPanel.qml
        components/SettingsTitle.qml
        components/DrawerButton.qml
        components/DrawerSeparator.qml
        components/DrawerSpacer.qml
        components/VectorEditor.qml
        components/DatePicker.qml
        components/DateMonthTablePicker.qml
        components/FloatingActionButton.qml
    RESOURCES
        icons/mascot.jpg
        icons/menu.svg
        icons/peak.svg
        icons/search.svg
        icons/favicon.ico
        icons/icon.svg
        icons/material/monitoring.svg
        icons/material/3d_rotation.svg
        icons/material/map.svg
        icons/material/pin_drop.svg
        icons/material/settings.svg
        icons/material/info.svg
        icons/material/format_paint.svg
        icons/material/location_searching.svg
        icons/material/my_location.svg
        icons/material/navigation.svg
        icons/material/navigation_offset.svg
        icons/material/chevron_left.svg
        icons/material/visibility_off.svg
        icons/presets/basic.png
        icons/presets/shaded.png
        icons/presets/snow.png

)

qt_add_translations(alpineapp TS_FILES
    i18n/de.ts
    i18n/en.ts
)

set_target_properties(alpineapp PROPERTIES
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
)
target_link_libraries(alpineapp PUBLIC Qt::Quick Qt::QuickControls2 Qt::Charts)
if (ALP_ENABLE_APP_SHUTDOWN_AFTER_60S)
    target_compile_definitions(alpineapp PUBLIC "ALP_APP_SHUTDOWN_AFTER_60S")
endif()

if (ANDROID OR EMSCRIPTEN)
    target_compile_definitions(alpineapp PUBLIC ALP_QML_SOURCE_DIR="qrc:///qt/qml/app/")
else()
    target_compile_definitions(alpineapp PUBLIC ALP_QML_SOURCE_DIR="file:/${CMAKE_CURRENT_SOURCE_DIR}/")
endif()


if (EMSCRIPTEN)
    set(ALP_INSTALL_FILES
        "$<TARGET_FILE_DIR:alpineapp>/alpineapp.js"
        "$<TARGET_FILE_DIR:alpineapp>/alpineapp.wasm"
        "$<TARGET_FILE_DIR:alpineapp>/alpineapp.html"
        "$<TARGET_FILE_DIR:alpineapp>/qtloader.js"
    )

    if (ALP_ENABLE_THREADING)
        list(APPEND ALP_INSTALL_FILES "$<TARGET_FILE_DIR:alpineapp>/alpineapp.worker.js")
    endif()
    install(FILES ${ALP_INSTALL_FILES} DESTINATION ${ALP_WWW_INSTALL_DIR})
endif()
