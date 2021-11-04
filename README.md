# Menu-Overwrites
Overwrite menus options in GUI Applications (Win32). <br> <br>
![alt text](https://raw.githubusercontent.com/proxytype/Menu-Overwrites/main/97.png)

Finding application handle using EnumWindows(...), using the handle to find the application menu,
change menu items and rerender the bar using DrawMenuBar(...).

Functions:
- EnumWindows(...)
- GetMenu(...)
- GetMenuItemCount(...)
- GetMenuItemID(...)
- EnableMenuItem(...)
- DeleteMenu(...)
- DrawMenuBar(...)
