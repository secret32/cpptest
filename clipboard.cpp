#include "clipboard.h"
#ifdef WIN32
#include <windows.h>
#endif // WIN32
#include <iostream>

char* ClipBoard::GetText()
{
    char* result = NULL;
#ifdef WIN32
    HWND hwnd = NULL;
    if (OpenClipboard(hwnd))
    {
        UINT format = 0;
        while ((format = EnumClipboardFormats(format)) > 0)
        {
            if (format == CF_UNICODETEXT)
            {
                HGLOBAL hMem = GetClipboardData(format);
                if (hMem)
                {
                    std::cout << "format=" << format << "\tclipboard size = " << GlobalSize(hMem) << std::endl;
                    char* str = (char*)GlobalLock(hMem);
                    if (str)
                    {
                        result = str;
                        std::cout << result << std::endl;
                    }
                    GlobalUnlock(hMem);
                }
            }
        }
        CloseClipboard();
    }
#endif // WIN32
    return result;
}

void ClipBoard::Clear()
{
#ifdef WIN32
    if (OpenClipboard(NULL))
    {
        EmptyClipboard();
        CloseClipboard();
    }
#endif
}

void ClipBoard::SetText(const char* text)
{

}
