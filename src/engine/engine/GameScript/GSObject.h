#pragma once
namespace Net
{
    namespace Repl
    {
        class IGameObject
        {
        };
    }
}

class CSerializableObject{};

class __declspec(align(4)) CGSObject : CSerializableObject, Net::Repl::IGameObject
{
  /*
  IGSObject *m_IGSO;
  CGSObject *m_pPrev;
  CGSObject *m_pNext;
  CGSObject *m_Owner;
  unsigned int m_GSOFlags;
  CLevel *m_pLevel;
  int m_ID;
  ttl::string_base<char> m_Name;
  ttl::string_base<char> m_PresetsData;
  int m_CachedPresetsId;
  safemultifastlist<TimeHandler *,256,22> m_TimeHandlers;
  Net::Repl::CObject *m_NetObject;
  unsigned __int8 m_iActiveFlags;
  */
};
