// This file is part of Dust Racing (DustRAC).
// Copyright (C) 2011 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#ifndef TRACKTILE_HPP
#define TRACKTILE_HPP

#include "../common/tracktilebase.hpp"

#include "MiniCore/Core/MCSurface"

class TrackData;

//! The track tile used in the game.
class TrackTile : public TrackTileBase
{
public:

    //! Tile width in pixels
    static const unsigned int TILE_W = 256;

    //! Tile height in pixels
    static const unsigned int TILE_H = 256;

    //! Constructor.
    //! See TrackTileBase.
    TrackTile(TrackData * trackData, QPointF location, QPoint matrixLocation,
        const QString & type = "clear");

    //! Destructor
    virtual ~TrackTile();

    //! Set the orientation in XY-plane in degrees when loading
    //! a track.
    void setRotation(int rotation);

    //! Set the renderable surface object corresponding
    //! to the track tile. TrackTile won't take the
    //! ownership, because many TrackTile's might use
    //! the same surface object.
    void setSurface(MCSurface * surface);

    //! Get the corresponding surface.
    MCSurface * surface() const;

    //! Get the orientation in XY-plane in degrees.
    int rotation() const;

private:

    int m_rotation;
    MCSurface * m_surface;
};

#endif // TRACKTILE_HPP