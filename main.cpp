 //
// Created by derek on 27/03/2026.
//

#include "Menu.h"

 int main() {

 try
 {
  std::unique_ptr<Menu> menu = std::make_unique<Menu>();
  menu->actionsMainMenu();
 }catch (...)
 {
   std::cout << "Se debe reiniciar el programa\n";
 }

 return 0;
}
