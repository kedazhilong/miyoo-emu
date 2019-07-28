/***************************************************************************
 *   Copyright (C) 2009 by Sindre Aamås                                    *
 *   sinamas@users.sourceforge.net                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "vfilterinfo.h"

static VideoLink * createNone() { return 0; }

template<class T>
static VideoLink * createT() { return new T; }

#define VFINFO(handle, Type) { handle, Type::out_width, Type::out_height, createT<Type> }

static VfilterInfo const vfinfos[] = {
	{ "None", VfilterInfo::in_width, VfilterInfo::in_height, createNone },
};

std::size_t VfilterInfo::numVfilters() {
	return sizeof vfinfos / sizeof vfinfos[0];
}

VfilterInfo const & VfilterInfo::get(std::size_t n) {
	return vfinfos[n];
}
