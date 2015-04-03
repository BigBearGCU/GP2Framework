project("OpenGLRenderer")

include_directories(include ${GAME_INC_PATH})

message("Game Include in Renderer ${GAME_INC_PATH}")

file(GLOB_RECURSE OPENGL_RENDERER_INC
	"include/*.h")

file(GLOB OPENGL_RENDERER_SRC
    "src/*.cpp"
)

add_library(OpenGLRenderer SHARED ${OPENGL_RENDERER_SRC} ${OPENGL_RENDERER_INC})
target_link_libraries(OpenGLRenderer${Game})
