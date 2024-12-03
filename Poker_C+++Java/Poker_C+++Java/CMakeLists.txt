# CMakeList.txt : projet CMake pour Poker_C+++Java, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Poker_C+++Java "Poker_C+++Java.cpp" "Poker_C+++Java.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Poker_C+++Java PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
