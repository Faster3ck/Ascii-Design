PROJECT(ascii-design)

cmake_minimum_required(VERSION 2.4)
  
SET(GUI "ascii-design")  

ADD_DEFINITIONS( ${OPTIMIZATION_FLAGS} )
  
SET(ascii-design_UIS  
    ui/mainwindow.ui
    ui/optionsman.ui
    ui/infodialog.ui
)  
  
SET(ascii-design_SRCS  
    src/mainwindowimpl.cpp
    src/main.cpp
    src/figletmanager.cpp
    src/figletfonts.cpp
    src/options.cpp
    src/dialogoptionsimpl.cpp
    src/dialoginfoimpl.cpp
)  
  
SET(ascii-design_MOC_HDRS  
    src/mainwindowimpl.h
    src/figletmanager.h
    src/figletfonts.h
    src/options.h
    src/dialogoptionsimpl.h
    src/dialoginfoimpl.h
)  
  
SET(ascii-design_RESOURCES  
    res.qrc
)  

SET(ascii-design_RCS
    winicon.rc
)

FIND_PACKAGE(Qt4 REQUIRED)  
INCLUDE(${QT_USE_FILE})  
QT4_WRAP_UI(ascii-design_UIS_H ${ascii-design_UIS})  
QT4_WRAP_CPP(ascii-design_MOC_SRCS ${ascii-design_MOC_HDRS})  
QT4_ADD_RESOURCES(ascii-design_RESOURCES ${ascii-design_RESOURCES})  

ADD_DEFINITIONS(
	-Wall 
	-DQT_NO_DEBUG
	${QT_DEFINITIONS}
)
  
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})  

if(MINGW)
  # resource compilation for mingw
    ADD_CUSTOM_COMMAND(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/winicon.o
    COMMAND windres.exe -I${CMAKE_CURRENT_SOURCE_DIR}
    -i${CMAKE_CURRENT_SOURCE_DIR}/winicon.rc
    -o ${CMAKE_CURRENT_BINARY_DIR}/winicon.o)
    SET(ascii-design_SRCS ${ascii-design_SRCS} ${CMAKE_CURRENT_BINARY_DIR}/winicon.o)
else(MINGW)
    SET(ascii-design_SRCS ${ascii-design_SRCS} winicon.rc)
endif(MINGW)
  
ADD_EXECUTABLE(${GUI}  
    ${ascii-design_SRCS}  
    ${ascii-design_UIS_H}  
    ${ascii-design_MOC_SRCS}  
    ${ascii-design_RESOURCES}  
    ${ascii-design_RCS} 
)  

IF( MINGW )
    SET_TARGET_PROPERTIES( ${GUI} PROPERTIES LINK_FLAGS "-mwindows" )
ENDIF( MINGW )
  
TARGET_LINK_LIBRARIES(${GUI} ${QT_LIBRARIES}) 

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/ascii-design DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES icon/ascii-design.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES pics/ascii-design.png DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
