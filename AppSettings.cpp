/*****************************************************************************
 * Alpine Terrain Renderer
 * Copyright (C) 2023 Gerald Kimmersdorfer
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

#include <QSettings>

#include "AppSettings.h"

AppSettings::AppSettings(QObject* parent)
    : QObject(parent)
{
#ifdef ALP_ENABLE_TRACK_OBJECT_LIFECYCLE
    qDebug() << "AppSettings()";
#endif
    /* UNCOMMENT TO ENABLE LOCAL SETTINGS SAVE
    QSettings settings;
    m_datetime = settings.value("app/datetime", QDateTime::currentDateTime()).toDateTime();
    m_gl_sundir_date_link = settings.value("app/gl_sundir_date_link", true).toBool();
    m_render_quality = settings.value("app/render_quality", 0.5f).toFloat();*/
    load_from_url();
}

AppSettings::~AppSettings() {
    /* UNCOMMENT TO ENABLE LOCAL SETTINGS SAVE
    QSettings settings;
    settings.setValue("app/datetime", m_datetime);
    settings.setValue("app/gl_sundir_date_link", m_gl_sundir_date_link);
    settings.setValue("app/render_quality", m_render_quality);
    settings.sync();
*/
#ifdef ALP_ENABLE_TRACK_OBJECT_LIFECYCLE
    qDebug() << "~AppSettings()";
#endif
}

void AppSettings::load_from_url() {

}

void AppSettings::set_datetime(const QDateTime& new_datetime) {
}

void AppSettings::set_gl_sundir_date_link(bool new_value) {
    if (m_gl_sundir_date_link != new_value) {
        m_gl_sundir_date_link = new_value;
        emit gl_sundir_date_link_changed(m_gl_sundir_date_link);
    }
}

void AppSettings::set_render_quality(float new_value) {
}
