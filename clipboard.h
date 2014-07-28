#ifndef CLIPBOARD_H
#define CLIPBOARD_H

class ClipBoard
{
public:
    ClipBoard(){}
    ~ClipBoard(){}
    char* GetText();
    void SetText(const char*);
    void Clear();
private:
    char* text;
};

#endif // CLIPBOARD_H
