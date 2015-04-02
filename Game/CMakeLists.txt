project("Game")
include_directories(include)
file(GLOB GAME_SRC
    "src/*.cpp"
)

file(GLOB_RECURSE GAME_INC 
	"include/*.h")

add_library(Game ${GAME_SRC} ${GAME_INC})

if(SDL2_FOUND)
  include_directories(${SDL2_INCLUDE_DIR})
  target_link_libraries(Game ${SDL_LIBRARIES})
endif(SDL2_FOUND)




