# Menu-Overwrites
Playing with Win32 applications menus.


# Payload
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

# Payload 2
Add new features to menus in GUI Applications (Win32). <br> <br>
![alt text](https://raw.githubusercontent.com/proxytype/Menu-Overwrites/main/menu-overwrite2.gif)

Finding window handle using EnumWindows(...) to obtain the menu,
add new features and register to window procedure using SetWindowLongPtr(...).

Functions:
- EnumWindows(...)
- GetMenu(...)
- CreatePopupMenu(...)
- AppendMenu(...)
- SetWindowLongPtr(...)
- DrawMenuBar(...)
