/*************************************************************************
 * OpenMMT - Open Multi-Monitor Taskbar
 * Copyright (C) 2010-2014 Genscripts
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
 *
 */
#ifndef OPENMMT_TEMPLATE_CLASSES_SMART_VECTOR_LIST_H
#define OPENMMT_TEMPLATE_CLASSES_SMART_VECTOR_LIST_H
#pragma once

/**
 * Template class for managing smart pointers in a vector. 
 *
 * Example:
 *  Objects being managed: Monitor
 *  Class managing the objects: MonitorManager
 *
 *  Declaration: VectorList<Monitor, MonitorManager>
 */
template <typename Object, typename FriendClass>
class SmartVectorList
{
  friend FriendClass;   /**< Friend! ❤ヽ(ﾟ∀ﾟ)ノ❤ */

private:
  typedef typename std::tr1::shared_ptr<Object> ObjectPtr;
  typedef typename std::vector<ObjectPtr>    ObjectVectorPtr;
  typedef typename ObjectVectorPtr::iterator ObjectIterator;

   ObjectVectorPtr vector_;


  inline void AddObject(ObjectPtr& Obj)
  {
    vector_.push_back(Obj);
  }

  void RemoveObject(ObjectPtr Obj)
  {
    for (ObjectIterator it = vector_.begin(); it != vector_.end(); ++it) {
      if (it->get()->GetId() == Obj->GetId()) {
        it = vector_.erase(it);
        break;
      }
    }
  }

  void ClearObjects()
  {
    vector_.clear();
  }

public:
  SmartVectorList()
  {
  }
  ~SmartVectorList()
  {
    vector_.clear();
  }
};


#endif // OPENMMT_TEMPLATE_CLASSES_SMART_VECTOR_LIST_H

// EOF
