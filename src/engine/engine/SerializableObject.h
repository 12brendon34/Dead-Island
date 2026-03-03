#pragma once
#include "GameObject.h"

class __cppobj __declspec(align(2)) CSerializableObject : CGameObject
{
  bool m_bIsSavedByGame;
  bool m_EnableParallelLoad;
  bool m_bLoaded;
};
