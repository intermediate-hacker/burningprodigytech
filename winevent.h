#ifndef WINEVENT_H
#define WINEVENT_H

#include <windows.h>

namespace Nex
{

class WinEvent
{
    public:
        WinEvent() { CmdPtr = NULL; }
        WinEvent(int id, void (*func)(WinEvent*)) {Bind(id,func);}
        virtual ~WinEvent() {}
    public:
        void Bind(int id, void (*func)(WinEvent*)) { MenuID(id); CmdPtr = func; }
        void Bind(void (*func) (WinEvent*)) { CmdPtr = func; }
        void Command(void) { if (CmdPtr!=NULL) (*CmdPtr)(this); }
        virtual void Create() {}
        //(*void)(WinEvent*) GetCmd(void) { return CmdPtr; } FixMe
    public:
        void MenuID(int v) { _hMenu = (HMENU) v; }
        int MenuID(void) { return (int)_hMenu; }
    protected:
        HMENU _hMenu;
        void (*CmdPtr)(WinEvent*);

};

}
#endif // WINEVENT_H

