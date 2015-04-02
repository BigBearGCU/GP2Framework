project("MyGame")

include_directories(include)
file(GLOB MYGAME_SRC
    "src/*.cpp"
)

file(GLOB_RECURSE MYGAME_INC 
	"include/*.h")

add_executable(MyGame ${MYGAME_SRC} ${MYGAME_INC})

if(SDL2_FOUND)
  include_directories(${SDL2_INCLUDE_DIR})
  target_link_libraries(MyGame ${SDL_LIBRARIES})
endif(SDL2_FOUND)

target_link_libraries(MyGame ${Game})
