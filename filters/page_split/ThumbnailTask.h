/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C) 2007-2008  Joseph Artsimovich <joseph_a@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PAGE_SPLIT_THUMBNAILTASK_H_
#define PAGE_SPLIT_THUMBNAILTASK_H_

#include "NonCopyable.h"
#include "RefCountable.h"
#include "IntrusivePtr.h"
#include <memory>

class QSizeF;
class PageInfo;
class ImageTransformation;
class ThumbnailPixmapCache;
class QGraphicsItem;

namespace deskew
{
	class ThumbnailTask;
}

namespace page_split
{

class Settings;

class ThumbnailTask : public RefCountable
{
	DECLARE_NON_COPYABLE(ThumbnailTask)
public:
	ThumbnailTask(
		IntrusivePtr<Settings> const& settings,
		IntrusivePtr<deskew::ThumbnailTask> const& next_task);
	
	virtual ~ThumbnailTask();
	
	std::auto_ptr<QGraphicsItem> process(
		ThumbnailPixmapCache& thumbnail_cache, QSizeF const& max_size,
		PageInfo const& page_info, ImageTransformation const& xform);
private:
	IntrusivePtr<deskew::ThumbnailTask> m_ptrNextTask;
	IntrusivePtr<Settings> m_ptrSettings;
};

} // namespace page_split

#endif
