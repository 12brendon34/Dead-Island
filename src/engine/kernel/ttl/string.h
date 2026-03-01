#pragma once
#include <cstdlib>
#include <cstring>

namespace ttl {
    template<typename CharT>
    class string_base {
    public:
        CharT *m_Buffer;
        unsigned int m_Size;
        unsigned int m_Capacity;

        CharT *c_str() {
            CharT *result = m_Buffer;
            if (!result)
                return 0;
            return result;
        }

        string_base(const CharT *str) {
            unsigned int v2 = (unsigned int)strlen(str);
            this->m_Capacity = v2;
            this->m_Size = v2;
            if (v2) {
                char *v3 = (char *)malloc(v2 + 1);
                size_t m_Size = this->m_Size;  // local copy - matches [ebp-8] stack var
                this->m_Buffer = v3;
                memcpy(v3, str, m_Size);
                this->m_Buffer[this->m_Size] = 0;
            } else {
                this->m_Buffer = 0;
            }
        }

        string_base(const string_base &src) {
            unsigned int mSize = src.m_Size;
            if (mSize) {
                char *buf = (char *)malloc(mSize + 1);
                this->m_Buffer = buf;
                this->m_Size = mSize;
                this->m_Capacity = mSize;
                memcpy(buf, src.m_Buffer, this->m_Size + 1);
            } else {
                this->m_Buffer = 0;
                this->m_Capacity = 0;
                this->m_Size = 0;
            }
        }

        ~string_base() {
            if (m_Buffer) {
                free(m_Buffer);
                m_Buffer = 0;
            }
        }
    };
}