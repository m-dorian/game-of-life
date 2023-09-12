VPATH	=	game/:cell/
CXX	=	g++
CXX_FLAGS	=	-Icell/	-Igame/
SOURCE	=	main.cpp	game/game.cpp	cell/cell.cpp
LINKER_FLAGS	=	-lSDL2
EXECUTABLE_NAME	=	game-of-life
all	:	${SOURCE}
	${CXX}	${SOURCE}	${CXX_FLAGS}	${LINKER_FLAGS}	-o	${EXECUTABLE_NAME}