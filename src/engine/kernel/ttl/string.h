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

		/*
        CharT *c_str() {
            CharT *result = m_Buffer;
            if (!result)
                return 0;
            return result;
        }
		*/
		
		// FUNCTION: DEADISLANDGAME 0x00401E00
        string_base(const CharT *str) {
			/*
			unsigned int v2 = 0;
			while (str[v2]){
				if ( !str[v2 + 1] )
				{
					++v2;
					break;
				}
				if ( !str[v2 + 2] )
				{
					v2 += 2;
					break;
				}
				if ( !str[v2 + 3] )
				{
					v2 += 3;
					break;
				}
				if ( !str[v2 + 4] )
				{
					v2 += 4;
					break;
				}
				v2 += 5;
				if ( v2 == -1 )
					break;
			}
			this->m_Capacity = v2;
			this->m_Size = v2;

			if (v2){
				char* v3 = (char *)_malloc(v2 + 1);
				m_Size = this->m_Size;
				this->m_Buffer = v3;
				memcpy(v3, str, m_Size);
				this->m_Buffer[this->m_Size] = 0;
			}
			else{
				this->m_Buffer = 0;
			}
			*/

            unsigned int v2 = (unsigned int)strlen(str);
            this->m_Capacity = v2;
            this->m_Size = v2;
            if (v2) {
                char *v3 = (char *)malloc(v2 + 1);
                size_t m_Size = this->m_Size;
                this->m_Buffer = v3;
                memcpy(v3, str, m_Size);
                this->m_Buffer[this->m_Size] = 0;
            } else {
                this->m_Buffer = 0;
            }
        }

        ~string_base() {
            if (m_Buffer) {
                free(m_Buffer);
                //m_Buffer = 0;
            }
        }
    };
}