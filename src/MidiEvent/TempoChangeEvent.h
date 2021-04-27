/*
 * MidiEditor
 * Copyright (C) 2010  Markus Schwenk
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
 */

#ifndef TEMPOCHANGEEVENT_H_
#define TEMPOCHANGEEVENT_H_

#include "MidiEvent.h"

class TempoChangeEvent : public MidiEvent {

public:
    TempoChangeEvent(int channel, int value, MidiTrack* track);
    TempoChangeEvent(TempoChangeEvent& other);

    int beatsPerQuarter();
    double msPerTick();

    virtual ProtocolEntry* copy();
    virtual void reloadState(ProtocolEntry* entry);
    int line();
    QByteArray save();

    QString typeString();

    void setBeats(int beats);

private:
    int _beats;
};

#endif
