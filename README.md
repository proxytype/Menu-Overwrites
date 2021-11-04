# Menu-Overwrites
Overwrite menus options in GUI Applications (Win32). <br> <br>
![alt text](https://raw.githubusercontent.com/proxytype/Menu-Overwrites/main/menu-overwrite.gif)

Finding window handle using EnumWindows(...) to obtain the menu,
change menu items and rerender the bar using DrawMenuBar(...).

Functions:
- EnumWindows(...)
- GetMenu(...)
- GetMenuItemCount(...)
- GetMenuItemID(...)
- EnableMenuItem(...)
- DeleteMenu(...)
- DrawMenuBar(...)
